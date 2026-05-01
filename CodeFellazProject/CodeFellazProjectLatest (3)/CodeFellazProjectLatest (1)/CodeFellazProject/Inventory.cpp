#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

//Method For A adding Product in products map
bool Inventory::addProduct(shared_ptr<Product> product){
    lock_guard<mutex> lock(inventoryMutex); //Lock mutex To Ensure Thread Safe Read Access
    int productID = product -> getProductID();

    if(products.count(productID)){ //Checks If The Product With That productID Exists
        return false;
    }
    products[productID] = product;
    return true;
}
//Method For Removing Product in products map using it productID
bool Inventory::removeProduct(int productID){
    lock_guard<mutex> lock(inventoryMutex);//Lock mutex To Ensure Thread Safe Read Access
    if(products.count(productID)){//Checks If The Product With That productID Exists inside map container
        products.erase(productID);  //Removing That Product If Exist
        return true;
    }
    return false; //If Entered The Product that do not exist inside map
}

bool Inventory::searchProduct(int ProductID){
    lock_guard<mutex> lock(inventoryMutex); //Lock mutex To Ensure Thread Safe Read Access

    //find_if Scans The Map And Returns An Iterator To The First Product
    //Whose ID matches ProductID
    auto it = find_if(products.begin(), products.end(),
        [ProductID](const auto& pair){
            return pair.second->getProductID() == ProductID;
        });

    if(it != products.end()){
        cout << "Product found!\n";
        cout << "Name: " << it->second->getName()
             << " | Quantity: " << it->second->getQuantity()
             << " | Price: R" << it->second->getPrice() << endl;
        return true;
    }
    cout << "Product not found!" << endl;
    return false;
}

void Inventory::displayAllProduct(){
    DisplayTableHeader();
    if(!products.empty()){
        for(auto product : products){ //iterating through map for displaying all product existing in map
            product.second -> displayProduct();
        }
    }else{
        cout << "| " << setw(10) << left << "N/A"
         << "| " << setw(20) << left << "N/A"
         << "| " << setw(17) << left << "N/A"
         << "| " << setw(13) << left << "N/A"
         << "| " << setw(13) << left << "N/A"
         << "|" << endl;
    }
}

void Inventory::sortByPrice(){
    //Method to sort products by price
    cout << "Products Sorted by Price:"<<endl;
    DisplayTableHeader();
    lock_guard<mutex> lock(inventoryMutex);
    vector<pair<int,shared_ptr<Product>>> sortedByPrice;
    for(auto& item: products){
        sortedByPrice.push_back(item);
    }

    sort(sortedByPrice.begin(), sortedByPrice.end(),[](const auto& a, const auto& b) {
      return a.second->calculateFinalPrice() < b.second->calculateFinalPrice();
    });

    for (const auto& sortedItems : sortedByPrice) {
        sortedItems.second->displayProduct();
    }
}

void Inventory::sortByQuantity(){
     //Method to sort products by price
    cout << "Products Sorted by quantity:"<<endl;
    DisplayTableHeader();
    lock_guard<mutex> lock(inventoryMutex);
    vector<pair<int,shared_ptr<Product>>> sortedByQuantity;
    for(auto& item: products){
        sortedByQuantity.push_back(item);
    }

    sort(sortedByQuantity.begin(), sortedByQuantity.end(),[](const auto& a, const auto& b) { // a repres
      return a.second->getQuantity() < b.second->getQuantity();
    });

    for (const auto& sortedItems : sortedByQuantity) {
        sortedItems.second->displayProduct();
    }
}

bool Inventory::processOrder(Order& order) {
    auto start = chrono::high_resolution_clock::now();
    lock_guard<mutex> lock(inventoryMutex);

    //Find product
    auto it = products.find(order.getProduct_ID());

    //Check if Product Exists First
    if (it == products.end()) {
        order.setStatus("Failed");

        processedOrders.push_back(make_unique<Order>(order));

        cout << "[Thread: " << this_thread::get_id() << "] "
             << "\tORDER FAILED | Product NOT FOUND"
             << " | Requested: " << order.getQuantityRequested()
             << endl << endl;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double>(end - start);
        cout << "\tTime taken: " << duration.count() << " ms\n";
        return false;
    }
    shared_ptr<Product>& product = it->second;

    cout << "[Thread: " << this_thread::get_id() << "] Processing Order #"
         << order.getOrderId()
         << " | Product ID: " << order.getProduct_ID()
         << " | Requested: " << order.getQuantityRequested()
         << endl;

    // Handle failed order
    if (product->getQuantity() < order.getQuantityRequested()) {
        order.setStatus("Failed");

        processedOrders.push_back(make_unique<Order>(order));

        cout << "\t    ORDER FAILED       "
             << " | Product Name: " << product->getName()
             << "    | In Stock: " << product->getQuantity()
             << endl << endl;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double>(end - start);
        cout << "\tTime taken: " << duration.count() << " ms\n";
        return false;
    }

    //Handle passed order
    product->setQuantity(
        product->getQuantity() - order.getQuantityRequested()
    );

    order.setStatus("Successful");

    processedOrders.push_back(make_unique<Order>(order));

    cout << "\t    ORDER SUCCESSFUL   "
         << " | Product Name: " << product->getName()
         << "   | Remaining Stock: " << product->getQuantity()
         << endl << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start);
    cout << "\tTime taken: " << duration.count() << " ms\n";
    return true;
}

void Inventory::DisplayTableHeader(){
    cout << "+-----------+---------------------+------------------+--------------+-------------------+" << endl;
    cout << "| " << setw(10) << left << "PRODUCT ID"
         << "| " << setw(20) << left << "PRODUCT NAME"
         << "| " << setw(17) << left << "PRODUCT QUANTITY"
         << "| " << setw(13) << left << "PRODUCT PRICE"
          << "| " << setw(13) << left << "PRODUCT TYPE"
         << "     |" << endl;

    cout << "+-----------+---------------------+------------------+--------------+-------------------+" << endl;
}





