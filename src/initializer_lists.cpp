/*
        Q/A:
                Q. Can an initializer list constructor take more than one parameter?
                A. Technically yes, but you cannot use the special initializer-list syntax.
*/

#include <initializer_list>
#include <ostream>
#include <vector>

class Container
{
	friend std::ostream & operator<<(std::ostream & os, const Container & c);

public:
	Container(std::initializer_list<int> list) : _value(0), _list(list)
	{}
	Container(int value, std::initializer_list<int> list) : _value(value), _list(list)
	{}

private:
	int _value;
	std::vector<int> _list;
};

std::ostream & operator<<(std::ostream & os, const Container & c)
{
	const auto & list = c._list;

	os << c._value;
	if (!list.empty()) {
		os << ", ";
	}

	for (auto iter = list.begin(); iter != list.end(); ++iter) {
		if (iter != list.begin()) {
			os << ", ";
		}
		os << *iter;
	}

	return os;
}


#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// Can use special initializer-list syntax
	Container c1{1, 2, 3};
	cout << c1 << endl;

	// Cannot use special initializer-list syntax
	Container c2(0, {1, 2, 3});
	cout << c2 << endl;

	return 0;
}
