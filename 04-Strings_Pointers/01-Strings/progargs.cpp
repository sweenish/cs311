#include <iostream>
#include <cstdlib>
#include <string>

// Will show how the program should be used, then exit
void printUsage(char arg[]);

// The names are not mandatory, but are the popular convention
// The types, and their order, is mandatory
// char *argv[] == char **argv
int main(int argc, char *argv[])
{
	if (argc != 2)				// This particular program requires two arguments
		printUsage(argv[0]);	// The first argument is ALWAYS the invocation of the program

	// Constructing a string object from argv[1] to avoid a compile warning
	std::string argvOne(argv[1]);

	if (std::string(argvOne) == "--nice")		// The double dash is just conforming to typical arguments
		std::cout << "Hi there friend.\n";
	else if (std::string(argvOne) == "--mean")	// Try man ls in a terminal, then man mv to see how arguments 
		std::cout << "Hi there ya fat dink!\n";	// are traditionally implemented
	else if (std::string(argvOne) == "--meh")
		std::cout << "Hi there...you.\n";
	else
		printUsage(argv[0]);					// Usage is printed if no acceptable argument was provided

	std::cout << "\nFor reference:\n";
	for (int i = 0; i < argc; i++)
		std::cout << "Argument #" << (i + 1) << ": " << argv[i] << std::endl; 

	return 0;
}

void printUsage(char arg[])
{
	std::cout << "USAGE: " << arg <<  " [--nice --mean]\n";
	exit(1);
}