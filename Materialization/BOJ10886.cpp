#include <iostream>

int main()
{
	int answer[2] = { 0, 0 };
	int n, input;

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input;
		++answer[input];
	}

	if (answer[0] > answer[1])
		std::cout << "Junhee is not cute!";
	else
		std::cout << "Junhee is cute!";	

	return 0;
}
