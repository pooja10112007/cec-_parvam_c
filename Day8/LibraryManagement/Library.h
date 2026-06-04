#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Library {
    private:
        vector<Book> books;
        string filename;
        
        void loadFromFile();
        void saveToFile();
    
    public:
        Library(const string& file = "books.txt");
        
        void addBook(const Book& book);
        void removeBook(int id);
        void issueBook(int id);
        void returnBook(int id);
        void searchByTitle(const string& title) const;
        void searchByAuthor(const string& author) const;
        void displayAllBooks() const;
        void displayAvailableBooks() const;
        void displayIssuedBooks() const;
};

#endif