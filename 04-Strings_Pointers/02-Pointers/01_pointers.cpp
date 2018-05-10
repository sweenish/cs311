#include <iostream>

typedef int* IntPtr;

void sneaky(const IntPtr temp);

int main()
{
	int og = 42;
	int *p1 = &og;  // Defining a pointer and providing the 'address of' the variable og
	std::cout << "Address of og: " << p1 << ", value is " << *p1 << "\n\n";  // Pointers hold addresses, can be de-referenced to get value

	int* p2;
	int * p3 = new int;
	p2 = p1;    // Note the difference in what is happening on this line and the next
	*p3 = *p1;  // Money *mon; mon->print(); === (*mon).print(); 
	*p2 = 24;   // By de-referencing, we are able to change the value of variables without needing the variable itself
	std::cout << "p2 pointing to: " << p2 << "\np1 pointing to: " << p1 << ", value is " << *p1; 
	std::cout << "\np3 pointing to : " << p3 << ", value is " << *p3 << "\n\n";
	delete p3;  // If we declare anything with 'new', we should delete it at some point. This destroys the dynamic variable
	p3 = nullptr;  // Destroying the dynamic variable means that the pointer is undefined. They are called dangling pointers. This is dangerous. NULL these pointers out as a best practice

	IntPtr p4 = new int(56);  // Declaration and initialization of unnamed integer using our typedef
	(*p4)++;
	std::cout << "Value of p4: " << *p4 << "\n\n";
	delete p4;
	p4 = nullptr;

	IntPtr p5 = new int(3);
	std::cout << "Value of *p5: " << *p5 << "\n";
	sneaky(p5);
	std::cout << "Value of *p5: " << *p5 << "\n";
	delete p5;
	p5 = nullptr;

	return 0;
}

void sneaky(const IntPtr temp)
{
	*temp = 99;
	std::cout << "In sneaky function, value at temp is: " << *temp << "\n";
}