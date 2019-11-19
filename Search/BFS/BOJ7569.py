import sys
import collections

box = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]
direction = [[0, -1, 0], [0, 0, 1], [0, 1, 0], [0, 0, -1], [1, 0, 0], [-1, 0, 0]]
M, N, H = map(int, input().split())
o_tomato, z_tomato, n_tomato = 0, 0, 0
q = collections.deque()

for i in range(H):
  for j in range(N):
    tomatos = list(map(int, sys.stdin.readline().split()))

    for k in range(M):
      tomato = tomatos[k]
      if tomato == 1:
        o_tomato += 1
        q.append([i,j,k])
        
      elif tomato == 0: z_tomato += 1
      else: n_tomato += 1
      box[i][j][k] = tomato

if z_tomato == 0 and o_tomato:
  print(0)
  sys.exit(0)
elif o_tomato == 0 and z_tomato == 0:
  print(-1)
  sys.exit(0)

day = 0

while len(q):
  length = len(q)
  for i in range(length):
    tomato = q.popleft()

    for j in range(6):
      nh, ny, nx = direction[j]
      nh += tomato[0]
      ny += tomato[1]
      nx += tomato[2]
      
      if 0 <= nh < H and 0 <= ny < N and 0 <= nx < M:
        if box[nh][ny][nx] == 0:
          box[nh][ny][nx] = 1
          q.append([nh, ny, nx])
          o_tomato += 1
          z_tomato -= 1
  if len(q):
    day += 1

if z_tomato > 0:
  print(-1)
  sys.exit(0)

print(day)
