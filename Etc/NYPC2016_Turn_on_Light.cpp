#include <iostream>

int cal_angle(int, int, int, int, int, int);

char map[30][30] = { 0 };
int count = 0;

int main()
{
	int W, H, result = 0;

	std::cin >> W >> H; 

	for (int i = 0; i < H; i++) //ют╥б
		for(int j = 0; j < W; j++)
			std::cin >> map[i][j];

	for (int i = 0; i < H; i++)
	{
		if(cal_angle(-1, i, 1, 0, W, H)) { std::cout << "L " << i; return 0; };
		if(cal_angle(W, i, -1, 0, W, H)) { std::cout << "R " << i; return 0; };
	}

	for (int i = 0; i < W; i++)
	{
		if (cal_angle(i, -1, 0, 1, W, H)){ std::cout << "U " << i; return 0;}
		if (cal_angle(i, H, 0, -1, W, H)){ std::cout << "D " << i; return 0;}
	}
}

int cal_angle(int x, int y, int val_x, int val_y, int w, int h)
{
	if (map[y + val_y][x + val_x] == 'O') return 1;
	else if (map[y + val_y][x + val_x] == '/' && x + val_x != w && y + val_y != h) // '/'
	{
		if (val_x == 1) cal_angle(++x, y, 0, -1, w, h);
		else if (val_x == -1) cal_angle(--x, y, 0, 1, w, h);
		else if (val_y == 1) cal_angle(x, ++y, -1, 0, w, h);
		else cal_angle(x, --y, 1, 0, w, h);
	}
	else if (map[y + val_y][x + val_x] == '\\' && x + val_x != w && y + val_y != h) // '\' 
	{
		if (val_x == 1) cal_angle(++x, y, 0, 1, w, h);
		else if (val_x == -1) cal_angle(--x, y, 0, -1, w, h);
		else if (val_y == 1) cal_angle(x, ++y, -1, 0, w, h);
		else cal_angle(x, --y, 1, 0, w, h);
	}
	else if (map[y + val_y][x + val_x] == '.' && x + val_x != w && y + val_y != h)
		cal_angle(x + val_x, y + val_y, val_x, val_y, w, h);
	else return 0;
}