#include <iostream>
#include <string>
#include <ios>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string book, keyword;
	int index = 0;
	int sIndex = 0;

	std::cin >> book >> keyword;

	int Cnt = 0;
	for (int i = 0; i < book.size(); ++i)
	{
		if (book[i] == keyword[index]) {
			++index; ++Cnt;
		}	
		else if (book[i] >= '0' && book[i] <= '9') { continue; }
		else
		{
			index = 0;
			Cnt = 0;
			if (book[i] == keyword[0]) --i;
		}

		if (Cnt == keyword.size())
		{
			std::cout << 1;
			return 0;
		}
	}
	
	std::cout << 0;
	return 0;
}
