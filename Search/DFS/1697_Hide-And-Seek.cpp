//================================================
// Filename : 1697_Hide-And-Seek
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1697
//================================================

#include <iostream>

int minCnt, K;

void DFS(int n, int cnt)
{
	if (n == K && cnt < minCnt)
	{
		minCnt = cnt;
		return;
	}



}

int main()
{	
	int N;
	std::cin >> N >> K;
	minCnt = N + K;
	
	DFS(N, 0);

	return 0;
}