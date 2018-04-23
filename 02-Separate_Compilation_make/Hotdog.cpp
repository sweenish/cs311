#include "Hotdog.hpp"

int HotdogStand::totalSales = 0;    //
int HotdogStand::numStands = 0;     // Static initialization must occur outside of class

HotdogStand::HotdogStand()
{ 
    numStands++;
}

void HotdogStand::sellHotdog()
{
    standSales++;
    totalSales++;
}