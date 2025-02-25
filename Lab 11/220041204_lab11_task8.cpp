///code written by voidsamin (Fattah - 204)
///rewerr.cpp

#include <fstream>
#include <iostream>

using namespace std;
#include <process.h>

const int MAX = 1000;
int buff[MAX];

int main()
{
    for(int i = 0; i < MAX; i++)
        buff[i] = i;

    ofstream os;
    os.open("a:edata.dat", ios::trunc | ios::binary);
    if(!os)
    {
        cerr << "Could not open output file." << endl;
        exit(1);
    }
    cout << "Writing..." << endl;
    os.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));

    if(!os)
    {
        cerr << "Could not write to file." << endl;
        exit(1);
    }
    os.close();

    for(int i = 0; i < MAX; i++)
        buff[i] = 0;

    ifstream is;
    is.open("a:edata.dat", ios::binary);
    if(!os)
    {
        cerr << "Could not open input file." << endl;
        exit(1);
    }
    cout << "Reading..." << endl;
    is.read(reinterpret_cast<char*>(buff), MAX*sizeof(int));

    if(!is)
    {
        cerr << "Could not read from file." << endl;
        exit(1);
    }
    is.close();

    for(int i = 0; i < MAX; i++)
    {
        if(buff[i] != i)
        {
            cerr << "Data is incorrect." << endl;
            exit(1);
        }
    }
    cout << "Data is correct." << endl;

    return 0;
}
