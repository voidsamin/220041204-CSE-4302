///code written by voidsamin (Fattah - 204)
///rewobj.cpp

#include <fstream>
#include <iostream>

using namespace std;

class Person{
    private:
        char name[40];
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

        void diskIn(int);
        void diskOut();
        static int diskCount();
};

void Person::diskIn(int pn)
{
    ifstream infile;
    infile.open("PERSFILE.dat", ios::binary);
    infile.seekg(pn*sizeof(Person));
    infile.read((char*)this, sizeof(*this));
}

void Person::diskOut()
{
    ofstream outfile;
    outfile.open("PERSFILE.dat", ios::app | ios::binary);
    outfile.write((char*)this, sizeof(*this));
}

int Person::diskCount()
{
    ifstream infile;
    infile.open("PERSFILE.dat", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(Person);
}

int main()
{
    Person p;
    char ch;

    do
    {
        cout << "Enter data for person:";
        p.getData();
        p.diskOut();
        cout << "Do another? (y/n)" << endl;
        cin >> ch;
    } while (ch == 'y');

    int n = Person::diskCount();
    cout << "There are " << n << " persons in file." << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "\nPerson #" << i;
        p.diskIn(i);
        p.showData();
    }
    cout << endl;

    return 0;
}
