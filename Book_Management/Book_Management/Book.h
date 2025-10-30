#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
    int id;
    string title, author;
    int quantity;
    double price;

    friend ostream& operator<<(ostream&, const Book&);
    friend istream& operator>>(istream&, Book&);

public:
    Book();
    Book(int id, const string& title, const string& author, int quantity, double price);
    ~Book();
    int getId() const;
    string getTitle() const;
    int getQuantity() const;
    string getAuthor() const;
    double getPrice() const;
    Book& operator=(const Book& other);
};