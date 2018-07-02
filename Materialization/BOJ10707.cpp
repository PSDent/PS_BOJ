#include <iostream>

int Min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int xTax, yTax, yUse, yAdd, amount;
	int x, y = 0;

	std::cin >> xTax >> yTax >> yUse >> yAdd >> amount;

	x = xTax * amount;
	y = yTax;
	if (amount - yUse > 0)
		y += (amount - yUse) * yAdd;

	std::cout << Min(x, y);

	return 0;
}
