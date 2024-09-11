#include <iostream>

using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

int main()
{
    etype temp;

    char ch;
    cout<<"Enter employee type (first letter only): "<<endl;
    cout<<"l = laborer, s = secretary, m = manager, a = accountant, e = executive, r = researcher."<<endl;
    cin>>ch;

    switch(ch)
    {
        case 'l':
            temp = laborer;
            break;

        case 's':
            temp = secretary;
            break;

        case 'm':
            temp = manager;
            break;

        case 'a':
            temp = accountant;
            break;

        case 'e':
            temp = executive;
            break;

        case 'r':
            temp = researcher;
            break;

        default:
            cout<<"Invalid employee type."<<endl;
            break;
    }

    cout<<"Your employee type is: ";

    switch(temp)
    {
        case laborer:
            cout<<"laborer."<<endl;
            break;

        case secretary:
            cout<<"secretary."<<endl;
            break;

        case manager:
            cout<<"manager."<<endl;
            break;

        case accountant:
            cout<<"accountant."<<endl;
            break;

        case executive:
            cout<<"executive."<<endl;
            break;

        case researcher:
            cout<<"researcher."<<endl;
            break;

        default:
            cout<<"none (invalid type entered)."<<endl;
            break;
    }

    return 0;
}
