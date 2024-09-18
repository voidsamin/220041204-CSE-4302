#include <iostream>
using namespace std;

class Counter {
private:
    int countValue = 0;
    int incrementStep = 0;

public:
    void setIncrementStep(const int x)
    {
        if(x > 0)
            incrementStep = x;
    }

    int getCount()
    {
        return countValue;
    }

    void increment()
    {
        countValue += incrementStep;
    }

    void resetCount()
    {
        countValue = 0;
    }
};

int main()
{
    Counter c1;

    cout<<c1.getCount()<<endl;
    c1.setIncrementStep(2);
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.setIncrementStep(5);
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<c1.getCount()<<endl;

    return 0;
}
