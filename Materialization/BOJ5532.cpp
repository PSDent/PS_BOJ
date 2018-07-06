#include <iostream>

int main()
{
	int L, A, B, C, D;
	int days = 0;
	std::cin >> L >> A >> B >> C >> D;

	while (A > 0 || B > 0)
	{
		A -= C;
		B -= D;
		++days;
	}

	std::cout << L - days;
}
