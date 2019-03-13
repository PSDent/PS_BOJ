#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::string str;
	std::vector<std::string> v;
	std::cin >> str;

	for (int i = 0; i < str.size(); ++i)
		v.push_back(str.substr(i, str.size() - i));

	std::sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << '\n';
	return 0;
}
