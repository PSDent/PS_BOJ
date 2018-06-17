#include <iostream>

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;

int N, M, R, C, K;
int map[20][20];	
int dice[6]; // 0 = D, 1 = F, 2 = U, 3 = B, 4 = L, 5 = R

void RotationDice(int cmd)
{
	int temp;
	switch (cmd)
	{
	case EAST:
		temp = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[5];
		dice[5] = temp;
		break;
	case WEST:
		temp = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[0];
		dice[0] = dice[4];
		dice[4] = temp;
		break;
	case NORTH:
		temp = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[1];
		dice[1] = temp;
		break;
	case SOUTH:
		temp = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[3];
		dice[3] = temp;
		break;
	}
}

void Movement(int cmd)
{
	if (cmd == EAST)
	{
		C += 1;
		if (C == M)
		{
			C -= 1; return;
		}
	}
	else if (cmd == WEST)
	{
		C -= 1;
		if (C == -1)
		{
			C += 1; return;
		}
	}
	else if (cmd == NORTH)
	{
		R -= 1;
		if (R == -1)
		{
			R += 1; return;
		}
	}
	else // cmd == SOUTH
	{
		R += 1;
		if (R == N)
		{
			R -= 1; return;
		}
	}
	RotationDice(cmd);
	if (map[R][C] == 0)
		map[R][C] = dice[0];
	else
	{
		dice[0] = map[R][C];
		map[R][C] = 0;
	}
	std::cout << dice[2] << '\n';

	return;
}

int main()
{
	std::cin >> N >> M >> R >> C >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			std::cin >> map[i][j];

	for (int i = 0; i < K; ++i)
	{
		int input;
		std::cin >> input;
		Movement(input);
	}

	return 0;
}
