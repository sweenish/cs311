#include <iostream>

class Foo {
public:
	Foo();					// Default constructor
	Foo(const Foo &foo);	// Copy constructor						// BIG THREE
	~Foo();					// Destructor							// BIG THREE
	int* getAddr() const;
	int getVal() const;
	void setVal(int val);
	Foo& operator =(const Foo &rhs);	// Overloaded assignment	// BIG THREE
	friend std::ostream& operator <<(std::ostream &lhs, const Foo &rhs);
private:
	int *ptr;
};

int main()
{
	Foo foo;

	std::cout << "foo: " << foo << std::endl;
	{	// SCOPING
		Foo bar;
		bar = foo;
		bar.setVal(99);
		std::cout << "bar: " << bar << std::endl;
	}
	std::cout << "foo: " << foo << std::endl;

	return 0;
}

Foo::Foo()
{
	ptr = new int(42);
}

Foo::Foo(const Foo &foo)
{
	ptr = new int(*(foo.ptr));
}

Foo::~Foo()
{
	delete ptr;
	ptr = nullptr;
}

int* Foo::getAddr() const
{
	return ptr;
}

int Foo::getVal() const
{
	return *ptr;
}

void Foo::setVal(int val)
{
	*ptr = val;
}

Foo& Foo::operator =(const Foo &rhs)
{
	if (&rhs == this)
		return *this;
	
	delete ptr;
	ptr = new int(*(rhs.ptr));

	return *this;
}

std::ostream& operator <<(std::ostream &lhs, const Foo & rhs)
{
	lhs << "(" << rhs.ptr << ", " << *(rhs.ptr) << ")";

	return lhs;
}