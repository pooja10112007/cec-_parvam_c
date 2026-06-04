#include "unified.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// =================== BOOK CLASS IMPLEMENTATION ===================

Book::Book() : id(0), title("N/A"), author("N/A"), year(0), isIssued(false) {}

Book::Book(int id, const string& title, const string& author, int year) 
    : id(id), title(title), author(author), year(year), isIssued(false) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::getIsIssued() const { return isIssued; }

void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }

void Book::setYear(int year) {
    if (year < 0 || year > 2025) {
        throw invalid_argument("Invalid year!");
    }
    this->year = year;
}

void Book::issue() {
    if (isIssued) {
        throw runtime_error("Book is already issued!");
    }
    isIssued = true;
}

void Book::returnBook() {
    if (!isIssued) {
        throw runtime_error("Book was not issued!");
    }
    isIssued = false;
}

void Book::display() const {
    cout << left << setw(5) << id
         << setw(30) << title
         << setw(20) << author
         << setw(10) << year
         << setw(10) << (isIssued ? "Issued" : "Available") << endl;
}

string Book::toFileString() const {
    return to_string(id) + "|" + title + "|" + author + "|" + 
           to_string(year) + "|" + (isIssued ? "1" : "0");
}

Book Book::fromFileString(const string& line) {
    stringstream ss(line);
    string token;
    
    getline(ss, token, '|'); int id = stoi(token);
    getline(ss, token, '|'); string title = token;
    getline(ss, token, '|'); string author = token;
    getline(ss, token, '|'); int year = stoi(token);
    getline(ss, token, '|'); bool issued = (token == "1");
    
    Book book(id, title, author, year);
    if (issued) book.issue();
    return book;
}

// =================== LIBRARY CLASS IMPLEMENTATION ===================

Library::Library(const string& file) : filename(file) {
    loadFromFile();
}

void Library::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile) return;
    
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            try {
                books.push_back(Book::fromFileString(line));
            }
            catch (const exception& e) {
                cerr << "Error loading record: " << e.what() << endl;
            }
        }
    }
    inFile.close();
}

void Library::saveToFile() {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Cannot open file for writing!");
    }
    
    for (const auto& book : books) {
        outFile << book.toFileString() << endl;
    }
    outFile.close();
}

void Library::addBook(const Book& book) {
    for (const auto& b : books) {
        if (b.getId() == book.getId()) {
            throw invalid_argument("Book with this ID already exists!");
        }
    }
    books.push_back(book);
    saveToFile();
    cout << "Book added successfully!" << endl;
}

void Library::removeBook(int id) {
    auto it = remove_if(books.begin(), books.end(),
        [id](const Book& b) { return b.getId() == id; });
    
    if (it == books.end()) {
        throw invalid_argument("Book not found!");
    }
    
    books.erase(it, books.end());
    saveToFile();
    cout << "Book removed successfully!" << endl;
}

void Library::issueBook(int id) {
    for (auto& book : books) {
        if (book.getId() == id) {
            book.issue();
            saveToFile();
            cout << "Book issued successfully!" << endl;
            return;
        }
    }
    throw invalid_argument("Book not found!");
}

void Library::returnBook(int id) {
    for (auto& book : books) {
        if (book.getId() == id) {
            book.returnBook();
            saveToFile();
            cout << "Book returned successfully!" << endl;
            return;
        }
    }
    throw invalid_argument("Book not found!");
}

void Library::searchByTitle(const string& title) const {
    cout << left << setw(5) << "ID" << setw(30) << "Title" 
         << setw(20) << "Author" << setw(10) << "Year" 
         << setw(10) << "Status" << endl;
    cout << string(75, '-') << endl;
    
    bool found = false;
    for (const auto& book : books) {
        string bookTitle = book.getTitle();
        string searchTitle = title;
        transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
        transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);
        
        if (bookTitle.find(searchTitle) != string::npos) {
            book.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No books found with title containing \"" << title << "\"" << endl;
    }
}

void Library::searchByAuthor(const string& author) const {
    cout << left << setw(5) << "ID" << setw(30) << "Title" 
         << setw(20) << "Author" << setw(10) << "Year" 
         << setw(10) << "Status" << endl;
    cout << string(75, '-') << endl;
    
    bool found = false;
    for (const auto& book : books) {
        string bookAuthor = book.getAuthor();
        string searchAuthor = author;
        transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        transform(searchAuthor.begin(), searchAuthor.end(), searchAuthor.begin(), ::tolower);
        
        if (bookAuthor.find(searchAuthor) != string::npos) {
            book.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No books found by author \"" << author << "\"" << endl;
    }
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        cout << "No books in the library." << endl;
        return;
    }
    
    cout << "\n" << left << setw(5) << "ID" << setw(30) << "Title" 
         << setw(20) << "Author" << setw(10) << "Year" 
         << setw(10) << "Status" << endl;
    cout << string(75, '-') << endl;
    
    for (const auto& book : books) {
        book.display();
    }
    cout << "Total books: " << books.size() << endl;
}

void Library::displayAvailableBooks() const {
    bool found = false;
    
    cout << "\nAvailable Books:" << endl;
    cout << left << setw(5) << "ID" << setw(30) << "Title" 
         << setw(20) << "Author" << setw(10) << "Year" << endl;
    cout << string(65, '-') << endl;
    
    for (const auto& book : books) {
        if (!book.getIsIssued()) {
            book.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No books currently available." << endl;
    }
}

void Library::displayIssuedBooks() const {
    bool found = false;
    
    cout << "\nIssued Books:" << endl;
    cout << left << setw(5) << "ID" << setw(30) << "Title" 
         << setw(20) << "Author" << setw(10) << "Year" << endl;
    cout << string(65, '-') << endl;
    
    for (const auto& book : books) {
        if (book.getIsIssued()) {
            book.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No books currently issued." << endl;
    }
}
