#include <iostream>
#include <random>


int main()
{
	int size;
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(1, 1000);
	std::cout << "Enter an array size: ";
	std::cin >> size;

	// The pointer dynArray is our only access to the heap-allocated array
	int *dynArray = new int[size];

	for (int i = 0; i < size; i++)
		dynArray[i] = dist(engine);	// [] only works because compiler knows
									// dynArray points to an array

	for (int i = 0; i < size; i++)
		std::cout << *(dynArray + i) << std::endl;  // Utilizes pointer arithmetic

	// Because it was an array, our delete command changes slightly, NOTE the order
	delete [] dynArray;
	dynArray = nullptr;		// The C++11 nullptr is more robust and less prone to edge-case errors than NULL

	return 0;
}