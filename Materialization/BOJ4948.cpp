#include <iostream>

const int MAX_PRIME = 246912;
bool primeNumArr[MAX_PRIME + 1]; // 123456 * 2 + 1

void Eratostenes()
{
	for (int i = 2; i <= MAX_PRIME; ++i)
		primeNumArr[i] = true;

	for (int i = 2; (i * i) <= MAX_PRIME; ++i)
	{
		if (primeNumArr[i])
		{
			for (int j = i * i; j <= MAX_PRIME; j += i)
				primeNumArr[j] = false;
		}
	}

}

int FindPrimeNum(int n)
{
	int cnt = 0;

	for (int i = n + 1; i <= 2 * n; ++i)
		if (primeNumArr[i])
			++cnt;

	return cnt;
}

int main()
{
	int input;

	Eratostenes();

	std::cin >> input;
	do
	{
		std::cout << FindPrimeNum(input) << '\n';
		std::cin >> input;
	} while (input != 0);

	return 0;
}
