#include <iostream>

using namespace std;

unsigned int oneCnt = 0, zeroCnt = 0;

int fibonacci(int n) 
{
	if (n == 0) {
		zeroCnt++;
		return 0;
	}
	else if (n == 1) {
		oneCnt++;
		return 1;
	}
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void main()
{
	int *number;
	int T;
	cin >> T;

	number = new int[T*2];

	for (int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		fibonacci(temp);

		number[i * 2] = zeroCnt;
		number[i * 2 + 1] = oneCnt;

		zeroCnt = oneCnt = 0;
	}

	for (int i = 0; i < T; i++)
		cout << number[i * 2] << ' ' << number[i * 2 + 1] << '\n';
}