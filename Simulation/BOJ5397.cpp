#include <iostream>
#include <string>
#include <list>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	std::cin >> N;

	std::string str;
	while (N--)
	{
		std::list<char> lst;
		std::list<char>::iterator iter;
		std::cin >> str;
		iter = lst.begin();

		for (int i = 0; i < str.size(); ++i)
		{
			char ch = str[i];
			if (ch == '<' && iter != lst.begin()) --iter;
			else if (ch == '>' && iter != lst.end()) ++iter;
			else if (ch == '-' && iter != lst.begin())
			{
				--iter;
				iter = lst.erase(iter); 
			}
			else if (ch != '<' && ch != '>' && ch != '-')
			{
				iter = lst.insert(iter, ch);
				++iter;
			}
		}
		
		for (iter = lst.begin(); iter != lst.end(); ++iter)
			std::cout << *iter;
		std::cout << '\n';
	}

	return 0;
}
