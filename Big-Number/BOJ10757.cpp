#include <iostream>
#include <cstring>

char input1[10001], input2[10001];
char sum[10002];
int len1, len2;

void Replace()
{
	for (int i = 1; i <= len2; i++) 
		input2[len1 - i] = input2[len2 - i];
	for (int i = 0; i < len1 - len2; i++)
		input2[i] = '0';
}

int main()
{
	std::cin >> input1 >> input2;
	len1 = strlen(input1);
	len2 = strlen(input2);

	if (len2 > len1) {
		char temp[10001];
		strcpy(temp, input1);
		strcpy(input1, input2);
		strcpy(input2, temp);

		int temp_len = len1;
		len1 = len2;
		len2 = temp_len;
	}

	if(len1 != len2)
		Replace();

	for (int i = 1; i <= len1; i++) {
		int temp = input1[len1 - i] + input2[len1 - i] - 96;
		sum[10002 - i] += temp % 10;
		if (sum[10002 - i] == 10) {
			sum[10002 - i] = 0;
			sum[10002 - i - 1] += 1;
		}
		sum[10002 - i - 1] += temp / 10;
	}

	int i = 0;

	while (sum[i] == '\0')
		i++;

	while(i < 10002)
		std::cout << (char)(sum[i++] + '0');

	return 0;
}