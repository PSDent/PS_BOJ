#include <iostream>
#include <string>
#include <algorithm>

int cnt[2][26], rs = 0;

int main()
{
	std::string input;

	for (int i = 0; i < 2; ++i)
	{
		std::cin >> input;
		for (int j = 0; j < input.size(); ++j)
		{
			++cnt[i][input[j] - 'a'];
		}
	}
	
	for (int i = 0; i < 26; ++i)
	{
		int m = std::max(cnt[0][i], cnt[1][i]);
		int n = std::min(cnt[0][i], cnt[1][i]);
		rs += m - n;
	}
	std::cout << rs;
	return 0;
}
