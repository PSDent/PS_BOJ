#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using LL = long long;

std::vector<LL> arr, tree;

LL Init(int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];
	
	int mid = (start + end) / 2;

	return tree[node] = std::min(Init(node * 2, start, mid), Init(node * 2 + 1, mid + 1, end));
}

LL Min(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return (LL)1000000001;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return std::min(Min(node * 2, start, mid, left, right), Min(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, input;
	std::cin >> N >> M;

	int height = (int)ceil(log2(N)) + 1;
	int size = pow(2, height);
	tree.resize(size);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		arr.push_back(input);
	}

	Init(1, 0, N - 1);

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;
		std::cout << Min(1, 0, N - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}
