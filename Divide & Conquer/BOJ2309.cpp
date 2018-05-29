#include <iostream>
#include <algorithm>

int dwarf[9];
int arr_index = 0;

void BF(int height, int sum, int index, int cnt)
{
	static bool isFind = false;

	if (isFind || height + sum > 100)
		return;

	if (sum + height != 100)
	{
		for (int i = index + 1; i < 9; ++i)
		{
			BF(dwarf[i], sum + height, i, cnt + 1);

			if (isFind)
			{
				dwarf[arr_index++] = height;
				break;
			}
		}
	}

	else if (sum + height == 100 && cnt == 7)
	{
		dwarf[arr_index++] = height;
		isFind = true;
	}

	return;
}

int main()
{
	for (int i = 0; i < 9; ++i)
		std::cin >> dwarf[i];

	BF(0, 0, -1, 0);

	std::sort(dwarf, dwarf + 7);

	for (int i = 0; i < 7; ++i)
		std::cout << dwarf[i] << ' ';

	return 0;
}