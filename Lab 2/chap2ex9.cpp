#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    char dummychar;

    cout<<"Enter first fraction: ";
    cin>>a>>dummychar>>b;

    cout<<"Enter second fraction: ";
    cin>>c>>dummychar>>d;

    if(b == 0 || d == 0)
    {
        cout<<"Math error."<<endl;
        return 1;
    }

    int num, den;

    if(b != d)
    {
        num = (a * d) + (b * c);
        den = (b * d);
    }
    else
    {
        num = a + c;
        den = b;
    }


    cout<<"Sum: "<<num<<"/"<<den<<endl;

    return 0;
}
