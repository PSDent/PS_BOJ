import sys

board = [[0 for _ in range(101)] for _ in range(101)]
bots = [[0 for _ in range(3)] for _ in range(101)]
n_to_d = {0 : 'N', 1 : 'E', 2 : 'S', 3 : 'W'} 
d_to_n = {'N' : 0, 'E' : 1, 'S' : 2, 'W': 3 }
dirX, dirY = [0, 1, 0, -1], [1, 0, -1, 0]

A, B = map(int, input().split())
N, M = map(int, input().split())

for i in range(1, N + 1):
  info = sys.stdin.readline().split()
  bots[i][0], bots[i][1], bots[i][2] = int(info[0]), int(info[1]), info[2]
  board[bots[i][1]][bots[i][0]] = i

cmds = []
for i in range(M):
  cmds.append(sys.stdin.readline().split())

for i in range(M):
  idx, type, num = int(cmds[i][0]), cmds[i][1], int(cmds[i][2])
  for j in range(num):
    bot_dir = bots[idx][2]
    if type == 'L':
       nDir = n_to_d[(d_to_n[bot_dir] + 3) % 4]
       bots[idx][2] = nDir
    elif type == 'R':
       nDir = n_to_d[(d_to_n[bot_dir] + 1) % 4]
       bots[idx][2] = nDir
    elif type == 'F':
      x, y = bots[idx][0], bots[idx][1]
      dirNum = d_to_n[bots[idx][2]]

      board[y][x] = 0
      x += dirX[dirNum]
      y += dirY[dirNum]
      
      if x < 1 or x > A or y < 1 or y > B:
        print(f'Robot {idx} crashes into the wall')
        sys.exit(0)

      if board[y][x]:
        print(f'Robot {idx} crashes into robot {board[y][x]}')
        sys.exit(0)

      bots[idx][0], bots[idx][1] = x, y
      board[y][x] = idx

print('OK')
