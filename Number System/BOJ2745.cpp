#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

int main()
{
	int base, exp, sum = 0;
	std::string input;
	std::cin >> input >> base;
	
	exp = input.size() - 1;
	for (int i = 0; i < input.size(); ++i)
	{
		int val;
		if (isalpha(input[i]))
			val = input[i] - 'A' + 10;
		else
			val = input[i] - '0';
		sum += val * pow(base, exp);
		--exp;
	}
	std::cout << sum;

	return 0;
}
