#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int Printer(queue<pair<int, int>> &queue, priority_queue<int> &pQueue)
{
	int cnt = 0;

	while (!queue.empty())
	{
		pair<int, int> qTemp = queue.front();
		int pqTemp = pQueue.top();

		queue.pop();
		if (pqTemp == qTemp.first)
		{
			pQueue.pop();
			++cnt;
			if (qTemp.second)
				break;
		}
		else
		{
			queue.push(qTemp);
		}
	}

	return cnt;
}

int main()
{
	int N, amount, findNum;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> amount >> findNum;

		queue<pair<int, int>> queue;
		priority_queue<int> pQueue;
		for (int j = 0; j < amount; ++j) {
			int importance;
			pair<int, int> pair;

			std::cin >> importance;
			
			if (findNum == j)
			{
				pair.first = importance;
				pair.second = 1;
			}
			else
			{
				pair.first = importance;
				pair.second = 0;
			}
			
			queue.push(pair);
			pQueue.push(pair.first);
		}

		std::cout << Printer(queue, pQueue) << '\n';
	}

	return 0;
}
