import sys

N = int(input())

minCnt = 36
minPair = []
pictures = [[[0 for _ in range(7)] for _ in range(5)] for _ in range(51)]

for i in range(1, N + 1):
  for j in range(5):
    pictures[i][j] = sys.stdin.readline()

for i in range(1, N):
  for e in range(i + 1, N + 1):
    cnt = 0
    for j in range(5):
      for k in range(7):
        if pictures[i][j][k] != pictures[e][j][k]:
          cnt += 1
    
    if cnt < minCnt:
      minCnt = cnt
      minPair = [i, e]
minPair.sort()
print(f'{ minPair[0] } { minPair[1] }')
