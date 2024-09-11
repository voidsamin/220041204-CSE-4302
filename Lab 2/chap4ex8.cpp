#include <iostream>

using namespace std;

struct fraction{
    int numerator;
    int denominator;
};

int main()
{
    fraction first, second;
    char dummychar;

    cout<<"Enter first fraction: ";
    cin>>first.numerator>>dummychar>>first.denominator;

    cout<<"Enter second fraction: ";
    cin>>second.numerator>>dummychar>>second.denominator;

    if(first.denominator == 0 || second.denominator == 0)
    {
        cout<<"Math error."<<endl;
        return 0;
    }

    fraction sum;

    if(second.denominator != first.denominator)
    {
        sum.numerator = (first.numerator * second.denominator) + (first.denominator * second.numerator);
        sum.denominator = (first.denominator * second.denominator);
    }
    else
    {
        sum.numerator = first.numerator + second.numerator;
        sum.denominator = first.denominator;
    }

    cout<<"Sum: "<<sum.numerator<<"/"<<sum.denominator<<endl;

    return 0;
}
