#include <iostream>
#include <stack>

int main()
{
	char input;
	std::stack<char> bar;
	std::stack<int> laser;

	int local = 0, cnt = 0;
	bool isLaser = true;
	while (std::cin >> input)
	{
		if (input == ')')
		{
			if (isLaser)
			{
				bar.pop();
				if (!bar.empty()) 
				{
					bar.push('@');
					laser.push(1);
				}
				isLaser = false;
			}
			else
			{
				if (bar.top() != '@')
					bar.pop();
				else
				{
					while (bar.top() == '@')
					{
						local = laser.top() + local;
						laser.pop();
						bar.pop();
					}
					bar.pop();
					bar.push('@');
					laser.push(local);
					cnt += local + 1;
					local = 0;
				}
			}
		}
		else
		{
			bar.push('(');
			isLaser = true;
		}

	}
	std::cout << cnt;

	return 0;
}
