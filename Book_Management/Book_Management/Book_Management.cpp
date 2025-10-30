#include "Book.h"
#include <iostream>
#include <fstream>

char Menu();
void addBook(Book*& books, int& size);
void updateBook(Book* books, int size);
void deleteBook(Book*& books, int& size);
void findBook(Book* books, int size);
void printBooks(Book* books, int size);
void writeData(Book* books, int size);
void readData(Book*& books, int& size, const string& filename);
void exportToCSV(Book* books, int size);

int main() {
    char choice;
    bool flag = true;
    int size = 0;
    Book* books = nullptr;

    readData(books, size, "books.bin");

    while (flag) {
        choice = Menu();
        switch (choice) {
        case 'A':
        case 'a':
            addBook(books, size);
            cout << "New book added successfully.\n";
            break;
        case 'U':
        case 'u':
            updateBook(books, size);
            break;
        case 'D':
        case 'd':
            deleteBook(books, size);
            cout << "Book deleted successfully.\n";
            break;
        case 'F':
        case 'f':
            findBook(books, size);
            break;
        case 'P':
        case 'p':
            printBooks(books, size);
            break;
        case 'X':
        case 'x':
            exportToCSV(books, size);
            cout << "Data exported to books.csv successfully.\n";
            break;
        case 'E':
        case 'e':
            writeData(books, size);
            delete[] books;
            flag = false;
            break;
        default:
            cout << "\nIncorrect Option" << endl;
            choice = Menu();
            break;
        }
    }
    return 0;

}

char Menu() {
    char choice;
    cout << "\t\t\nBook Management System" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t\tAdd New Book\t\t:\t[A/a]" << endl;
    cout << "\t\tUpdate Book Info\t:\t[U/u]" << endl;
    cout << "\t\tDelete Book\t\t:\t[D/d]" << endl;
    cout << "\t\tFind Book\t\t:\t[F/f]" << endl;
    cout << "\t\tPrint All Books\t\t:\t[P/p]" << endl;
    cout << "\t\tExport to CSV\t\t:\t[X/x]" << endl;
    cout << "\t\tExit\t\t\t:\t[E/e]" << endl;
    cout << "\t\t\tEnter Option\t:\t";
    cin >> choice;
    return choice;
}

void addBook(Book*& books, int& size) {
    Book newBook;
    cin >> newBook;

    for (int i = 0; i < size; ++i) {
        if (books[i].getId() == newBook.getId()) {
            cout << "Book with this ID already exists.\n";
            return;
        }
    }
    while (newBook.getQuantity() < 0 || newBook.getPrice() < 0) {
        cout << "The Price or Quantity cannot be a negative number. Enter again: " << endl;
        cin >> newBook;
    }

    Book* temp = new Book[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = books[i];
    }
    temp[size] = newBook;
    delete[] books;
    books = temp;
    size++;
}

void updateBook(Book* books, int size) {
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;
    for (int i = 0; i < size; ++i) {
        if (books[i].getId() == id) {
            cout << "Enter new details for the book:\n";
            cin >> books[i];
            cout << "Book updated successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void deleteBook(Book*& books, int& size) {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (books[i].getId() == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    Book* temp = new Book[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = books[i];
        }
    }
    delete[] books;
    books = temp;
    size--;
}

void findBook(Book* books, int size) {
    int id;
    cout << "Enter Book ID to find: ";
    cin >> id;
    for (int i = 0; i < size; ++i) {
        if (books[i].getId() == id) {
            cout << books[i];
            return;
        }
    }
    cout << "Book not found.\n";
}

void printBooks(Book* books, int size) {
    if (size <= 0 || books == nullptr) {
        cout << "No books available.\n";
    }
    else {
        cout << "\nAll Books:\n";
        for (int i = 0; i < size; ++i) {
            cout << books[i] << endl;
        }
    }
}

void writeData(Book* books, int size) {
    fstream file("books.bin", ios::binary | ios::out | ios::app);
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }

    file.write((char*)&size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        file.write((char*)&books[i], sizeof(Book));
    }

    if (!file) {
        cout << "Error writing data to file.\n";
    }
    else {
        cout << "All data saved to file.\n";
    }

    file.close();
}

// Function to read the binary data
void readData(Book*& books, int& size, const string& filename) {
    fstream file(filename, ios::binary | ios::in);
    if (!file) {
        size = 0;
        books = nullptr;
        return;
    }

    int newSize;
    file.read((char*)&newSize, sizeof(int));

    if (newSize > 0) {
        Book* tempBooks = new Book[newSize];
        for (int i = 0; i < newSize; ++i) {
            file.read((char*)&tempBooks[i], sizeof(Book));
        }

        // If successful, delete the old array and assign the new one
        delete[] books;
        books = tempBooks;
        size = newSize;
    }
    else {
        delete[] books;
        books = nullptr;
        size = 0;
    }
    file.close();
}



// Function to export data to CSV file
void exportToCSV(Book* books, int size) {
    if (size <= 0) {
        cout << "No data to export.\n";
        return;
    }

    fstream csvFile("books.csv", ios::in | ios::out | ios::app);
    if (!csvFile) {
        cout << "Failed to open CSV file for writing.\n";
        return;
    }

    csvFile << "ID,Title,Author,Quantity,Price\n";
    for (int i = 0; i < size; ++i) {
        csvFile << books[i].getId() << ','
            << books[i].getTitle() << ','
            << books[i].getAuthor() << ','
            << books[i].getQuantity() << ','
            << books[i].getPrice() << '\n';
    }
    csvFile.close();
    cout << "Data exported to books.csv successfully.\n";
}

