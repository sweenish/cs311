#include <iostream>

/*
 * These r-value snippets of code just exist to demonstrate properties.
 * These are not practical uses
 */

int main()
{
    int &&rref = 5; // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
    rref = 10;      // That's why we're able to re-assign the value
    std::cout << rref;
 
    return 0;
}