#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<std::string> v;
	std::string input;
	int N, M, K, max = 0;
	
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		v.push_back(input);
	}
	std::cin >> K;

	while (!v.empty())
	{
		int cnt = 1;
		std::string mem = v[0];
		v.erase(v.begin());
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == mem) { 
				++cnt;
				v.erase(v.begin() + i);
				--i;
			}
		}

		int zeroCnt = 0;
		for (int i = 0; i < mem.size(); ++i)
		{
			if (mem[i] == '0')
				++zeroCnt;
		}
		
		if ( K < zeroCnt)  continue;
		if ( (zeroCnt - K) % 2 == 0) 
			max = std::max(max, cnt);
	}
	std::cout << max;

	return 0;
}                                                       
