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
void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }
void Book::setISBN(const string& i) { isbn = i; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerId(const string& id) { borrowerId = id; }

// Convertit un livre en ligne de texte pour sauvegarde
string Book::toFileFormat() const {
    // Format : titre|auteur|isbn|disponible|borrowerId
    stringstream ss;
    ss << title << "|" << author << "|" << isbn << "|" << isAvailable << "|" << borrowerId;
    return ss.str();
}

// Méthodes
void Book::checkOut(const string& borrowerId) {
    if (isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    } else {
        cout << "Le livre est déjà emprunté." << endl;
    }
}

// Reconstruit un livre à partir d'une ligne de texte
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    string availableStr;
    getline(ss, availableStr, '|');
    isAvailable = (availableStr == "1" || availableStr == "true");
    getline(ss, borrowerId, '|');
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    return title + " | " + author + " | " + isbn + (isAvailable ? " | Disponible" : " | Emprunté");
}
