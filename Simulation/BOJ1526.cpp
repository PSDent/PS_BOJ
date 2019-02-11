#include <iostream>
#include <string>
#include <deque>

int main()
{
	std::string N, ans;
	std::cin >> N;

	bool up = false;
	for (int i = 0; i < N.size(); ++i)
	{
		if (N[i] > '7')
		{
			ans.push_back('7');
			for (int j = i + 1; j < N.size(); ++j)
				N[j] = '9';
		}
		else if (N[i] == '7')
		{
			if (i + 1 < N.size() && (N[i + 1] < '4'))
			{
				ans.push_back('4');
				for (int j = i + 1; j < N.size(); ++j)
					N[j] = '9';
			}
			else
				ans.push_back('7');
		}
		else if (N[i] > '4')
		{
			ans.push_back('4');
			for (int j = i + 1; j < N.size(); ++j)
				N[j] = '9';
		}
		else if (N[i] == '4')
		{
			if (i + 1 < N.size() && (N[i + 1] < '4'))
			{
				for (int j = i + 1; j < N.size(); ++j)
					N[j] = '9';
			}
			else
				ans.push_back('4');
		}
		else if(N[i] > '0')
		{
			N[i] = N[i] - 1;
			for (int j = i + 1; j < N.size(); ++j)
				N[j] = '9';
		}
	}
	std::cout << ans;

	return 0;
}
