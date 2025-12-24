#include <iostream>
using namespace std;

class Payment {
protected:
    float amount;

public:
    Payment(float a) {
        amount = a;
    }

    virtual void pay() = 0;

    virtual ~Payment() {}
};

class CreditCard : public Payment {
public:
    CreditCard(float a) : Payment(a) {}

    void pay() {
        cout << "Payment Method: Credit Card\n";
        cout << "Amount Paid: " << amount << endl;
    }
};

class CashOnDelivery : public Payment {
public:
    CashOnDelivery(float a) : Payment(a) {}

    void pay() {
        cout << "Payment Method: Cash on Delivery\n";
        cout << "Amount to Pay: " << amount << endl;
    }
};

class Order {
private:
    int orderId;
    float totalAmount;
    string productName;     

public:
    Order(int id, float amt, string pname) {
        orderId = id;
        totalAmount = amt;
        productName = pname; 
    }

    void showOrder() {
        cout << "Order ID: " << orderId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Total Amount: " << totalAmount << endl;
    }

    float validateAmount() {
        try {
            if (totalAmount <= 0) {
                throw totalAmount;
            }
            return totalAmount;
        }
        catch (float) {
            cout << "Error: Invalid order amount!\n";
            return 0;
        }
    }
};

int main() {

    Order o1(101, 5000, "Laptop");  
    o1.showOrder();

    float amt = o1.validateAmount();

    if (amt > 0) {
        Payment* p;

        CreditCard cc(amt);
        p = &cc;
        p->pay();

        cout << endl;

        CashOnDelivery cod(amt);
        p = &cod;
        p->pay();
    }

    return 0;
}
