#include <iostream>
#include <string>

using namespace std;

int N;
int num[12];

void Lotto(int index, int cnt, string str)
{
	str += std::to_string(num[index]) + ' ';
	for (int i = index + 1;  i < N; ++i)
		Lotto(i, cnt + 1, str);
	if (cnt == 6)
		std::cout << str << '\n';
}

int main()
{
	do
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> num[i];
		string str = "";
		for(int i = 0; N - i >= 6; ++i)
			Lotto(i, 1, str);
		std::cout << '\n';
	} while (N != 0);

	return 0;
}
