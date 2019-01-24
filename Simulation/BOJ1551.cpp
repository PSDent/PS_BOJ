#include <iostream>
#include <string>

int arr[21];

int main()
{
	std::string input;
	int N, K;
	std::cin >> N >> K >> input;

	for (int i = 1; i <= N; ++i)
	{
		arr[i] = std::stoi(input.substr(0, input.find(',')));
		input.erase(0, input.find(',') + 1);
	}

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N - i; ++j)
			arr[j] = arr[j + 1] - arr[j];
	}

	for (int i = 1; i <= (N * 2 - 1) - K * 2; ++i)
	{
		if (i % 2 == 1) std::cout << arr[i / 2 + 1];
		else std::cout << ',';
	}

	return 0;
}
