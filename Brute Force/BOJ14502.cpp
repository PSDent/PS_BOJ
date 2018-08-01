#include <iostream>

int N;

int main()
{
	int mul = 1;
	int tempMul, tempSum, tempVal;

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		if (i / mul == 10)
			mul *= 10;

		tempMul = mul;
		tempSum = i;
		tempVal = i;
		while (tempMul > 0)
		{
			tempSum += tempVal / tempMul;
			tempVal = tempVal - (tempVal / tempMul) * tempMul;
			tempMul /= 10;
		}

		if (tempSum == N)
		{
			std::cout << i;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
}
