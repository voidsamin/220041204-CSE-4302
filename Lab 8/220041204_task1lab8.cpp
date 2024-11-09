#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        string accountNo;
        string accountName;
        double balance;

    public:
        Account() {}
        void setAccountNo(string accno) {
            accountNo = accno;
        }
        void setAccountName(string accname) {
            accountName = accname;
        }
        void setBalance(double val) {
            if(val > 0.0)
                balance = val;
            else
                cerr << "Invalid balance, try again" << endl;
        }
        string getAccountNo() const {
            return accountNo;
        }
        string getAccountName() const {
            return accountName;
        }
        double getBalance() const {
            return balance;
        }
};

class CurrentAccount : public Account {
    private:
        const static string accountPrefix;
        const static double serviceCharge;
        static string nextAccount;

        static void nextAccountNo() {
            if(nextAccount.empty())
                nextAccount = "10000";
            else
            {
                int temp = stoi(nextAccount);
                temp++;
                nextAccount = to_string(temp);
            }
        }

    public:
        CurrentAccount(double val) : Account() {
            nextAccountNo();
            setAccountName("Current Account");
            setAccountNo(accountPrefix + nextAccount);
            setBalance(val - serviceCharge);
        }

        void description() {
            cout << "Account type: Current Account" << endl;
            cout << "Account Number: " << getAccountNo() << endl;
            cout << "Account Balance: " << getBalance() << endl;
            cout << "Other info: Service Charge per year " << serviceCharge << endl;
        }

        const double getServiceCharge() const {
            return serviceCharge;
        }
};

const string CurrentAccount::accountPrefix = "100";
const double CurrentAccount::serviceCharge = 100.0;
string CurrentAccount::nextAccount = "";

class SavingsAccount : public Account {
    private:
        double interestRate;
        double monthlyDepositAmount;
        const static string accountPrefix;
        static string nextAccount;

        static void nextAccountNo() {
            if(nextAccount.empty())
                nextAccount = "10000";
            else
            {
                int temp = stoi(nextAccount);
                temp++;
                nextAccount = to_string(temp);
            }
        }

    public:
        SavingsAccount(double rate, double mda, double val) : Account() {
            interestRate = rate;
            monthlyDepositAmount = mda;
            nextAccountNo();
            setAccountName("Savings Account");
            setAccountNo(accountPrefix + nextAccount);
            setBalance(val);
        }

        void setInterestRate(double rate) {
            if(rate > 0)
                interestRate = rate;
            else
                cerr << "Error, invalid rate" << endl;
        }

        void setMonthlyDepositAmount(double mda) {
            if(mda > 0)
                monthlyDepositAmount = mda;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getInterestRate() const {
            return interestRate;
        }

        double getMonthlyDepositAmount() const {
            return monthlyDepositAmount;
        }

        void description() {
            cout << "Account type: Savings Account" << endl;
            cout << "Account Number: " << getAccountNo() << endl;
            cout << "Account Balance: " << getBalance() << endl;
            cout << "Interest Rate: " << interestRate << endl;
            cout << "Monthly Deposit Amount: " << monthlyDepositAmount << endl;
        }
};

const string SavingsAccount::accountPrefix = "200";
string SavingsAccount::nextAccount = "";

class MonthlyDepositScheme : public Account {
    private:
        double interestRate;
        double monthlyDepositAmount;
        const static string accountPrefix;
        static string nextAccount;

        static void nextAccountNo() {
            if(nextAccount.empty())
                nextAccount = "10000";
            else
            {
                int temp = stoi(nextAccount);
                temp++;
                nextAccount = to_string(temp);
            }
        }

    public:
        MonthlyDepositScheme(double rate, double mda, double val) : Account() {
            interestRate = rate;
            monthlyDepositAmount = mda;
            nextAccountNo();
            setAccountName("Savings Account");
            setAccountNo(accountPrefix + nextAccount);
            setBalance(val);
        }

        void setInterestRate(double rate) {
            if(rate > 0)
                interestRate = rate;
            else
                cerr << "Error, invalid rate" << endl;
        }

        void setMonthlyDepositAmount(double mda) {
            if(mda > 0)
                monthlyDepositAmount = mda;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getInterestRate() const {
            return interestRate;
        }

        double getMonthlyDepositAmount() const {
            return monthlyDepositAmount;
        }

        void description() {
            cout << "Account type: Monthly Deposit Scheme" << endl;
            cout << "Account Number: " << getAccountNo() << endl;
            cout << "Account Balance: " << getBalance() << endl;
            cout << "Interest Rate: " << interestRate << endl;
            cout << "Monthly Deposit Amount: " << monthlyDepositAmount << endl;
        }
};

const string MonthlyDepositScheme::accountPrefix = "300";
string MonthlyDepositScheme::nextAccount = "";

class LoanAccount : public Account {
    private:
        double interestRate;
        double monthlyDepositAmount;
        const static string accountPrefix;
        static string nextAccount;

        static void nextAccountNo() {
            if(nextAccount.empty())
                nextAccount = "10000";
            else
            {
                int temp = stoi(nextAccount);
                temp++;
                nextAccount = to_string(temp);
            }
        }

    public:
        LoanAccount(double rate, double mda, double val) : Account() {
            interestRate = rate;
            monthlyDepositAmount = mda;
            nextAccountNo();
            setAccountName("Savings Account");
            setAccountNo(accountPrefix + nextAccount);
            setBalance(val);
        }

        void setInterestRate(double rate) {
            if(rate > 0)
                interestRate = rate;
            else
                cerr << "Error, invalid rate" << endl;
        }

        void setMonthlyDepositAmount(double mda) {
            if(mda > 0)
                monthlyDepositAmount = mda;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getInterestRate() const {
            return interestRate;
        }

        double getMonthlyDepositAmount() const {
            return monthlyDepositAmount;
        }

        void description() {
            cout << "Account type: Loan Account" << endl;
            cout << "Account Number: " << getAccountNo() << endl;
            cout << "Account Balance: " << getBalance() << endl;
            cout << "Interest Rate: " << interestRate << endl;
            cout << "Monthly Deposit Amount: " << monthlyDepositAmount << endl;
        }
};

const string LoanAccount::accountPrefix = "900";
string LoanAccount::nextAccount = "";

class  TwoYearMDS : public MonthlyDepositScheme {
    private:
        double maximumInterest;

    public:
        TwoYearMDS(double rate, double mda, double val, double max_interest) : MonthlyDepositScheme(rate, mda, val) {
            maximumInterest = max_interest;
        }

        void setMaximumInterest(double max_interest) {
            if(max_interest > 0.0)
                maximumInterest = max_interest;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getMaximumInterest() const {
            return maximumInterest;
        }

        void description() {
            MonthlyDepositScheme::description();
            cout << "Type of MDS: Two Years MDS" << endl;
            cout << "Maximum Interest Amount: " << maximumInterest << endl;
        }
};

class  FiveYearMDS : public MonthlyDepositScheme {
    private:
        double maximumInterest;

    public:
        FiveYearMDS(double rate, double mda, double val, double max_interest) : MonthlyDepositScheme(rate, mda, val) {
            maximumInterest = max_interest;
        }

        void setMaximumInterest(double max_interest) {
            if(max_interest > 0.0)
                maximumInterest = max_interest;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getMaximumInterest() const {
            return maximumInterest;
        }

        void description() {
            MonthlyDepositScheme::description();
            cout << "Type of MDS: Five Years MDS" << endl;
            cout << "Maximum Interest Amount: " << maximumInterest << endl;
        }
};

class  InitialDepositMDS : public MonthlyDepositScheme {
    private:
        double maximumInterest;
        double initialDepositAmount;

    public:
        InitialDepositMDS(double rate, double mda, double val, double max_interest, double init_dep_amount) : MonthlyDepositScheme(rate, mda, val) {
            maximumInterest = max_interest;
            initialDepositAmount = init_dep_amount;
        }

        void setMaximumInterest(double max_interest) {
            if(max_interest > 0.0)
                maximumInterest = max_interest;
            else
                cerr << "Error, invalid amount" << endl;
        }

        void setInitialDepositAmount(double init_dep_amount) {
            if(init_dep_amount > 100.0)
                initialDepositAmount = init_dep_amount;
            else
                cerr << "Error, invalid amount" << endl;
        }

        double getMaximumInterest() const {
            return maximumInterest;
        }

        double getInitialDepositAmount() const {
            return initialDepositAmount;
        }

        void description() {
            MonthlyDepositScheme::description();
            cout << "Type of MDS: Initial Deposit MDS" << endl;
            cout << "Maximum Interest Amount: " << maximumInterest << endl;
            cout << "Initial Deposit Amount: " << initialDepositAmount << endl;
        }
};

int main() {
    CurrentAccount c(5000.00), c1(7600.00), c2(100500.00);
    c.description();
    c1.description();
    c2.description();

    SavingsAccount s(12.5, 2500, 300.0), s1(15.5, 1000, 7600.00), s2(11.25, 1500, 100500.00);
    s.description();
    s1.description();
    s2.description();

    TwoYearMDS t(12.5, 2500, 100.0, 5000), t1(15.5, 1000, 7600.00, 14000), t2(11.25, 1500, 100500.00, 250000.0);
    t.description();
    t1.description();
    t2.description();

    FiveYearMDS f(12.5, 2500, 5000.0, 5000), f1(15.5, 1000, 7600.00, 14000), f2(11.25, 1500, 100500.00, 250000.0);
    f.description();
    f1.description();
    f2.description();

    InitialDepositMDS i(12.5, 2500, 6000.0, 5000, 1000), i1(15.5, 1000, 7600.00, 14000, 2000), i2(11.25, 1500, 100500.00, 250000.0, 50000);
    i.description();
    i1.description();
    i2.description();

    return 0;
}
