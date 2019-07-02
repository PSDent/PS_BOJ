#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> sIndexs;
	std::string docu, word;
	int maxCnt = 0;
	std::getline(std::cin, docu);
	std::getline(std::cin, word);

	int startIndex = 0;

	while(docu.find(word, startIndex) != std::string::npos)
	{
		startIndex = docu.find(word, startIndex);
		sIndexs.push_back(startIndex);
		++startIndex;
	}

	for (int i = 0; i < sIndexs.size(); ++i)
	{
		int endPos, cnt = 1;
		endPos = sIndexs[i] + word.size() - 1;
		
		for (int j = i + 1; j < sIndexs.size(); ++j)
		{
			if (sIndexs[j] <= endPos) continue;
			
			endPos = sIndexs[j] + word.size() - 1;
			++cnt;
		}

		if (cnt > maxCnt)
			maxCnt = cnt;
	}

	std::cout << maxCnt;

	return 0;
}
