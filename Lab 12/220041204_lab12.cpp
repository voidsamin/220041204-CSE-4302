#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class Book{
    private:
        string title;
        string author;
        string isbn;

    public:
        Book(string __title, string __author, string __isbn) : title(__title), author(__author), isbn(__isbn) {}
        string getTitle() const {
            return title;
        }
        string getAuthor() const {
            return author;
        }
        string getIsbn() const {
            return isbn;
        }
        void display() const {
            cout << "Title of the book: " << title << endl;
            cout << "Author of the book: " << author << endl;
            cout << "ISBN of the book: " << isbn << endl;
        }
};

class Library{
    private:
        vector<Book> inventory;
        deque<Book> borrowedBooks;
        list<Book> archivedBooks;

    public:
        void addBook(){
            string title;
            string author;
            string isbn;

            cout << "Enter title of the book: ";
            getline(cin, title);
            //cin.ignore();
            cout << "Enter author of the book: ";
            getline(cin, author);
            //cin.ignore();
            cout << "Enter ISBN of the book: ";
            getline(cin, isbn);

            Book b(title, author, isbn);

            inventory.push_back(b);
            cout << "Added book " << b.getTitle() << " to the inventory." << endl;
        }

        void addBook(const Book &b){
            inventory.push_back(b);
            cout << "Added book " << b.getTitle() << " to the inventory." << endl;
        }

        void borrowBook(const Book &b){
            bool flag = false;
            for(int i = 0; i < inventory.size(); i++){
                if(b.getIsbn() == inventory[i].getIsbn()){
                    flag = true;
                    inventory.erase(inventory.begin() + i);
                    break;
                }
            }
            if(flag){
                borrowedBooks.push_back(b);
                cout << "Borrowed book: " << b.getTitle() << endl;
            }
            else
                cout << "Book doesn't exist in inventory." << endl;
        }

        void returnBook(const Book &b){
            bool flag = false;
            for(int i = 0; i < borrowedBooks.size(); i++){
                if(b.getIsbn() == borrowedBooks[i].getIsbn()){
                    flag = true;
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                    break;
                }
            }
            if(flag){
                inventory.push_back(b);
                cout << "Returned book: " << b.getTitle() << endl;
            }
            else
                cout << "Book was not borrowed." << endl;
        }

        void archiveBook(const Book &b){
            bool flag = false;
            for(int i = 0; i < inventory.size(); i++){
                if(b.getIsbn() == inventory[i].getIsbn()){
                    flag = true;
                    inventory.erase(inventory.begin() + i);
                    break;
                }
            }
            if(flag){
                archivedBooks.push_back(b);
                cout << "Archived book: " << b.getTitle() << endl;
            }
            else
                cout << "Book doesn't exist in inventory." << endl;
        }

        void display() const {
            cout << "Books in inventory:" << endl;
            for(int i = 0; i < inventory.size(); i++){
                cout << "Book " << i + 1 << ":" << endl;
                inventory[i].display();
            }
            cout << endl;
            cout << "Books borrowed:" << endl;
            for(int i = 0; i < borrowedBooks.size(); i++){
                cout << "Book " << i + 1 << ":" << endl;
                borrowedBooks[i].display();
            }
            cout << endl;
            cout << "Books archived:" << endl;
            int i = 1;
            for(auto x:archivedBooks){
                cout << "Book " << i << ":" << endl;
                x.display();
                i++;
            }
        }

        void saveData() {
            ofstream inventoryFile("inventory.txt");
            if(!inventoryFile){
                cerr << "Error opening inventory file." << endl;
                exit(1);
            }
            ofstream borrowedFile("borrowed.txt");
            if(!borrowedFile){
                cerr << "Error opening borrowed file." << endl;
                exit(1);
            }
            ofstream archivedFile("archived.txt");
            if(!archivedFile){
                cerr << "Error opening archived file." << endl;
                exit(1);
            }

            for(auto x:inventory)
                inventoryFile << x.getTitle() << "," << x.getAuthor() << "," << x.getIsbn() << endl;

            for(auto x:borrowedBooks)
                borrowedFile << x.getTitle() << "," << x.getAuthor() << "," << x.getIsbn() << endl;

            for(auto x:archivedBooks)
                archivedFile << x.getTitle() << "," << x.getAuthor() << "," << x.getIsbn() << endl;

            inventoryFile.close();
            borrowedFile.close();
            archivedFile.close();
        }

        void loadData() {
            ifstream inventoryFile("inventory.txt");
            if(!inventoryFile){
                cerr << "Error opening inventory file." << endl;
                exit(1);
            }
            ifstream borrowedFile("borrowed.txt");
            if(!borrowedFile){
                cerr << "Error opening borrowed file." << endl;
                exit(1);
            }
            ifstream archivedFile("archived.txt");
            if(!archivedFile){
                cerr << "Error opening archived file." << endl;
                exit(1);
            }

            string line;

            while (getline(inventoryFile, line)){
                string title, author, isbn;
                stringstream ss(line);
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');

                inventory.push_back(Book(title, author, isbn));
            }

            while (getline(borrowedFile, line)){
                string title, author, isbn;
                stringstream ss(line);
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');

                borrowedBooks.push_back(Book(title, author, isbn));
            }

            while (getline(archivedFile, line)){
                string title, author, isbn;
                stringstream ss(line);
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');

                archivedBooks.push_back(Book(title, author, isbn));
            }

            inventoryFile.close();
            borrowedFile.close();
            archivedFile.close();
        }
};

int main(){
    Library lib;

    lib.addBook();
    lib.addBook();

    Book b("Harry Potter", "J.K Rowling", "HP204");
    lib.borrowBook(b);
    lib.borrowBook(b);

    lib.returnBook(b);
    lib.returnBook(b);

    lib.archiveBook(b);
    lib.archiveBook(b);

    Book b1("Bonfire", "Fattah", "220041204");
    lib.addBook();
    lib.borrowBook(b1);

    lib.saveData();

    lib.loadData();

    return 0;
}
