#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    bool available;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}

    void display() {
        cout<<"Title - "<<title<<" Author - "<<author<<" ISBN - "<<isbn<<" Available - "<<(available ? "Yes" : "No")<<endl;
    }
};

class Borrower {
public:
    string name;
    int id;
    vector<Book> books;

    Borrower(string n, int i) : name(n), id(i) {}

    void showBooks() {
        cout<<"Borrower "<<name<<" (ID "<<id<<")"<<endl;
        for (int j = 0; j < books.size(); j++) {
            books[j].display();
        }
    }
};

class Library {
private:
    vector<Book> bookList;
    vector<Borrower> borrowerList;

public:
    void addBook(const Book& b) {
        bookList.push_back(b);
        cout<<"Book added"<<endl;
    }

    void searchBook(const string& query) {
        bool found = false;
        for (int i = 0; i < bookList.size(); i++) {
            if (bookList[i].title == query || bookList[i].author == query || bookList[i].isbn == query) {
                bookList[i].display();
                found = true;
            }
        }
        if (!found) {
            cout<<"Book not found"<<endl;
        }
    }

    Borrower* findBorrower(int id) {
        for (int i = 0; i < borrowerList.size(); i++) {
            if (borrowerList[i].id == id) {
                return &borrowerList[i];
            }
        }
        return nullptr;
    }

    void checkoutBook(const string& isbn, int borrowerID) {
        Borrower* borrower = findBorrower(borrowerID);
        if (borrower == nullptr) {
            cout<<"Borrower not found"<<endl;
            return;
        }

        for (int i = 0; i < bookList.size(); i++) {
            if (bookList[i].isbn == isbn && bookList[i].available) {
                borrower->books.push_back(bookList[i]);
                bookList[i].available = false;
                cout<<"Book checked out"<<endl;
                return;
            }
        }
        cout<<"Book is unavailable"<<endl;
    }

    void returnBook(const string& isbn, int borrowerID) {
        Borrower* borrower = findBorrower(borrowerID);
        if (borrower == nullptr) {
            cout<<"Borrower not found"<<endl;
            return;
        }

        for (int i = 0; i < bookList.size(); i++) {
            if (bookList[i].isbn == isbn) {
                bookList[i].available = true;
                cout<<"Book returned"<<endl;
                return;
            }
        }
        cout<<"Book not found in the system"<<endl;
    }

    void addBorrower(const Borrower& b) {
        borrowerList.push_back(b);
        cout<<"Borrower added"<<endl;
    }

    double calcFine(int lateDays) {
        const double finePerDay = 2.0;
        return lateDays * finePerDay;
    }
};

void showMenu() {
    cout<<"1 Add Book"<<endl;
    cout<<"2 Search Book"<<endl;
    cout<<"3 Checkout Book"<<endl;
    cout<<"4 Return Book"<<endl;
    cout<<"5 Add Borrower"<<endl;
    cout<<"6 Exit"<<endl;
}

int main() {
    Library lib;
    int choice;
    string title, author, isbn;
    int id;
    string borrowerName;

    while (true) {
        showMenu();
        cout<<"Enter choice ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter title: ";
                cin>>title;
                cout<<"Enter author: ";
                cin>>author;
                cout<<"Enter ISBN : ";
                cin>>isbn;
                lib.addBook(Book(title, author, isbn));
                break;

            case 2:
                cout<<"Enter title, author, or ISBN to search: ";
                cin>>title;
                lib.searchBook(title);
                break;

            case 3:
                cout<<"Enter Borrower ID : ";
                cin>>id;
                cout<<"Enter ISBN : ";
                cin>>isbn;
                lib.checkoutBook(isbn, id);
                break;

            case 4:
                cout<<"Enter Borrower ID: ";
                cin>>id;
                cout<<"Enter ISBN :";
                cin>>isbn;
                lib.returnBook(isbn, id);
                break;

            case 5:
                cout<<"Enter borrower name : ";
                cin>>borrowerName;
                cout<<"Enter borrower ID: ";
                cin>>id;
                lib.addBorrower(Borrower(borrowerName, id));
                break;

            case 6:
                cout<<"Exit ";
                return 0;
        }
    }

return 0;
}