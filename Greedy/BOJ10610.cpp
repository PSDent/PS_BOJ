#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
         
int cnt[10];

int main()
{
	std::string N;
	int result;
	std::cin >> N;

	int sum = 0;
	for (int i = 0; i < N.size(); ++i)
	{
		++cnt[N[i] - '0'];
		sum += N[i] - '0';
	}
	if (sum % 3 == 0 && cnt[0] >= 1)
		for (int i = 9; i >= 0; --i)
		{
			for (int j = 0; j < cnt[i]; ++j)
				std::cout << i;
		}
	else
		std::cout << -1;

	return 0;
}
