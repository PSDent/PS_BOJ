#include <iostream>

int main()
{
	int N, lVal, rVal;
	int nowWhere = 1;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> lVal >> rVal;
		if (lVal == nowWhere || rVal == nowWhere)
		{
			int temp = lVal;
			lVal = rVal;
			rVal = temp;
			nowWhere = nowWhere != lVal ? lVal : rVal;
		}
	}

	std::cout << nowWhere;
	return 0;
}
