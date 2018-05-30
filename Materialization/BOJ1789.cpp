#include <iostream>
#include <cmath>

int main()
{
	unsigned int input;
	unsigned int n = 0;

	std::cin >> input;
	n = sqrt(input * 2);

	// 4,294,967,295 를 넣었을시
	// n * (n + 1) 가 unsigned int 범위를 넘으므로 
	// 무한루프가 발생함. 
	// 고로 LL을 곱하여 수를 늘려야 한다. 
	while (1LL * n * (n + 1) / 2 <= input)
		n++;

	std::cout << n - 1;

	return 0;
}
