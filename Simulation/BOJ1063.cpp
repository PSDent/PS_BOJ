#include <iostream>
#include <string>
#include <map>

using Coord = std::pair<int, int>;
int kx, ky, sx, sy;

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	std::string king, stone, input;
	std::map<std::string, std::pair<int, int>> m;
	m.insert(std::make_pair("R", std::make_pair(1, 0)));
	m.insert(std::make_pair("L", std::make_pair(-1, 0)));
	m.insert(std::make_pair("B", std::make_pair(0, -1)));
	m.insert(std::make_pair("T", std::make_pair(0, 1)));
	m.insert(std::make_pair("RT", std::make_pair(1, 1)));
	m.insert(std::make_pair("LT", std::make_pair(-1, 1)));
	m.insert(std::make_pair("RB", std::make_pair(1, -1)));
	m.insert(std::make_pair("LB", std::make_pair(-1, -1)));


	std::cin >> king >> stone >> N;
	kx = king[0] - 'A' + 1; ky = king[1] - '0';
	sx = stone[0] - 'A' + 1; sy = stone[1] - '0';
	
	while (N--)
	{
		int dx = 0, dy = 0, nx, ny;
		std::cin >> input;
		dx = m[input].first, dy = m[input].second;
		nx = dx + kx, ny = dy + ky;
		if (nx > 8 || nx < 1 || ny > 8 || ny < 1) continue;
		else if (nx == sx && ny == sy)
		{
			int snx = sx + dx, sny = sy + dy;
			if (snx > 8 || snx < 1 || sny > 8 || sny < 1) continue;
			else
			{
				kx = nx, ky = ny;
				sx = snx, sy = sny;
			}
		}
		else kx = nx, ky = ny;
	}

	std::cout << (char)(kx + 'A' - 1) << ky << '\n';
	std::cout << (char)(sx + 'A' - 1) << sy;

	return 0;
}#include <iostream>
#include <string>
#include <map>

using Coord = std::pair<int, int>;
int kx, ky, sx, sy;

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	std::string king, stone, input;
	std::map<std::string, std::pair<int, int>> m;
	m.insert(std::make_pair("R", std::make_pair(1, 0)));
	m.insert(std::make_pair("L", std::make_pair(-1, 0)));
	m.insert(std::make_pair("B", std::make_pair(0, -1)));
	m.insert(std::make_pair("T", std::make_pair(0, 1)));
	m.insert(std::make_pair("RT", std::make_pair(1, 1)));
	m.insert(std::make_pair("LT", std::make_pair(-1, 1)));
	m.insert(std::make_pair("RB", std::make_pair(1, -1)));
	m.insert(std::make_pair("LB", std::make_pair(-1, -1)));


	std::cin >> king >> stone >> N;
	kx = king[0] - 'A' + 1; ky = king[1] - '0';
	sx = stone[0] - 'A' + 1; sy = stone[1] - '0';
	
	while (N--)
	{
		int dx = 0, dy = 0, nx, ny;
		std::cin >> input;
		dx = m[input].first, dy = m[input].second;
		nx = dx + kx, ny = dy + ky;
		if (nx > 8 || nx < 1 || ny > 8 || ny < 1) continue;
		else if (nx == sx && ny == sy)
		{
			int snx = sx + dx, sny = sy + dy;
			if (snx > 8 || snx < 1 || sny > 8 || sny < 1) continue;
			else
			{
				kx = nx, ky = ny;
				sx = snx, sy = sny;
			}
		}
		else kx = nx, ky = ny;
	}

	std::cout << (char)(kx + 'A' - 1) << ky << '\n';
	std::cout << (char)(sx + 'A' - 1) << sy;

	return 0;
}
