///code written by voidsamin (Fattah - 204)
///ipers.cpp

#include <fstream>
#include <iostream>

using namespace std;

class Person{
    private:
        char name[80];
        short age;

    public:
        void showData()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int main()
{
    Person pers;

    ifstream infile("PERSON.dat", ios::binary);
    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();

    return 0;
}
