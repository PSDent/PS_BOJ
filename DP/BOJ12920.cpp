#include <iostream>
#include <algorithm>
#include <vector>

using ItemPair = std::pair<int, int>;

int N, M, itemsNum;
int dp[10001];
std::vector<ItemPair> items;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int v, c, k;
		std::cin >> v >> c >> k;

		for (int j = 1; k; j <<= 1)
		{
			int itemC, itemV;

			++itemsNum;
			if (j > k)
			{
				itemC = k * c;
				itemV = k * v;
				items.emplace_back(std::make_pair(itemC, itemV));
				break;
			}

			k -= j;
			itemC = j * c;
			itemV = j * v;
			items.emplace_back(std::make_pair(itemC, itemV));
		}
	}

	int max = 0;
	for (int i = 0; i < itemsNum; ++i)
		for (int j = M; j >= items[i].second; --j)
			dp[j] = std::max(dp[j], dp[j - items[i].second] + items[i].first);

	std::cout << *std::max_element(dp, dp + M + 1);

	return 0;
}
