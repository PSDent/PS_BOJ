#include <iostream>

char pixel[65][65]; // 1 ~ 64

void Quad(int sx, int sy, int size)
{
	char pivot = pixel[sy][sx];

	// 괄호 넣는 것을 잘 생각할 것

	for (int i = sy; i < sy + size; ++i)
	{
		for (int j = sx; j < sx + size; ++j)
		{
			if (pixel[i][j] != pivot)
			{
				std::cout << '(';
				for (int m = 0; m < 2; ++m)
				{
					for (int n = 0; n < 2; ++n)
					{
						Quad(sx + n * size / 2, sy + m * size / 2, size / 2);
					}
				}

				std::cout << ')';
				return;
			}

		}
	}

	std::cout << pivot;
	return; 
}

int main()
{
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			std::cin >> pixel[i][j];

	Quad(1, 1, n);

	return 0;
}