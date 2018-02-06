#include <iostream>

int main()
{
	int A, B, V;
	int t = 0;

	std::cin >> A >> B >> V;

	if ((V - A) % (A - B) != 0)
		t = 1;

	std::cout << (V - A) / (A - B) + 1 + t;

	return 0;
}