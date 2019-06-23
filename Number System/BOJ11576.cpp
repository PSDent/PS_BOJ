#include <iostream>
#include <cmath>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int A, B;
	int N, sum = 0, base;
	std::cin >> A >> B >> N;
	base = N - 1;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;
		sum += pow(A, base) * input;
		--base;
	}

	std::stack<int> st;
	do
	{
		st.push(sum % B);
		sum -= sum % B;
		sum /= B;
	} while (sum);

	int sz = st.size();
	for (int i = 0; i < sz; ++i)
	{
		std::cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}
