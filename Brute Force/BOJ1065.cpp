#include <iostream>

int cnt = 0;

void CheckSequence(int val, int length)
{
	int sequence[4], index = 0, diffrent = 0;

	for (int i = length; i > 0; i /= 10)
	{
		sequence[index] = val / i;
		val -= sequence[index++] * i;
	}

	diffrent = sequence[0] - sequence[1];
	for (int i = 0; i < index - 1; ++i)
	{
		if (sequence[i] - sequence[i + 1] != diffrent)
			return;
	}
	++cnt;

	return;
}

int main()
{
	int N, length = 1;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		if (i / length >= 10) length *= 10;
		CheckSequence(i, length);
	}
	std::cout << cnt;

	return 0;
}