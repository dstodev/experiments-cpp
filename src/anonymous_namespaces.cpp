/*
        Q/A:
                Q. Can symbols inside an anonymous namespace be referenced outside of the namespace but
                        within the same TU?
                A. Yes

                Q. Are multiple anonymous namespaces within the same TU actually the same namespace?
                        i.e. can you only have one unique anonymous namespace within a single TU?
                A. Yes

        Takeaways:
                All anonymous namespaces within the same TU are the same

                Symbols defined in an anonymous namespace are accessible outside of the namespace,
                but (only) within the same translation unit
*/


#include <iostream>
using std::cout;
using std::endl;

namespace {
int func_one()
{
	return 1;
}
}  // namespace

namespace {
// Will redefine func_one(), meaning all anonymous namespaces within a TU reference the same namespace.
// int func_one()
// {
// 	return 0;
// }
int func_two()
{
	return 2;
}
}  // namespace


// Main is outside of the anonymous namespace, but within the same TU, so func_one() and func_two() are accessible.
int main()
{
	cout << func_one() << endl;
	cout << func_two() << endl;

	return 0;
}
