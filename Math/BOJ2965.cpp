#include <iostream>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int A, B, C;

	std::cin >> A >> B >> C;

	std::cout << Max(C - B, B - A) - 1;

}
