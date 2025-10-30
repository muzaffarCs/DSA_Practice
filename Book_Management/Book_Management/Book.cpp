#include "Book.h"

Book::Book() : id(0), title(" "), author(" "), quantity(0), price(0) {}

Book::Book(int id, const string& title, const string& author, int quantity, double price)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->quantity = quantity;
    this->price = price;

}
Book::~Book() {}


int Book::getId() const {
    return this->id;
}

string Book::getTitle() const {
    return this->title;
}
int Book::getQuantity() const {
    return this->quantity;
}
string Book::getAuthor() const {
    return this->author;
}
double Book::getPrice() const {
    return this->price;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        this->id = other.id;
        this->title = other.title;
        this->author = other.author;
        this->quantity = other.quantity;
        this->price = other.price;
    }
    return *this;
}

ostream& operator<<(ostream& COUT, const Book& book) {
    cout << "Id: " << book.id << "\nTitle: " << book.title << "\nAuthor: " << book.author
        << "\nQuantity: " << book.quantity << "\nPrice: " << book.price << endl;
    return COUT;
}

istream& operator>>(istream& CIN, Book& book) {
    cout << "Enter Book Id: ";
    CIN >> book.id;

    cin.ignore();
    cout << "Enter Book Title: ";
    getline(CIN, book.title, '\n');

    cout << "Enter Book Author: ";
    getline(CIN, book.author, '\n');

    cout << "Enter the Quantity:";
    CIN >> book.quantity;

    cout << "Enter Book Price:";
    CIN >> book.price;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return CIN;
}