#include <iostream>
#include <algorithm>

int aliquot[50];

int main()
{
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> aliquot[i];

	std::sort(aliquot, aliquot + N);

	std::cout << aliquot[0] * aliquot[N - 1];


	return 0;
}
