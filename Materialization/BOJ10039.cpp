#include <iostream>

int main()
{
	int sum = 0;
	int student = 0;

	for (int i = 0; i < 5; i++) {
		std::cin >> student;
		if (student < 40)
			sum += 40;
		else
			sum += student;
	}

	std::cout << sum / 5;


	return 0;
}