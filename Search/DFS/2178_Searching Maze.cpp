//================================================
// Filename : 2178_Seaching Maze
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2178
//================================================

#include <iostream>

void SearchMaze(char (*maze)[100], int, int);

int main()
{
	char maze[100][100] = { '0' };
	int N, M;

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			std::cin >> maze[i][j];

	SearchMaze(maze, N, M);

	return 0;
}

void SearchMaze(char (*maze)[100], int, int)
{

}