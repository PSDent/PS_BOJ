#include <iostream>
#include <string>

char map[31][31];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	std::string A, B;
	std::cin >> A >> B;

	int indexA = 31, indexB =31;
	for (int i = 0; i < B.size(); ++i)
	{
		int temp = 0;
		temp = A.find(B[i], 0);

		if (temp == std::string::npos) continue;
		else
		{
			if (temp < indexA)
			{
				indexA = temp;
				indexB = B.find(B[i], 0);
			}
		}
	}

	for (int i = 0; i < B.size(); ++i)
		for (int j = 0; j < A.size(); ++j)
			map[i][j] = '.';

	for (int i = 0; i < A.size(); ++i) map[indexB][i] = A[i];
	for (int i = 0; i < B.size(); ++i) map[i][indexA] = B[i];

	for (int i = 0; i < B.size(); ++i)
	{
		for (int j = 0; j < A.size(); ++j)
			std::cout << map[i][j];
		std::cout << '\n';
	}
	return 0;
}
