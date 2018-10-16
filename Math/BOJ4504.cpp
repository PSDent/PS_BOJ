#include <iostream>
#include <ios>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, input; 
	std::cin >> N;
	
	while (1)
	{
		std::cin >> input;

		if (input == 0) break;
		if (input % N != 0)
			std::cout << input << " is NOT a multiple of " << N << '.' << '\n';
		else if(input % N == 0)
			std::cout << input << " is a multiple of " << N << '.' << '\n';
	}

	return 0;
}
