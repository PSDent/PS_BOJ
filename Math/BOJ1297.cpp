#include <iostream>
#include <cmath>

int main()
{
	int diag, h, w;
	double d;

	std::cin >> diag >> h >> w;
	d = sqrt(pow(diag, 2) / (pow(h, 2) + pow(w, 2)));
	h = h * d;
	w = w * d;

	std::cout << h << ' ' << w;
	return 0;
}
