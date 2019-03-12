#include <iostream>
#include <list>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::list<char> ls;
	std::string str;
	std::cin >> str;

	for (int i = 0; i < str.size(); ++i)
		ls.push_back(str[i]);

	std::list<char>::iterator iter = ls.end();
	int N;
	char cmd, ch;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> cmd;

		if (cmd == 'L')
		{
			if(iter != ls.begin())
				--iter;
		}
		else if (cmd == 'D')
		{
			if (iter != ls.end())
				++iter;
		}

		else if (cmd == 'B')
		{
			if (iter != ls.begin())
			{
				if (iter != ls.end())
					iter = ls.erase(--iter);
				else
				{
					ls.erase(--iter);
					iter = ls.end();
				}
			}
		}
		else
		{
			std::cin >> ch;
			ls.insert(iter, ch);
			//++iter;
		}
		//for (iter = ls.begin(); iter != ls.end(); ++iter)
		//	std::cout << *iter;
		//std::cout << '\n';
	}

	for (iter = ls.begin(); iter != ls.end(); ++iter)
		std::cout << *iter;
	return 0;
}