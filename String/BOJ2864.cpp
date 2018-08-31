#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string A, B;
	int aMin, aMax, bMin, bMax;

	std::cin >> A >> B;

	std::replace(A.begin(), A.end(), '6', '5');
	aMin = std::stoi(A, nullptr, 10);
	
	std::replace(A.begin(), A.end(), '5', '6');
	aMax = std::stoi(A, nullptr, 10);

	std::replace(B.begin(), B.end(), '6', '5');
	bMin = std::stoi(B, nullptr, 10);

	std::replace(B.begin(), B.end(), '5', '6');
	bMax = std::stoi(B, nullptr, 10);

	std::cout << aMin + bMin << ' ' << aMax + bMax;

	return 0;
}
