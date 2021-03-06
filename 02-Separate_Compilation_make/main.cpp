#include <iostream>
#include <random>
#include "Hotdog.hpp"

int main(void)
{
    HotdogStand first, second, third, fourth;
    std::random_device rd;  // True random number generator, slow
    std::mt19937 generator(rd());  // Mersenne Twister pseudo-random number generator, fast, seeded by true random number
    std::uniform_int_distribution<int> uniDist(1, 15); // Random numbers w/ uniform distribution in range [1, 15]
    
    int firstSales = uniDist(generator);
    int secondSales = uniDist(generator);
    int thirdSales = uniDist(generator);
    int fourthSales = uniDist(generator);
    
    for (auto i = 1; i <= firstSales; ++i) {
        first.sellHotdog();
    }
    
    for (auto i = 1; i <= secondSales; ++i) {
        second.sellHotdog();
    }
    
    for (auto i = 1; i <= thirdSales; ++i) {
        third.sellHotdog();
    }
    
    for (auto i = 1; i <= fourthSales; ++i) {
        fourth.sellHotdog();
    }
    
    std::cout << "Results:\n  First stand sales:\t" << first.getSales() << "\n";
    std::cout << "  Second stand sales:\t" << second.getSales() << "\n";
    std::cout << "  Third stand sales:\t" << third.getSales() << "\n";
    std::cout << "  fourth stand sales:\t" << fourth.getSales() << "\n";
    std::cout << "Total stands: " << HotdogStand::getNumStands() << "\n";
    std::cout << "Total hotdogs sold: " << HotdogStand::getTotalSales() << "\n";
    
    return 0;
}