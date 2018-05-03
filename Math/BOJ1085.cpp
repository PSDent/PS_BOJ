#include <iostream>

int Min(int a, int b) {
	return a < b ? a : b;
}

int main()
{
	int x, y, w, h;
	int a,b,c,d, dist = 1001;

	std::cin >> x >> y >> w >> h;

	// L
	a = x;
	// R
	b = w - x;
	// U
	c = h - y;
	// D
	d = y;

	std::cout << Min(d,Min(c,Min(a, b)));

	return 0;
}
