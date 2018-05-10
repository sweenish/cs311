#include <iostream>

class Foo {
public:
	Foo();
	int* getAddr() const;
	int getVal() const;
	void setVal(int val);
	friend std::ostream& operator <<(std::ostream &lhs, const Foo &rhs);
private:
	int *ptr;
};

int main()
{
	Foo foo;

	std::cout << "foo: " << foo << std::endl;

	{	// SCOPING
		Foo bar = foo;
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

std::ostream& operator <<(std::ostream &lhs, const Foo & rhs)
{
	lhs << "(" << rhs.ptr << ", " << *(rhs.ptr) << ")";

	return lhs;
}