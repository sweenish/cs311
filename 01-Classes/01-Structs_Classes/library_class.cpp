#include <iomanip>
#include <iostream>
#include <string>

class Book {
public:
    Book();
    Book(std::string a, std::string t, int y, bool r);
    std::string getAuthor() const;
    std::string getTitle() const;
    int getYear() const;
    bool isRead() const;
    void markRead();
    friend bool operator==(const Book& left, const Book& right);
private:
    std::string author;
    std::string title;
    int year;
    bool read;
};

class Library {
public:
    Library();
    void addBook(Book book);
    Book getBook(Book book);
    void removeBook(Book book);
    void markRead(Book book);
    void print();
    const Book operator[](int i) const;
private:
    Book library[10];
    int numBooksInLibrary;

    bool isInLibrary(Book book);
    int getLocation(Book book);
};

int main()
{
    Library library;
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

        library.addBook(Book(author, title, year, read));
    }

    std::cout << std::endl;
    library.print();

    std::cout << "\nRemoving a book\n\n";
    library.removeBook(library[0]);
    library.print();

    std::cout << "\nMarking the remaining book as read\n\n";
    library.markRead(library[0]);
    library.print();

    return 0;
}


// Book Class
Book::Book()
    : author(std::string())
    , title(std::string())
    , year(0)
    , read(0)
{
}

Book::Book(std::string a, std::string t, int y, bool r)
    : author(a)
    , title(t)
    , year(y)
    , read(r)
{
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getTitle() const
{
    return title;
}

int Book::getYear() const
{
    return year;
}

bool Book::isRead() const
{
    return read;
}

void Book::markRead()
{
    read = true;
}

bool operator==(const Book& left, const Book& right)
{
    if (left.author == right.author && left.title == right.title && left.year == right.year)
        return true;
    else
        return false;
}


// Library Class
Library::Library()
    : numBooksInLibrary(0)
{
}

void Library::addBook(Book book)
{
    library[numBooksInLibrary] = book;
    numBooksInLibrary++;
}

Book Library::getBook(Book book)
{
    if (isInLibrary(book)) {
        return library[getLocation(book)];
    } else {
        std::cout << "Book not found.\n";
        return Book();
    }
}

void Library::removeBook(Book book)
{
    if ( !(isInLibrary(book)) )
        return;
    
    int loc = getLocation(book);
    if (loc < (numBooksInLibrary - 1)) {
        for (int i = loc; i < numBooksInLibrary; i++) {
            library[i] = library[i + 1];
        }
    }
    numBooksInLibrary--;
}

void Library::markRead(Book book)
{
    if ( !(isInLibrary(book)) )
        return;
    
    library[getLocation(book)].markRead();
}

void Library::print()
{
    char prev = std::cout.fill('.');
    for (int i = 0; i < numBooksInLibrary; i++) {
        std::cout << "Book #" << (i + 1) << "\n";
        std::cout << std::setw(12) << std::left << "Title" << library[i].getTitle() << "\n";
        std::cout << std::setw(12) << std::left << "Author" << library[i].getAuthor() << "\n";
        std::cout << std::setw(12) << std::left << "Published" << library[i].getYear() << "\n";
        std::cout << std::setw(12) << std::left << "Have Read";
        if (library[i].isRead())
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << "\n\n";
    }
    std::cout.fill(prev);
}

const Book Library::operator[](int i) const
{
    if (i >= 0 && i < numBooksInLibrary) {
        return library[i];
    } else {
        std::cout << "Invalid location.\n";
        return Book();
    }
}

bool Library::isInLibrary(Book book)
{
    for (int i = 0; i < numBooksInLibrary; i++)
        if (library[i].getAuthor() == book.getAuthor() 
                                        && library[i].getTitle() == book.getTitle() 
                                        && library[i].getYear() == book.getYear())
            return true;
            
    
    return false;
}

int Library::getLocation(Book book)
{
    for (int i = 0; i < numBooksInLibrary; i++) {
        if (library[i].getAuthor() == book.getAuthor() 
                                        && library[i].getTitle() == book.getTitle() 
                                        && library[i].getYear() == book.getYear()) {
            return i;
        }
    }

    return -1;
}
