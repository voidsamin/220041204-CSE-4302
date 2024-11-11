#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        string EmpName;
        unsigned int ID;
        unsigned int Age;
        double Salary;

        string getStatus() {
            if(Age <= 25) {
                if(Salary <= 20000) return "Low";
                else return "Moderate";
            }
            else {
                if(Salary <= 21000) return "Low";
                else if(Salary > 21000 && Salary <= 60000) return "Moderate";
                else return "High";
            }
        }

    public:
        Employee() : EmpName(""), ID(0), Age(0), Salary(0.00) {}
        Employee(const string& name, const unsigned int& id, const unsigned int& age, const double& sal) {
            FeedInfo(name, id, age, sal);
        }
        void FeedInfo(const string& name, const unsigned int& id, const unsigned int& age, const double& sal) {
            EmpName = name;
            ID = id;
            Age = age;
            Salary = sal;
        }
        void ShowInfo() {
            cout << "Employee Name: " << EmpName << endl;
            cout << "Employee ID: " << ID << endl;
            cout << "Employee Age: " << Age << endl;
            cout << "Monthly Salary: BDT " << Salary << endl;
            cout << "Status: " << getStatus() << endl;
        }
};

int main() {
    Employee e1, e2;
    e1.FeedInfo("John Doe", 123, 32, 75000);
    e2.FeedInfo("Podolov", 334, 23, 18000);

    e1.ShowInfo();
    cout << endl;
    e2.ShowInfo();

    return 0;
}
