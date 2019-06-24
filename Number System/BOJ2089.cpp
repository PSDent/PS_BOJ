#include <iostream>
#include <stack>

int main()
{
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::stack<int> st;
	std::cin >> N;

	do
	{
		int quotient, remainder;
		if (N % -2 == -1)
		{
			quotient = N / -2 + 1;
			remainder = 1;
		}
		else
		{
			remainder = N % -2;
			quotient = N / -2;
		}
		st.push(remainder);

		N -= remainder;
		N = quotient;
	} while (N);

	int len = st.size();
	for (int i = 0; i < len; ++i)
	{
		std::cout << st.top();
		st.pop();
	}

	return 0;
}
