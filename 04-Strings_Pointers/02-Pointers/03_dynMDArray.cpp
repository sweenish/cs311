#include <iostream>
#include <iomanip>

int main()
{
	typedef int* intPtr;
	int rows, columns;

	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of columns: ";
	std::cin >> columns;

	// Typedef Method of Multi-Dimensional Array
	intPtr *first = new intPtr[rows];  // Using a typedef to declare an array of arrays
	for (int i = 0; i < rows; i++)  // Expanding each row to get columns
		first[i] = new int[columns];

	for (int i = 0; i < rows; i++)  // Placing values in array
		for (int j = 0; j < columns; j++)
			first[i][j] = (i * columns) + j + 1;


	for (int i = 0; i < rows; i++) {  // Finally, printing the array
		for (int j = 0; j < columns; j++) {
			std::cout << std::setw(4) << first[i][j];
		}
		std::cout << "\n";
	}  

	std::cout << "\n\n";

	// Without a typedef
	int **second = new int*[rows];
	for (int i = 0; i < rows; i++)
		second[i] = new int[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			second[i][j] = (i * columns) + j + 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << std::setw(4) << second[i][j];
		}
		std::cout << "\n";
	}

	for (int i = 0; i < rows; i++) {
		delete [] first[i];
		delete [] second[i];
	}
	delete [] first;
	delete [] second;
	return 0;
}