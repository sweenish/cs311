#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>
#include "DayOfYear.hpp"

void showTest(std::string testing, std::string regExpect, std::string ecExpect, std::stringstream& result);
void flushStream(std::stringstream& ss);

class DayOfYearTest : public DayOfYear {
public:
    DayOfYearTest();
    DayOfYearTest(int month);
    DayOfYearTest(int month, int day);
    bool runTest();
    DayOfYearTest& operator =(const DayOfYear& r);
private:
    //
};

int main()
{
    DayOfYear one(10, 31), two(12, 30), three(5), four(50, 50), result;
    int diff;
    bool test;
    std::stringstream sstream;

    // Addition of Two Objects
    result = three + two;
    sstream << result;
    showTest("Addition (2 obj)", "June 1", "May 31", sstream);
    
    // Addition of Object and int
    result = three + 19;
    sstream << result;
    showTest("Addition (obj + int)", "May 20", "May 20", sstream);

    // Addition of int and Object
    result = 19 + three;
    sstream << result;
    showTest("Addition (int + obj)", "May 20", "May 20", sstream);

    // Subtraction
    diff = one - three;
    sstream << diff;
    showTest("Subtraction", "150", "183", sstream);

    // Negation
    result = -one;
    sstream << result;
    showTest("Negation", "March 30", "March 3", sstream);

    // Equality (TRUE)
    test = (one == one);
    sstream << test;
    showTest("Equality (TRUE)", "1", "1", sstream);

    // Equality (FALSE)
    test = (one == two);
    sstream << test;
    showTest("Equality (FALSE)", "0", "0", sstream);

    // Less than (TRUE)
    test = (four < two);
    sstream << test;
    showTest("Less than (TRUE)", "1", "1", sstream);

    // Less than (FALSE)
    test = (two < four);
    sstream << test;
    showTest("Less than (FALSE)", "0", "0", sstream);

    // Greater than (TRUE)
    test = (two > four);
    sstream << test;
    showTest("Greater than (TRUE)", "1", "1", sstream);

    // Greater than (FALSE)
    test = (four > two);
    sstream << test;
    showTest("Greater than (TRUE)", "0", "0", sstream);

    // Pre-fix increment
    sstream << two; sstream << " incremented is " << (++two);
    showTest("Pre-fix ++", "December 30 incremented is January 1", "December 30 incremented is December 31", sstream);

    // Post-fix increment
    sstream << (two++); sstream << " incremented is " << two;
    showTest("Post-fix ++", "January 1 incremented is January 2", "December 31 incremented is January 1", sstream);

    // Pre-fix decrement
    sstream << two; sstream << " incremented is " << (--two);
    showTest("Pre-fix --", "January 2 decremented is January 1", "January 1 decremented is December 31", sstream);

    // Post-fix decrement
    sstream << (two--); sstream << " incremented is " << two;
    showTest("Post-fix --", "January 1 decremented is December 30", "December 31 decremented is December 30", sstream);
    
    // Insertion operator <<
    result = four + three;
    sstream << four << " + " << three << " = " << result;
    showTest("Insertion operator <<", "January 1 + May 1 = June 2", "January 1 + May 1 = June 2", sstream);

    // [ ]
    sstream << three << " is " << three[1] << "/" << three[2] << ", day number " << three[3] << " of the year.";
    showTest("[ ]", "May 1 is 5/1, day number 121 of the year.", "May 1 is 5/1, day number 121 of the year.", sstream);

    // Extraction operator >>
    std::cout << "======Extraction operator >>======";
    std::cout << "\nPlease enter a new date: ";
    std::cin >> one;
    std::cout << "\nPlease enter a new date: ";
    std::cin >> two;
    std::cout << "\nPlease enter a new date: ";
    std::cin >> three;
    std::cout << "\nPlease enter a new date: ";
    std::cin >> four;
    std::cout << "\nPlease enter a new date: ";
    std::cin >> result;

    std::cout << "\nExpected output for regular and extra credit\n"
            << "NOTE: Should see an error message on final input attempt\n"
            << "October 20\nNovember 5\nJuly 30\nSeptember 1\nJanuary 1\n\n";
    std::cout << "Actual Output\n" << one << "\n" << two << "\n" << three << "\n" << four << "\n" << result << "\n";
    
    flushStream(sstream);

    return 0;
}

void showTest(std::string testing, std::string regExpect, std::string ecExpect, std::stringstream& result)
{
    std::cout << "======" << testing << "======" << std::endl;
    std::cout << std::setw(21) << "Expected Output: " << regExpect << std::endl;
    std::cout << std::setw(21) << "EC Expected Output: " << ecExpect << std::endl;
    std::cout << std::setw(21) << "Actual Output: " << result.str() << std::endl << std::endl;
    flushStream(result);
}

void flushStream(std::stringstream& ss)
{
    ss.str(std::string(""));
    ss.clear();
}

DayOfYearTest::DayOfYearTest() : DayOfYear()
{ }

DayOfYearTest::DayOfYearTest(int month) : DayOfYear(month)
{ }

DayOfYearTest::DayOfYearTest(int month, int day) : DayOfYear(mont, day)
{ }

bool DayOfYearTest::runTest();
DayOfYearTest& DayOfYearTest::operator =(const DayOfYear& r);