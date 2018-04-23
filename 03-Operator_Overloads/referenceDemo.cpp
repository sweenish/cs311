#include <iostream>

int& preIncrement(int& x)
{
	return ++x;
}

int main()
{
	int y = 2;

	preIncrement(y);
	std::cout << y << "\n";
	preIncrement(y) = 7;
	std::cout << y << "\n";

	return 0;
}