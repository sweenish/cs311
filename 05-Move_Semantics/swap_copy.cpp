#include <iostream>
#include <string>
 
template<class T>
void swap(T& a, T& b) 
{ 
  T tmp { a }; // invokes copy constructor
  a = b; // invokes copy assignment
  b = tmp; // invokes copy assignment
}
 
int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };
 
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
 
	swap(x, y);
 
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
 
	return 0;
}