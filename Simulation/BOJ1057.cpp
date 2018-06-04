#include <iostream>

bool tournament[100001];

int main()
{
	int N, jimin, hansu;
	int cnt = 0;
	std::cin >> N >> jimin >> hansu;

	while (1)
	{
		if ( (jimin % 2 == 1 && jimin + 1 == hansu) || 
			(hansu % 2 == 1 && hansu + 1 == jimin) )
		{
			std::cout << cnt + 1;
			return 0;
		}
		else
		{
			++cnt;
			jimin = (float)jimin / 2.0f + 0.5f;
			hansu = (float)hansu / 2.0f + 0.5f;
		}
	}


	return 0;
}
