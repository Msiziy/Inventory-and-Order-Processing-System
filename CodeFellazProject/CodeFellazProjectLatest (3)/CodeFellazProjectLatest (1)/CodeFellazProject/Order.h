#pragma once
#include <string>
using namespace std;

class Order{
    private:
        int OrderId;
        int ProductId;
        int QuantityRequested;
        string status;

    public:
        Order(int OrderId, int ProductId, int QuantityRequested, string status);
        int getOrderId();
        int getProduct_ID();
        int getQuantityRequested();
        string getStatus();
        void setStatus(string status);
};
