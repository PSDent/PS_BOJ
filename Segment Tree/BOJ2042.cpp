#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using LL = long long;

int N, M, K;
vector<long long> sgt;
vector<LL> arr, tree;

LL Init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

void Update(int node, int start, int end, int change, LL diff)
{
	if ( change < start || change > end) return;

	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		Update(node * 2, start, mid, change, diff);
		Update(node * 2 + 1, mid + 1, end, change, diff);
	}
}

LL Sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int input;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		arr.push_back(input);
	}

	int height = (int)ceil(log2(N));
	int treeSize = pow(2, (height + 1));
	tree.resize(treeSize);

	Init(1, 0, N - 1);

	int a, b, c;
	for (int i = 0; i < M + K; ++i)
	{
		std::cin >> a >> b >> c;

		if (a == 1)
		{
			LL diff = c - arr[b - 1];
			arr[b - 1] = c;
			Update(1, 0, N - 1, b - 1, diff);
		}
		else
		{
			std::cout << Sum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}