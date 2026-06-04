#ifndef LIBRARY_MANAGEMENT_SYSTEM_HPP
#define LIBRARY_MANAGEMENT_SYSTEM_HPP

#include <string>
#include <vector>
#include <iostream>

// Forward declaration
class Book;

// Book class definition
class Book {
private:
    int id;
    std::string title;
    std::string author;
    int year;
    bool isIssued;

public:
    Book();
    Book(int id, const std::string& title, const std::string& author, int year);
    
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool getIsIssued() const;
    
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setYear(int year);
    void issue();
    void returnBook();
    
    void display() const;
    std::string toFileString() const;
    static Book fromFileString(const std::string& line);
};

// Library class definition
class Library {
private:
    std::vector<Book> books;
    std::string filename;
    
    void loadFromFile();
    void saveToFile();

public:
    Library(const std::string& file = "books.txt");
    
    void addBook(const Book& book);
    void removeBook(int id);
    void issueBook(int id);
    void returnBook(int id);
    void searchByTitle(const std::string& title) const;
    void searchByAuthor(const std::string& author) const;
    void displayAllBooks() const;
    void displayAvailableBooks() const;
    void displayIssuedBooks() const;
};

#endif // LIBRARY_MANAGEMENT_SYSTEM_HPP
