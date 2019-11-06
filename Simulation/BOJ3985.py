import sys

L = int(input()) 
N = int(input())
audience = []
cake = [ 0 for x in range(L+1)]
first, secondCnt, secondIdx = 0, 0, 0

for i in range(N):
  P, K = map(int, sys.stdin.readline().split())

  audience.append([P, K])

  if audience[i][1] - audience[i][0] > audience[first][1] - audience[first][0]:
    first = i

  cnt = 0
  for j in range(P, K+1):
    if cake[j] == 0:
      cnt += 1
      cake[j] = 1
  
  if cnt > secondCnt:
    secondCnt = cnt
    secondIdx = i

print(first + 1)
print(secondIdx + 1)
