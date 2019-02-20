#include <iostream>

bool board[7][7];

int main()
{
	char cw;
	int w, h, pw, ph, sw, sh;

	for (int i = 0; i < 36; ++i)
	{
		std::cin >> cw >> h;
		w = cw - 'A' + 1;
		if (i == 0) { sw = w; sh = h; }
		if (board[h][w]) { std::cout << "Invalid"; return 0; }

		board[h][w] = true;
		
		if (i != 0)
		{
			bool valid = false;
			for (int j = 1; j <= 2; ++j)
			{
				int k = j % 2 + 1;
				if (pw - j > 0)
				{
					if (ph + k <= 6 && h == ph + k && w == pw - j) valid = true;
					if (ph - k > 0 && h == ph - k && w == pw - j) valid = true;
				}

				if (pw + j <= 6)
				{
					if (ph + k <= 6 && h == ph + k && w == j + pw) valid = true;
					if (ph - k > 0 && h == ph - k && w == j + pw) valid = true;
				}
			}
			if (!valid) { std::cout << "Invalid"; return 0; }
		}
		if (i == 35)
		{
			bool valid = false;
			for (int j = 1; j <= 2; ++j)
			{
				int k = j % 2 + 1;
				if (sw - j > 0)
				{
					if (sh + k <= 6 && h == sh + k && w == sw - j) valid = true;
					if (sh - k > 0 && h == sh - k && w == sw - j) valid = true;
				}

				if (sw + j <= 6)
				{
					if (sh + k <= 6 && h == sh + k && w == j + sw) valid = true;
					if (sh - k > 0 && h == sh - k && w == j + sw) valid = true;
				}
			}
			if (!valid) { std::cout << "Invalid"; return 0; }
		}
		pw = w; ph = h;
	}
	std::cout << "Valid";
	return 0;
}
