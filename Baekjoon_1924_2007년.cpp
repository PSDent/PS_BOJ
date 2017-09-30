//-----------------------------------------------
// Baekjoon_1924_2007년 
//
// Problem URL : https://www.acmicpc.net/problem/1924
// 
// Coded by PSDent.
//
// GitHub : https://github.com/PSDent/algorithm
//------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

char *days_char[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int CalDay(int mon, int days)
{
	int sum = days;
	for (int i = 1; i < mon; i++)
		sum += month[i];

	return sum % 7;
}

int main()
{
	int x, y;

	cin >> x >> y;
	cout << days_char[CalDay(x,y)];

	return 0;
}
