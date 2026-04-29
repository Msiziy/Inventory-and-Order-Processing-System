#include "Order.h"
#include <iostream>
#include <string>
using namespace std;


Order::Order(int OrderId,int ProductId, int QuantityRequested, string status){
    this->OrderId = OrderId;
    this->ProductId = ProductId;
    this->QuantityRequested = QuantityRequested;
    this->status = status;
}

int Order::getOrderId(){
    return OrderId;
}

int Order::getProduct_ID(){
    return ProductId;
}

int Order::getQuantityRequested(){
    return QuantityRequested;
}

string Order::getStatus(){
    return status;
}

void Order::setStatus(string status){
    this -> status = status;
}

