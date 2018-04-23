#ifndef HOTDOG_HPP
#define HOTDOG_HPP

class HotdogStand {
public:
    HotdogStand();
    int getSales() const { return standSales; }
    static int getTotalSales() { return totalSales; }
    static int getNumStands() { return numStands; }
    void sellHotdog();
private:
    int standSales = 0;
    static int totalSales;
    static int numStands;
};

#endif