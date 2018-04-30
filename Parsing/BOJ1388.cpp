#include <iostream>

char room[101][101]; // '-', '|', '.'
int N, M, cnt = 0;

using namespace std;

void visit(int x, int y)
{
	int addY = 0, addX = 0;
	char origin = room[y][x];

	if (origin == '-')
		addX = 1;
	else
		addY = 1;

	while (room[y][x] == origin) {
		room[y][x] = '.';
		y += addY;
		x += addX;
	}
	cnt++;
}

int calAmount()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (room[i][j] != '.')
				visit(j, i);
	}

	return cnt;
}

int main()
{
	char input;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> room[i][j];
	calAmount();
	cout << cnt;

	return 0;
}