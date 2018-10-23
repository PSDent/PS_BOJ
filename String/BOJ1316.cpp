#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool alpha[30];

int main()
{
	int N, cnt = 0;
	string input;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;

		for (int j = 0; j < input.size();)
		{
			char letter = input[j];
			
			if (alpha[letter - 'a'])
				break;

			while (j < input.size() && letter == input[j])
				++j;
			alpha[letter - 'a'] = true;

			if (j == input.size()) ++cnt;
		}
		memset(alpha, 0, sizeof(alpha));
	}

	cout << cnt;
	return 0;
}
