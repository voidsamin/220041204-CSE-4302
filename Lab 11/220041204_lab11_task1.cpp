///code written by voidsamin (Fattah - 204)
///ochar.cpp

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Time is a great teacher, but unfortunately it kills all its pupils. --Berloiz";

    ofstream outfile("TEST.txt");
    for(int i = 0; i < str.size(); i++)
        outfile.put(str[i]);
    cout << "File written." << endl;

    return 0;
}
