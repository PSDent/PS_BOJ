#include <iostream>
#include <vector>

using Point = std::pair<int, int>;

struct Snake
{
	int x, y;
	int nowDir;
	int nextPoint;

	Snake(int x, int y, int dir, int point)
	{
		this->x = x;
		this->y = y;
		nowDir = dir;
		nextPoint = point;
	}
};

char map[101][101];
std::vector<Point> moveV;
std::vector<Snake> snake;
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };
int nowDir = 0; // 0 : R, 1 : D, 2 : L, 3 : U

int main()
{
	int N, K, L;

	std::cin >> N >> K;

	for (int i = 0; i < K; ++i) // 사과
	{
		int x, y;
		std::cin >> y >> x;
		map[y][x] = '@';
	}

	std::cin >> L;
	for (int i = 0; i < L; ++i) // 명령
	{
		int time, dirVal;
		char cmd;
		std::cin >> time >> cmd;
		if (cmd == 'L')
			dirVal = -1;
		else
			dirVal = 1;
		moveV.push_back(std::make_pair(time, dirVal));
	}

	snake.emplace_back(1, 1, 0, 0); // 초기 위치

	int time = 0;
	bool gameOver = false;
	while (!gameOver)
	{
		int size = snake.size();
		++time;

		bool eat = false;
		for (int i = 0; i < size; ++i) // 뱀 이동
		{
			snake[i].x += dirX[snake[i].nowDir];
			snake[i].y += dirY[snake[i].nowDir];
			if (snake[i].nextPoint < moveV.size() && time - moveV[snake[i].nextPoint].first == i)
			{
				snake[i].nowDir += moveV[snake[i].nextPoint].second;
				snake[i].nowDir = (snake[i].nowDir + 4) % 4;
				++snake[i].nextPoint;
			}

			if (map[snake[i].y][snake[i].x] == '@')
			{
				map[snake[i].y][snake[i].x] = ' ';
				eat = true;
			}

			for (int i = 1; i < snake.size(); ++i) // 뱀 머리와 몸통 충돌 검사
				if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
					gameOver = true;
		}
		if (eat)
		{
			int tail = snake.size() - 1;
			int newX = snake[tail].x - dirX[snake[tail].nowDir], newY = snake[tail].y - dirY[snake[tail].nowDir];
			snake.emplace_back(newX, newY, snake[tail].nowDir, snake[tail].nextPoint);
		}

		if (snake[0].x == 0 || snake[0].x == N + 1) // 벽에 부딪힘
			gameOver = true;
		else if (snake[0].y == 0 || snake[0].y == N + 1) // 벽에 부딪힘
			gameOver = true;
	}

	std::cout << time;

	return 0;
}
