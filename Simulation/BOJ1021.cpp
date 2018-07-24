#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

int main()
{
	int N, M, input, pos, cnt = 0;
	
	std::deque<int> dq;
	std::deque<int>::iterator iter;

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> input;
		dq.push_back(input);
	}

	for (int i = 0; i < M; ++i)
	{
		int left = dq.front() - 1;
		int right = N - dq.front() + 1;

		if (left < right)
		{
			pos = left; 
			cnt += left;
		}
		else
		{
			pos = -right;
			cnt += right;
		}
		
		for (iter = dq.begin(); iter != dq.end(); ++iter)
		{
			*iter -= pos;
			if (*iter > N) *iter = *iter - N;
			else if (*iter < 1) *iter = *iter + N;
		}

		--N;
		dq.pop_front();

		for (iter = dq.begin(); iter != dq.end(); ++iter)
			*iter -= 1;
	}
	std::cout << cnt;
}
