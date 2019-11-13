import sys

board, dices = [0], []
N, M = map(int, input().split())
cnt, pos = 0, 1

for i in range(N):
  board.append(int(sys.stdin.readline()))

for i in range(M):
  dices.append(int(sys.stdin.readline()))

for num in dices:
  cnt += 1
  pos += num
  if pos >= N:
    print(cnt)
    break

  pos += board[pos]

  if pos >= N:
    print(cnt)
    break
