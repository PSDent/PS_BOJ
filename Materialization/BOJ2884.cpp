#include <iostream>

int main()
{
	int H, M;

	std::cin >> H >> M;

	if (H == 0 && M < 45)
		H = 24;

	int min = H * 60 + M;
	min -= 45;

	int hour = min / 60;
	min -= hour * 60;

	std::cout << hour << ' ' << min;

	return 0;
}
