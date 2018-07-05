#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, index = 0;
char board[25][26];
int complex[625];
int aptComplexCnt = 0;

void DFS(int x, int y)
{
	++complex[index];
	board[y][x] = '0' + aptComplexCnt + 1;

	if (x > 0 && board[y][x - 1] == '1')
		DFS(x - 1, y);
	if (x < N - 1 && board[y][x + 1] == '1')
		DFS(x + 1, y);
	if (y > 0 && board[y - 1][x] == '1')
		DFS(x, y - 1);
	if (y < N - 1 && board[y + 1][x] == '1')
		DFS(x , y + 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == '1')
			{
				++aptComplexCnt;
				++index;
				DFS(j, i);
			}
		}
	}

	if(aptComplexCnt > 0)
		sort(complex + 1, complex + aptComplexCnt + 1);

	std::cout << aptComplexCnt << '\n';
	for (int i = 1; i <= aptComplexCnt; ++i)
		cout << complex[i] << '\n';

	return 0;
}
