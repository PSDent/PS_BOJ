#include <iostream>

int main()
{
	int N, time, m = 0, y = 0;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> time;
		y += (time / 30 + 1) * 10;
		m += (time / 60 + 1) * 15;
	}

	if (y == m)
		std::cout << "Y " << "M " << y;
	else
	{
		if (y < m) std::cout << "Y " << y;
		else std::cout << "M " << m;
	}
	
	return 0;
}
