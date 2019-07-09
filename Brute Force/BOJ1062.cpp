#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> strV;
int max = 0, N, K;
void FindWord(int status, int lastPos, int depth)
{
	if (depth == K - 5)
	{
		int wordCnt = 0;
		for (auto str : strV)
		{
			int cnt = 0;
			for (int i = 4; i < str.size() - 4; ++i)
			{
				int pos = str[i] - 'a';
				if (status & (1 << pos)) ++cnt;
			}
			
			if (cnt == str.size() - 8)
				++wordCnt;
		}
		max = std::max(max, wordCnt);
	}
	else
	{
		for (int i = lastPos + 1; i < 26; ++i)
		{
			if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;
			int tempStatus = status;
			tempStatus |= (1 << i);
			FindWord(tempStatus, i, depth + 1);
		}
	}
}

int main()
{
	std::cin >> N >> K;

	if (K < 5)
	{
		std::cout << 0;
		return 0;
	}
	else if (K == 26)
	{
		std::cout << N;
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		strV.emplace_back(str);
	}

	int status = 0;

	status = status | (1 << 0) | (1 << 2) | (1 << 8) | (1 << 13) | (1 << 19);

	for (int i = 0; i < 26; ++i)
	{
		if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;
		int tempStatus = status;
		int startDepth = 0;
		if (K > 5)
		{
			tempStatus |= (1 << i);
			startDepth = 1;
		}
		FindWord(tempStatus, i, startDepth);
	}

	std::cout << max;

	return 0;
}
