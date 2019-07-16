#include <iostream>
#include <algorithm>
#include <vector>

#define Left first
#define Right second

using Child = std::pair<int, int>;

Child node[10001];
std::vector<int> column[10001];
bool rootCheck[10001];
int minLevel = 1, maxWidth, maxLevel;
int no = 1;

void InOrder(int nodeNum, int level)
{
	if (nodeNum == -1) return;

	maxLevel = std::max(maxLevel, level);

	InOrder(node[nodeNum].Left, level + 1);
	column[level].emplace_back(no); ++no;
	InOrder(node[nodeNum].Right, level + 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int nodeNum;
		std::cin >> nodeNum;
		std::cin >> node[nodeNum].Left >> node[nodeNum].Right;
		if (node[nodeNum].Left != -1) rootCheck[node[nodeNum].Left] = true;
		if (node[nodeNum].Right != -1) rootCheck[node[nodeNum].Right] = true;
	}

	for (int i = 1; i <= N; ++i)
		if (!rootCheck[i])
			InOrder(i, 1);

	for (int i = 1; i <= maxLevel; ++i)
	{
		int end = column[i].size() - 1;
		int width = column[i][end] - column[i][0] + 1;
		if (width > maxWidth)
		{
			maxWidth = width;
			minLevel = i;
		}
	}
	std::cout << minLevel << ' ' << maxWidth;

	return 0;
}
