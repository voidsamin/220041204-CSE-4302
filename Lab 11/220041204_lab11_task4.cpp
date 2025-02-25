///code written by voidsamin (Fattah - 204)
///opers.cpp

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
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
        }
};

int main()
{
    Person pers;
    pers.getData();

    ofstream outfile("PERSON.dat", ios::binary);
    outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));

    return 0;
}
