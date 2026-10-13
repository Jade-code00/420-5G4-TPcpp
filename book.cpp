#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructeurs
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }

// Méthodes
void Book::checkOut(const string& borrowerId) {
    if (isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    } else {
        cout << "Le livre est déjà emprunté." << endl;
    }
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    return title + " | " + author + " | " + isbn + 
            (isAvailable ? " | Disponible" : " | Emprunté par" + borrowerId);
}


// Sauvegarde / chargement
string Book::toFileFormat() const {
    // Format : title|author|isbn|isAvailable|borrowerId
    stringstream ss;
    ss << title << "|" << author << "|" << isbn << "|" 
        << isAvailable << "|" << borrowerId;
    return ss.str();
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availableStr;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availableStr, '|');
    getline(ss, borrowerId, '|');
    
    isAvailable = (availableStr == "1" || availableStr == "true");