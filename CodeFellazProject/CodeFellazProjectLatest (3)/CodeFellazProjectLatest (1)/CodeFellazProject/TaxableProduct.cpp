#include "TaxableProduct.h"
#include <iostream>
#include <iomanip>
using namespace std;

TaxableProduct::TaxableProduct(int ProductId, string ProductName, int ProductQuantity, double ProductPrice)
    :Product(ProductId, ProductName, ProductQuantity, ProductPrice ){}

double TaxableProduct::calculateFinalPrice(){
    return (ProductPrice + (ProductPrice*(productTax/100.0)));
}

void TaxableProduct::displayProduct(){
   cout << "| " << setw(10) << left << productID
         << "| " << setw(20) << left << ProductName
         << "| " << setw(17) << left << ProductQuantity
         << "| R" << setw(12) << left << calculateFinalPrice()  // price AFTER 15% tax
         << "| " << setw(13) << left << "Taxable  (+15%)"
         << "   |" << endl;
}
