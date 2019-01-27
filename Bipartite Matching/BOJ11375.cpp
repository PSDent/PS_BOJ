#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> job[1001];
bool visited[1001];
int visitedV[1001], N, M;

bool DFS(int v)
{
	if (visited[v]) return false;
	visited[v] = true;
	for (int i = 0; i < job[v].size(); ++i)
	{
		int work = job[v][i];
		if (!visitedV[work] || DFS(visitedV[work]))
		{
			visitedV[work] = v;
			return true;
		}
	}

	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int input;
		std::cin >> input;
		for (int j = 1; j <= input; ++j)
		{
			int num;
			std::cin >> num;
			job[i].push_back(num);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		std::fill(visited + 1, visited + 1 + N, false);
		if (DFS(i)) {
			++cnt;
		}
	}
	std::cout << cnt;

	return 0;
}