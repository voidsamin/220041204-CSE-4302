#include <iostream>
#include <cstring>
using namespace std;

class Medicine {
private:
    char tradeName[30];
    char genericName[30];
    double unitPrice;
    double discountPercentage = 5;

public:
    void assignName(const char trade_name[], const char generic_name[])
    {
        if(trade_name == NULL && generic_name == NULL)
            cerr << "Names are null." << endl;
        else
        {
            strcpy(tradeName, trade_name);
            strcpy(genericName, generic_name);
        }
    }

    void assignPrice(double price)
    {
        unitPrice = price;
    }

    void setDiscountPercent(double percent)
    {
        if(percent >= 0 && percent <= 30)
            discountPercentage = percent;
    }

    double getSellingPrice()
    {
        return unitPrice - (unitPrice * discountPercentage / 100);
    }

    double getSellingPrice(int nos)
    {
        return nos * ( unitPrice - (unitPrice * discountPercentage / 100) );
    }

    void display()
    {
        cout << "MRP. of " << tradeName << " (" << genericName << ") " << "is BDT " << unitPrice << ". Current discount " << discountPercentage << "%. Selling price BDT " << getSellingPrice() << "." << endl;
    }
};

int main()
{
    Medicine m;

    m.assignName("Napa", "Paracetamol");
    m.assignPrice(1.00);
    m.setDiscountPercent(10.00);
    cout<< "Selling Price of 10 units with discount: BDT " << m.getSellingPrice(10) << endl;
    m.display();

    return 0;
}
