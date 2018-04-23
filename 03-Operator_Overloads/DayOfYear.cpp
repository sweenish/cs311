#include <cmath>
#include <limits>
#include <iostream>
#include <string>
#include "DayOfYear.hpp"

DayOfYear::DayOfYear(int month, int day) : month(month), day(day)
{
    testDate();
}

DayOfYear::DayOfYear(int month) : month(month), day(1)
{
    testDate();
}

DayOfYear::DayOfYear() : month(1), day(1)
{
    setOrdinal();
}

int DayOfYear::getMonthNumber() const { return month; }

int DayOfYear::getDay() const { return day; }

int DayOfYear::getOrdinal() const { return ordinal; }

void DayOfYear::testDate()
{
    if (month < 1 || month > 12) {
        std::cout << month << " is an invalid month. Resetting...\n";
        month = 1;
    }

    if (day < 1) {
        std::cout << day << " is invalid. Resetting...\n";
        day = 1;
    }

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31) {
            std::cout << day << " is not valid for month " << month << ". Resetting...\n";
            day = 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30) {
            std::cout << day << " is not valid for month " << month << ". Resetting...\n";
            day = 1;
        }
        break;
    case 2:
        if (day > 29) {
            std::cout << day << " is not valid for month " << month << ". Resetting...\n";
            day = 1;
        }
        break;
    default:
        day = 1;
    }

    setOrdinal();
}

void DayOfYear::setOrdinal()
{
    int adjustedMonth = month % 12;
    if (adjustedMonth == 0)
        adjustedMonth = 12;

    switch(adjustedMonth) {
    case 1:
        ordinal = day;
        break;
    case 2:
        ordinal = 31 + day;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        ordinal = 59 + floor((30.6 * (adjustedMonth + 1)) + day - 122);
        break; // ^^^ Because day can still be larger than 31, ordinal day may be > 365
    default:
        std::cout << "ERROR in private function setOrdinal\n";
    }

    if (ordinal > 365)
        ordinal %= 365;
    if (ordinal == 0)
        // Accounts for numbers like 730, which is still Dec. 31
        ordinal = 365;
}

void DayOfYear::fixDate()
{
    // Ordinal <= 365 at this point
    if (ordinal <= 31) {            // January
        month = 1;
        day = ordinal;
    } else if (ordinal <= 59) {     // February
        month = 2;
        day = ordinal - 31;
    } else if (ordinal <= 90) {     // March
        month = 3;
        day = ordinal - 59;
    } else if (ordinal <= 120) {    // April
        month = 4;
        day = ordinal - 90;
    } else if (ordinal <= 151) {    // May
        month = 5;
        day = ordinal - 120;
    } else if (ordinal <= 181) {    // June
        month = 6;
        day = ordinal - 151;
    } else if (ordinal <= 212) {    // July
        month = 7;
        day = ordinal - 181;
    } else if (ordinal <= 243) {    // August
        month = 8;
        day = ordinal - 212;
    } else if (ordinal <= 273) {    // September
        month = 9;
        day = ordinal - 243;
    } else if (ordinal <= 304) {    // October
        month = 10;
        day = ordinal - 273;
    } else if (ordinal <= 334) {    // November
        month = 11;
        day = ordinal - 304;
    } else {                        // December
        month = 12;
        day = ordinal - 334;
    }
}

/*===MEMBER OPERATOR OVERLOADS===*/
const DayOfYear DayOfYear::operator -() const
{
    DayOfYear newDate;
    newDate.ordinal = 365 - (ordinal - 1);
    newDate.fixDate();

    return newDate;
}

DayOfYear& DayOfYear::operator ++()
{
    ++ordinal;
    fixDate();

    return *this;
}

const DayOfYear DayOfYear::operator++(int)
{
    DayOfYear temp = *this;
    ++(*this);

    return temp;
}

DayOfYear& DayOfYear::operator --()
{
    --ordinal;
    fixDate();

    return *this;
}

const DayOfYear DayOfYear::operator --(int)
{
    DayOfYear temp = *this;
    --(*this);

    return temp;
}

int DayOfYear::operator [](int index) const
{
    switch(index) {
    case 1:
        return month;
    case 2:
        return day;
    case 3:
        return ordinal;
    default:
        return -1;
    }
}
/*===NON-MEMBER OPERATOR OVERLOADS===*/
const DayOfYear operator +(const DayOfYear& left, const DayOfYear& right)
{
    DayOfYear sum;
    sum.month = left.month + right.month;
    sum.day = left.day + right.day;
    sum.setOrdinal();
    sum.fixDate();

    return sum;
}

const DayOfYear operator +(const DayOfYear& left, int right)
{
    DayOfYear sum = left;
    sum.ordinal += right;
    sum.fixDate();

    return sum;
}

const DayOfYear operator +(int left, const DayOfYear& right)
{
    return (right + left);
}

int operator -(const DayOfYear& left, const DayOfYear& right)
{
    if (left.getOrdinal() <= right.getOrdinal()) {
        std::cout << "ERROR: left operand must be later date than right operand.\n";
        return 0;
    }

    return (left.getOrdinal() - right.getOrdinal());
}

bool operator ==(const DayOfYear& left, const DayOfYear& right)
{
    return (((left.month == right.month) && (left.day == right.day)) && (left.ordinal == right.ordinal));
}

bool operator <(const DayOfYear& left, const DayOfYear& right)
{
    return (left.ordinal < right.ordinal);
}

bool operator >(const DayOfYear& left, const DayOfYear& right)
{
    return (left.ordinal > right.ordinal);
}

std::ostream& operator <<(std::ostream& outStream, const DayOfYear& right)
{
    switch (right.month) {
    case 1:
        outStream << "January ";
        break;
    case 2:
        outStream << "February ";
        break;
    case 3:
        outStream << "March ";
        break;
    case 4:
        outStream << "April ";
        break;
    case 5:
        outStream << "May ";
        break;
    case 6:
        outStream << "June ";
        break;
    case 7:
        outStream << "July ";
        break;
    case 8:
        outStream << "August ";
        break;
    case 9:
        outStream << "September ";
        break;
    case 10:
        outStream << "October ";
        break;
    case 11:
        outStream << "November ";
        break;
    case 12:
        outStream << "December ";
        break;
    }
    outStream << right.day;

    return outStream;
}

std::istream& operator >>(std::istream& inStream, DayOfYear& right)
{
    std::string input;
    inStream >> input;
    inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::size_t slashLoc = input.find_first_of("/");
    if (slashLoc != 1 && slashLoc != 2) {
        std::cout << "Invalid input entered. Defaulting to Jan. 1\n";
        input = "1/1";
        slashLoc = input.find_first_of("/");    // String processing occurs next no matter what,
    }                                           // slashLoc needs to be accurate

    /* Getting to this point means that we are processing a string where the 
     * slash was in a correct position. That does not mean the other characters are valid
	 */
    std::string::size_type size;    // Used to verify month/day sections are wholly numbers

	std::string month = input.substr(0, slashLoc);
	int monthNum = std::stoi(month, &size);
	if (size != slashLoc)   // TRUE indicates that the month portion is garbage
        monthNum = 1;       // Set it to a default value
        
	std::string day = input.substr(slashLoc + 1, std::string::npos);
	int dayNum = std::stoi(day, &size);
	if (size != day.length())
        dayNum = 1;
        
    // Getting this far means the input is in num/num format; it may still be invalid
    right.testDate();

    return inStream;
}
