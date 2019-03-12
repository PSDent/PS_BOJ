#include <iostream>
#include <string>

int main()
{
	std::string a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::cout << std::stoll(a + b) + std::stoll(c + d);

	return 0;
}
