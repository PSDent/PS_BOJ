#include <iostream>

int main()
{
	int N, F, modVal, origin;
	std::cin >> N >> F;

	if( (N + F - N % F) % 100 > N % 100) // 자릿수 넘어가지 않는지 확인
		N = N + (F - N % F);
	else
		N = N - N % F;

	modVal = N % 100;
	origin = N - modVal;

	while (modVal - F >= 0) modVal -= F;
	if (modVal < 10)
		std::cout << '0';
	std::cout << modVal;

	return 0;
}
