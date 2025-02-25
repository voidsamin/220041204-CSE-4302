///code written by voidsamin (Fattah - 204)
///ichar.cpp

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    char ch;
    ifstream infile("TEST.txt");
    while(infile)
    {
        infile.get(ch);
        cout << ch;
    }
    cout << endl;

    return 0;
}
