///code written by voidsamin (Fattah - 204)
///seekg.cpp

#include <fstream>
#include <iostream>

using namespace std;

class Person{
    private:
        char name[80];
        short age;

    public:
        void getData()
        {
            cout << "\n  Enter name: ";
            cin >> name;
            cout << "  Enter age: ";
            cin >> age;
        }

        void showData()
        {
            cout << "\n  Name: " << name;
            cout << "\n  Age: " << age;
        }
};

int main()
{
    Person pers;
    ifstream infile;
    infile.open("GROUP.dat", ios::in | ios::binary);

    infile.seekg(0, ios::end);
    int endposition = infile.tellg();
    int n = endposition / sizeof(Person);
    cout << "\nThere are " << n << " persons in file.";

    cout << "\nEnter person number: ";
    cin >> n;
    int position = (n - 1) * sizeof(Person);
    infile.seekg(position);

    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();
    cout << endl;
    infile.close();

    return 0;
}
