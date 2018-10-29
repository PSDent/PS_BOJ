#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
	std::deque<int> pdq, ndq;
	int N, input, sum = 0;

	std::cin >> N;
	for(int i = 0; i < N; ++i){
		std::cin >> input;
		if (input > 0) pdq.push_back(input);
		else ndq.push_back(input);
	}
	
	std::sort(pdq.begin(), pdq.end(), std::greater<int>());
	std::sort(ndq.begin(), ndq.end(), std::less<int>());

	for (; pdq.size() / 2 >= 1;)
	{
		int first = pdq.front();
		pdq.pop_front();
		int second = pdq.front();
		pdq.pop_front();
		if (second != 1) sum += first * second;
		else sum += first + second;
	}
	if(pdq.size()) sum += pdq.front();

	for (; ndq.size() / 2 >= 1;)
	{
		int first = ndq.front();
		ndq.pop_front();
		int second = ndq.front();
		ndq.pop_front();
		sum += first * second;
	}
	if(ndq.size()) sum += ndq.front();

	std::cout << sum;

	return 0;
}
