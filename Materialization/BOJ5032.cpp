#include <iostream>

using namespace std;

int main()
{
	int a, b, c, cnt = 0;
	
	cin >> a >> b >> c;

	a += b;

	while (a >= c)
	{
		int empty = a / c;
		cnt += empty;

		a = (a - empty * c) + empty;
	}
	cout << cnt;

	return 0;
}
