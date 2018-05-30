#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = 3.141592653589793;

int main()
{
	double R;

	std::cin >> R;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << pow(R,2.0) * PI << ' ' << pow(R * sqrt(2.0), 2.0);

	return 0;
}
