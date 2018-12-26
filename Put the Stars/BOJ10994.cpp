#include <iostream>

bool star[400][400];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	// 한 변의 길이 = (N-1) * 4 + 1

	for (int i = N; i > 0; --i)
	{
		int startPos = (N - i) * 2 + 1;
		int endPos = (i - 1) * 4;

		for (int j = startPos; j <= startPos + endPos; ++j)
		{
			star[startPos][j] = true;
			star[startPos + endPos][j] = true;
			star[j][startPos] = true;
			star[j][startPos + endPos] = true;
		}

	}
	
	for (int i = 1; i <= (N - 1) * 4 + 1; ++i)
	{
		for (int j = 1; j <= (N - 1) * 4 + 1; ++j)
			if (star[i][j])
				std::cout << '*';
			else
				std::cout << ' ';
		std::cout << '\n';
	}

	return 0;
}
