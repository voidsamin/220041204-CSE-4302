#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        unsigned int accountNumber;
        string accountHolderName;
        string accountType;
        double currentBalance;
        const double minimumBalance;
        const double interestRate;

        static double sourceTax;
        static unsigned int createdCount;
        static unsigned int presentCount;

    public:
        BankAccount() : accountNumber(0), accountHolderName(""), accountType(""), currentBalance(2000.00), minimumBalance(1000.00), interestRate(3.00) { createdCount++; presentCount++; }
        BankAccount(const unsigned int& num, const string& name, const string& type, const double& currBal, const double& minBal) : accountNumber(num), accountHolderName(name), accountType(type), minimumBalance(minBal), interestRate(3.00) {
            if(currBal < minBal) {
                cerr << "Invalid current balance" << endl;
                currentBalance = minimumBalance;
            }
            else
                currentBalance = currBal;

            createdCount++;
            presentCount++;
        }
        void setAccountNumber(const unsigned int& num) {
            accountNumber = num;
        }
        void setAccountHolderName(const string& name) {
            accountHolderName = name;
        }
        void setAccountType(const string& type) {
            accountType = type;
        }
        void setCurrentBalance(const double& currBal) {
            if(currentBalance < minimumBalance) {
                currentBalance = minimumBalance;
                cerr << "Invalid current balance" << endl;
            }
            else
                currentBalance = currBal;
        }
        void showInfo() const {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: Mr. " << accountHolderName << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Current Balance: BDT " << currentBalance << endl;
            cout << "Minimum Balance: BDT " << minimumBalance << endl;
        }
        void showBalance() const {
            cout << "Current Balance: BDT " << currentBalance << endl;
        }
        double getCurrentBalance() const {
            return currentBalance;
        }
        void deposit(const double& val) {
            if(val < 500.00)
                cerr << "Invalid amount, deposit more." << endl;
            else
                currentBalance += val;
        }
        void withdrawal(const double& val) {
            if(currentBalance - val < minimumBalance)
                cerr << "Error, can not withdraw a larger amount than BDT " << abs(minimumBalance - currentBalance) << endl;
            else
                currentBalance -= val;
        }
        void giveInterest() {
            double temp = currentBalance * interestRate / 100.00;
            sourceTax += (temp * 0.1);
            temp *= 0.9;
            currentBalance += temp;
        }
        void giveInterest(const double& rate) {
            if(rate > 0) {
                double temp = currentBalance * rate / 100.00;
                sourceTax += (temp * 0.1);
                temp *= 0.9;
                currentBalance += temp;
            }
            else {
                double temp = currentBalance * interestRate / 100.00;
                sourceTax += (temp * 0.1);
                temp *= 0.9;
                currentBalance += temp;
            }
        }
        ~BankAccount() {
            cout << "Account of Mr. " << accountHolderName << " with account no. " << accountNumber << " is destroyed with a balance BDT " << currentBalance << endl;
            presentCount--;
        }

        friend void display_stat();
};

double BankAccount::sourceTax = 0.00;
unsigned int BankAccount::createdCount = 0;
unsigned int BankAccount::presentCount = 0;

void display_stat() {
    cout << "Total number of BankAccount objects created: " << BankAccount::createdCount << endl;
    cout << "Total number of BankAccount objects currently present in the program: " << BankAccount::presentCount << endl;
    cout << "Total amount of source tax collected from all bank accounts: BDT " << BankAccount::sourceTax << endl;
}

BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    if(A.getCurrentBalance() > B.getCurrentBalance())
        return A;
    return B;
}

int main() {
    BankAccount a(12345, "Sterling", "Savings Account", 50000.00, 10000.00), b(22222, "Raheem", "Fixed Deposit Account", 100000.00, 20000.00);

    a.showBalance();
    cout << endl;
    a.deposit(25000);
    a.showInfo();
    cout << endl;
    b.showInfo();
    cout << endl;

    a.giveInterest();
    b.giveInterest(15.00);

    a.showInfo();
    cout << endl;
    b.showInfo();
    cout << endl;

    b.withdrawal(99000.00);
    cout << endl;

    display_stat();
    cout << endl;

    BankAccount temp = Larger(a, b);
    temp.showInfo();
    cout << endl;

    display_stat();
    cout << endl;

    b.~BankAccount();
    cout << endl;

    display_stat();
    cout << endl;

    return 0;
}
