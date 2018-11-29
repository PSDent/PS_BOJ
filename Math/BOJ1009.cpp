#include <iostream>

int main()
{
	int T, a, b;
	
	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int temp = 1;
		std::cin >> a >> b;
		for (int j = 0; j < b; ++j)
			temp = temp * a % 10;

		if (temp == 0) temp = 10;
		std::cout << temp << '\n';
	}

	return 0;
}
