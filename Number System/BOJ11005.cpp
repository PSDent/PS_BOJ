#include <iostream>
#include <stack>

std::stack<int> nums;

int main()
{
	int N, B;
	std::cin >> N >> B;

	do
	{
		nums.push(N % B);
		N = (N - N % B) / B;
	} while (N);

	int len = nums.size();
	for (int i = 0; i < len; ++i)
	{
		char num;
		int val = nums.top();
		nums.pop();

		if (val >= 10)
			num = 'A' + val - 10;
		else
			num = val + '0';
		std::cout << num;
	}

	return 0;
}
