#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string heard[500000];
string never[500000];
int cnt = 0, neverIndex = 0;
int N, M;

void BinarySearch(string str)
{
	int low = 0, high = N - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		
		// 
		if (str.compare(heard[mid]) > 0)
		{
			low = mid + 1;
		}
		else if (str.compare(heard[mid]) < 0)
		{
			high = mid - 1;
		}
		else
		{
			never[neverIndex++] = str;
			return;
		}
	}
}

int main()
{
	cin >> N >> M;

	string input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		heard[i] = input;
	}

	sort(heard, heard + N);

	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		BinarySearch(input);
	}
	sort(never, never + neverIndex);

	cout << neverIndex << '\n';

	for (int i = 0; i < neverIndex; ++i)
		cout << never[i] << '\n';
	
	return 0;
}
