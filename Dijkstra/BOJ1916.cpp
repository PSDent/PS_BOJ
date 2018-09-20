#include <iostream>
#include <queue>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();
using Point = std::pair<int, int>;

int dest[100001];
std::vector<Point> v[100001];
std::priority_queue <Point> pq;

bool operator <(Point &left, Point &right)
{
	return left.second < right.second ? true : false;
}

int main()
{
	int start, end;
	int N, M;
	int s, e, c;
	std::cin >> N >> M;
	for (int i = 0; i <= N; ++i) dest[i] = INF;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> s >> e >> c;
		v[s].push_back(std::make_pair(e, c)); // e = dest, c = cost
	}
	std::cin >> start >> end;
	dest[start] = 0;

	pq.push(std::make_pair(start, 0));
	while (!pq.empty())
	{
		int nowEdge = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[nowEdge].size(); ++i)
		{
			int destCity = v[nowEdge][i].first;
			int destCost = v[nowEdge][i].second;
			
			if (cost + destCost < dest[destCity])
			{
				dest[destCity] = cost + destCost;
				pq.push(std::make_pair(destCity, dest[destCity]));
			}
		}
	}
	std::cout << dest[end];

	return 0;
}
