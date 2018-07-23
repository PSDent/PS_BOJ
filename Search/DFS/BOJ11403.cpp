#include <iostream>

bool vertex[100][100];
bool result[100][100];
int N;

void DFS(int v, int x)
{
	for (int i = 0; i < N; ++i)
	{
		if (!result[x][i] && vertex[v][i])
		{
			result[x][i] = true;
			DFS(i, x);
		}
	}
}

int main()
{
	std::cin >> N;
	bool input;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			std::cin >> vertex[i][j];

	for (int i = 0; i < N; ++i)
		DFS(i, i);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			std::cout << result[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}
