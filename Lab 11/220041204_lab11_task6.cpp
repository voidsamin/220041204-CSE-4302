///code written by voidsamin (Fattah - 204)
///diskfun.cpp

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
    char ch;
    Person pers;
    fstream file;

    file.open("GROUP.dat", ios::app | ios::out | ios::in | ios::binary);

    do
    {
        cout << "Enter person's data:";
        pers.getData();

        file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
        cout << "Enter another person? (y/n)" << endl;
        cin >> ch;
    } while(ch == 'y');
    file.seekg(0);

    file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    while(!file.eof())
    {
        cout << "\nPerson:";
        pers.showData();
        file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    }
    cout << endl;

    file.close();

    return 0;
}
