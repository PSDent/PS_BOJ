#include <iostream>

int main()
{
	int x = 0;
	int E, S, M;
	int ME, MS, MM;
	std::cin >> E >> S >> M; // 15, 28, 19

	ME = 15; 
	MS = 28;
	MM = 19;

	int e = 0, s = 0, m = 0;
	for (int i = 0; ; ++i)
	{
		e = ME * i + E;

		for (int j = 0; m <= e; ++j)
		{
			m = MM * j + M;
			if (m == e)
			{
				for (int k = 0; s <= m; ++k)
				{
					s = MS * k + S;
					if (s == m)
					{
						std::cout << s;
						return 0;
					}
				}
			}
		}

	}

	return 0;
}
