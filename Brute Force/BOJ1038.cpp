#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<long long> numV;

void ReduceNum(std::string numStr)
{
	if (numStr.size() > 10) return;
	numV.emplace_back(std::stoll(numStr));

	char lastCh = numStr[numStr.size() - 1];
	if (lastCh == '0') return;
	--lastCh;
	for (char i = lastCh; i >= '0'; --i)
		ReduceNum(numStr + i);
}

int main()
{
	int N;
	std::cin >> N;

	numV.emplace_back(0);
	for (char i = '1'; i <= '9'; ++i)
	{
		std::string numStr;
		numStr.push_back(i);
		ReduceNum(numStr);
	}

	std::sort(numV.begin(), numV.end());
	if (N >= numV.size()) std::cout << -1;
	else std::cout << numV[N];

	return 0;
}
