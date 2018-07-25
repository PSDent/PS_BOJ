#include <iostream>
#include <cmath>

int main()
{
	int N, W, H, root;
	int input;

	std::cin >> N >> W >> H;
	root = sqrt(pow(W,2) + pow(H, 2));

	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;

		if (input <= W || input <= H || input <= root)
			std::cout << "DA" << '\n';
		else
			std::cout << "NE" << '\n';
	}

	return 0;
}
