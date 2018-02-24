#include <iostream>

int A[50], B[50];

void InsertSort(int i, bool order)
{
	int temp;
	if (order) { // true = 오름차순
		temp = A[i];
		for (int j = i - 1; j >= 0; j--) {
			if (temp <= A[j]) {
				A[j + 1] = A[j];
				A[j] = temp;
			}
			else
				break;
		}
	}
	else {       // false = 내림차순
		temp = B[i];
		for (int j = i - 1; j >= 0; j--) {
			if (temp >= B[j]) {
				B[j + 1] = B[j];
				B[j] = temp;
			}
			else
				break;
		}
	}

	return;
}

int main()
{
	int N, sum = 0;

	std::cin >> N;

	for (int i = 0; i < N; i++) { // A[]
		std::cin >> A[i];
		InsertSort(i, true);
	}

	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
		InsertSort(i, false);
	}

	for (int i = 0; i < N; i++) 
		sum += A[i] * B[i];
	std::cout << sum;

	return 0;
}