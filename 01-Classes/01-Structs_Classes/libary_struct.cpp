#include <iomanip>
#include <iostream>
#include <string>

struct Book {
    std::string author;
    std::string title;
    int year;
    bool read;
};

// Array that represents library
Book library[10];
int numBooksInLibrary = 0;

// Functions to control library
Book makeBook(std::string a, std::string t, int y, bool r);
void markRead(Book &book);
// void markRead(bool &r);   markRead(book.read);
bool isInLibrary(Book book);
int findBook(Book book);
void removeBook(Book book);
void printLibrary();

int main()
{
    for (int i = 0; i < 2; i++) {
        std::string title;
        std::string author;
        int year;
        bool read;

        std::cout << "Let's add a book to the library!\n";
        std::cout << "What's the title? ";
        getline(std::cin, title);
        std::cout << "Who wrote it? ";
        getline(std::cin, author);
        std::cout << "When was it published? ";
        std::cin >> year;
        std::cin.get();
        std::cout << "Have you read it already? (Type 1 for yes, 0 for no)";
        std::cin >> read;
        std::cin.get();
        std::cout << std::endl;

        library[i] = makeBook(author, title, year, read);
        numBooksInLibrary++;
    }

    std::cout << std::endl;
    printLibrary();

    std::cout << "\nRemoving a book\n\n";
    removeBook(library[0]);
    printLibrary();

    std::cout << "\nMarking the remaining book as read\n\n";
    markRead(library[0]);
    printLibrary();

    return 0;
}

Book makeBook(std::string a, std::string t, int y, bool r)
{
    Book book;
    book.author = a;
    book.title = t;
    book.year = y;
    book.read = r;

    return book;
}

void markRead(Book &book)
{
    book.read = true;
}

bool isInLibrary(Book book)
{
    for (int i = 0; i < numBooksInLibrary; i++)
        if (library[i].author == book.author && library[i].title == book.title && library[i].year == book.year)
            return true;
    
    return false;
}

int findBook(Book book)
{
    for (int i = 0; i < numBooksInLibrary; i++) {
        if (library[i].author == book.author && library[i].title == book.title && library[i].year == book.year) {
            return i;
        }
    }

    return -1;
}

void removeBook(Book book)
{
    if ( !(isInLibrary(book)) )
        return;
    
    int location = findBook(book);

    if (location < (numBooksInLibrary - 1)) {
        for (int i = location; i < numBooksInLibrary; i++) {
            library[i] = library[i + 1];
        }
    }
    numBooksInLibrary--;
}

void printLibrary()
{
    char prev = std::cout.fill('.');
    for (int i = 0; i < numBooksInLibrary; i++) {
        std::cout << "Book #" << (i + 1) << "\n";
        std::cout << std::setw(12) << std::left << "Title" << library[i].title << "\n";
        std::cout << std::setw(12) << std::left << "Author" << library[i].author << "\n";
        std::cout << std::setw(12) << std::left << "Published" << library[i].year << "\n";
        std::cout << std::setw(12) << std::left << "Have Read";
        if (library[i].read)
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << "\n\n";
    }
    std::cout.fill(prev);
}