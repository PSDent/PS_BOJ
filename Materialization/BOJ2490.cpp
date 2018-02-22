#include <iostream>

int main()
{
	char yut[7] = {'D','C', 'B', 'A', 'E' }; // 0 = น่, 1 = ต๎ 

	for (int i = 0; i < 3; i++) {
		int a = 0, b = 0, c = 0, d = 0;
		int sum = 0;

		std::cin >> a >> b >> c >> d;
		sum = a + b + c + d;
		std::cout << yut[sum] << std::endl;
	}


	return 0;
}