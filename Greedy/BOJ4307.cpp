#include <iostream>
#include <ios>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	int length, n;

	std::cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		int ant;
		int min = 0, max = 0;
		std::cin >> length >> n;
		
		for (int j = 0; j < n; ++j)
		{
			std::cin >> ant;
			int srt = ((length - ant) < ant) ? length - ant : ant;
			int lng = (ant > length - ant) ? ant : length - ant;

			min = (min > srt) ? min : srt;
			max = (max > lng) ? max : lng;
		}
		std::cout << min << ' ' << max << '\n';
	}

	return 0;
}
