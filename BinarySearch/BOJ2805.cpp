#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using ll = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	ll N, M, max = 0;
	std::map<ll, ll> treeMap;
	std::cin >> N >> M;

	while (N--)
	{
		int input;
		std::cin >> input;
		if (treeMap.find(input) != treeMap.end())
			++treeMap[input];
		else
			treeMap[input] = 1;
	}

	ll left = 0;
	ll right = 2000000000;
	ll mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		ll cnt = 0;
		for (auto tree : treeMap)
		{
			ll treeHeight = tree.first;
			ll treeNum = tree.second;
			if (treeHeight - mid > 0)
				cnt += treeNum * (treeHeight - mid);
		}
		
		if (cnt >= M)
		{
			max = std::max(max, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	std::cout << max;

	return 0;
}
