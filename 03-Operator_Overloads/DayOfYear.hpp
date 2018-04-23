#ifndef DAYOFYEAR
#define DAYOFYEAR

class DayOfYear {
public:
    DayOfYear(int month, int day);
    DayOfYear(int month);
    DayOfYear();
    void output() const;
    int getMonthNumber() const;
    int getDay() const;
    int getOrdinal() const;
    const DayOfYear operator -() const;
    DayOfYear& operator ++();
    const DayOfYear operator++(int);
    DayOfYear& operator --();
    const DayOfYear operator --(int);
    int operator [](int index) const;
    friend const DayOfYear operator +(const DayOfYear& left, const DayOfYear& right);
    friend const DayOfYear operator +(const DayOfYear& left, int right);
    friend const DayOfYear operator +(int left, const DayOfYear& right);
    friend bool operator ==(const DayOfYear& left, const DayOfYear& right);
    friend bool operator <(const DayOfYear& left, const DayOfYear& right);
    friend bool operator >(const DayOfYear& left, const DayOfYear& right);
    friend std::ostream& operator <<(std::ostream& outStream, const DayOfYear& right);
    friend std::istream& operator >>(std::istream& inStream, DayOfYear& right);
private:
    void testDate();    // Resets out of bounds month or day to 1
    void setOrdinal();  // No constructor for ordinal day, must be set after creation
    void fixDate();     // Adjusts date after an operation
    int month;
    int day;
    int ordinal;
};

// Non-member, non-friend operator overload
int operator -(const DayOfYear& left, const DayOfYear& right);
#endif
