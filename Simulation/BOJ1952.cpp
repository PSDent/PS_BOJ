#include <iostream>

bool visited[101][101];
int dirX[4] = { 1, 0, -1, 0 }, dirY[4] = { 0, 1, 0, -1 }, dir = 0, cnt = 0;

int main()
{
	int M, N, nx = 1,ny = 1;
	std::cin >> M >> N;

	while (true)
	{
		int dx = dirX[dir], dy = dirY[dir];
		if(!visited[ny][nx]) visited[ny][nx] = true;
		else break;

		if (ny + dy > M || ny + dy < 1 || nx + dx > N || nx + dx < 1 || visited[ny + dy][nx + dx])
		{
			++cnt;
			dir = (dir + 1) % 4; 
			dx = dirX[dir], dy = dirY[dir];
		}
		ny += dy, nx += dx;
	}
	std::cout << cnt - 1;

	return 0;
}
