#include "DiscountedProduct.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//Constructer Accepting Arguement Of Parent Class And Child Class
DiscountedProduct::DiscountedProduct (int ProductId, string ProductName, int ProductQuantity, double ProductPrice)
    :Product(ProductId, ProductName, ProductQuantity, ProductPrice) //Construct Of Parent Class
{
    this->ProductDiscount =  ProductDiscount;
}

double DiscountedProduct::discountCalculation(){
    return ProductDiscount/100;
}

double DiscountedProduct::calculateFinalPrice(){
    return ProductPrice - (ProductPrice * discountCalculation());
}

void DiscountedProduct::displayProduct(){
    cout << "| " << setw(10) << left << productID
         << "| " << setw(20) << left << ProductName
         << "| " << setw(17) << left << ProductQuantity
         << "| R" << setw(12) << left << calculateFinalPrice()  // price AFTER 10% discount
         << "| " << setw(13) << left << "Discount (-10%)"
         << "   |" << endl;
}

