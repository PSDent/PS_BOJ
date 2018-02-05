#include <iostream>
#include <cstring>

char str1[1001], str2[1001], sub[1001];
int dp[1001][1001];

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int len1, len2; // W, H

	std::cin >> str1 >> str2;

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = len1; i >= 1; i--) str1[i] = str1[i - 1];
	for (int i = len2; i >= 1; i--) str2[i] = str2[i - 1];

	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (str1[j] == str2[i])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	std::cout << dp[len2][len1] << '\n';

	int index = 1001;
	while (dp[len2][len1])
	{
		if (dp[len2][len1 - 1] != dp[len2][len1] && dp[len2 - 1][len1] != dp[len2][len1]) {
			sub[--index] = str2[len2--];
			len1--;
		}
		else if (dp[len2][len1 - 1] == dp[len2][len1])
			len1--;
		else if (dp[len2 - 1][len1] == dp[len2][len1])
			len2--;
	}

	for (int i = index; i <= 1000; i++)
		std::cout << sub[i];

	return 0;
}
