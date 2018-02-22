#include <iostream>

int count[10];

int main()
{
	int A, B, C;
	int result;
	int multiple = 1;

	std::cin >> A >> B >> C;

	result = A * B * C;

	do {
		if (result < 10)
			break;

		multiple *= 10; 
	} while (result / multiple > 10);

	for (int i = multiple; i > 0; i /= 10)
	{
		int temp = result / i;
		count[temp]++;
		result = result - (temp * i);
	}

	for (int i = 0; i < 10; i++)
		std::cout << count[i] << std::endl;

	return 0;
}