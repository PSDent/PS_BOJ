import sys

H, W = map(int, input().split())
area = []
forecast = [ [-1 for _ in range(W)] for _ in range(H)]

for i in range(H):
  area.append(list(sys.stdin.readline()))

  time = -1
  for j in range(W):
    if area[i][j] == 'c':
      time = 0
    elif area[i][j] == '.' and time >= 0:
      time += 1
    else:
      continue

    forecast[i][j] = time

for i in range(H):
  print(*forecast[i], sep = ' ')
