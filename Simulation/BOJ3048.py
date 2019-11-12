N1, N2 = map(int, input().split())

antMap = dict()
N1_ant, N2_ant, T = list(input()), list(input()), int(input())
N1_ant.reverse()
ants = N1_ant + N2_ant

for i in range(N1):
  antMap[N1_ant[i]] = 'L'
for i in range(N2):
  antMap[N2_ant[i]] = 'R'

while T > 0:
  movedSet = set()
  for i in range(N1 + N2 - 1):
    if ants[i] not in movedSet and ants[i+1] not in movedSet:
      if antMap[ants[i]] == 'L' and antMap[ants[i+1]] == 'R':
        ants[i], ants[i+1] = ants[i+1], ants[i]
        movedSet.add(ants[i])
        movedSet.add(ants[i+1])

  T -= 1

print(''.join(ants))
