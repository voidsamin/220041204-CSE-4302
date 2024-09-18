#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

public:
    void assign(int num, int den)
    {
        if(den == 0)
            cerr << "You can not assign 0 as a denominator." << endl;
        else
        {
            numerator = num;
            denominator = den;
        }
    }

    double convert()
    {
        return (double)numerator/denominator;
    }

    void invert()
    {
        if(numerator == 0)
            cerr << "You can not assign 0 as denominator." << endl << "Inversion Failed." << endl;
        else
        {
            int temp = numerator;
            numerator = denominator;
            denominator = temp;
        }
    }

    void print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << "." << endl;
    }
};

int main()
{
    RationalNumber r;

    r.assign(5, 0); //Checking if our error checker for undefined state works.
    r.assign(3, 2);
    cout << r.convert() << endl; //Showing decimal version of the fraction
    r.print(); //Showing the fraction
    r.invert(); //Inverting the fraction
    r.print(); //Printing the inverted fraction
    r.assign(0, 5); //Setting fraction as 0/5 basically 0.
    cout<< r.convert() << endl;
    r.invert(); //Checking if our invert undefined error checker works

    return 0;
}
