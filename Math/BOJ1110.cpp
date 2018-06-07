#include <iostream>

int main()
{
	int N, save, cnt = 0;

	std::cin >> N;
	save = N;

	do
	{
		int sum = 0, num;	
		
		num = N % 10;
		sum = N / 10 + N % 10;
		N = num * 10 + sum % 10; 

		++cnt;
	} while (save != N);

	std::cout << cnt;

	return 0;
}
