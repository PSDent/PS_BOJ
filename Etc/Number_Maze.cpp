#include <iostream>

#define WIDTH 7
#define HIDTH WIDTH

int Solvemaze(int, int, int count = 0);
int CheckOverlap(int, int); //Checking Array "is it Overlaped"

int maze[HIDTH][WIDTH] = {
	//0 1 2 3 4 5 6
	{ 4,3,1,3,6,4,3 }, //0
	{ 4,4,3,5,3,5,4 }, //1
	{ 4,3,2,3,4,1,4 }, //2
	{ 2,4,5,2,3,3,2 }, //3
	{ 2,5,4,2,1,3,1 }, //4
	{ 4,2,2,4,2,3,2 }, //5
	{ 4,6,5,1,1,3,1 }  //6
};
int arr[40] = { -1 };

int main()
{
	int x = Solvemaze(6, 6);
	if (x != 9999999)
		std::cout << "Minimum Path : " << x << std::endl;
	else
		std::cout << "That Path is can't found." << std::endl;
}

int Solvemaze(int X, int Y, int count)
{
	static int mincount = 9999999;
	static int reachX = X, reachY = Y, i = 0, flag=0;

	if (!count) {
		X = 0; Y = 0;
	}

	if (X == reachX && Y == reachY && count < mincount)
	{
		flag = 1; mincount = count;
		return 0;
	}
	else if( mincount > count )
	{
		if (Y + maze[Y][X] < WIDTH && !CheckOverlap(X, Y + maze[Y][X])){	
			arr[i * 2] = X; arr[i * 2 + 1] = Y; i++;
			Solvemaze(X, Y + maze[Y][X], count+1); //UP
		}
		if (Y - maze[Y][X] >= 0 && !CheckOverlap(X, Y - maze[Y][X])) {
			arr[i * 2] = X; arr[i * 2 + 1] = Y; i++;
			Solvemaze(X, Y - maze[Y][X], count+1); //DOWN
		}
		if (X + maze[Y][X] < HIDTH && !CheckOverlap(X + maze[Y][X],Y)) {
			arr[i * 2] = X; arr[i * 2 + 1] = Y; i++;
			Solvemaze(X + maze[Y][X], Y, count+1); //RIGHT 
		}
		if (X - maze[Y][X] >= 0 && !CheckOverlap(X - maze[Y][X], Y)) {
			arr[i * 2] = X; arr[i * 2 + 1] = Y; i++;
			Solvemaze(X - maze[Y][X], Y, count+1); //LEFT
		}
	}
	else
	{
		int j = 0; i = 0;
		while (j < 40) {
			arr[j] = -1; j++;
		}
		return 0;
	}

	if (flag != 0)
		return mincount;
	else
		return 9999999;
}

int CheckOverlap(int x, int y){
	int j = 0;
	while (arr[j*2] != -1){
		if (arr[j * 2] == x && arr[j * 2 + 1] == y)
			return 1;
		j++;
	}
	return 0;
}
