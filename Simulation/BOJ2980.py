import sys

N, L = map(int, input().split())

traffics, trafficDict = [], dict()
pos, time = 0, 0

for i in range(N):
  traffics.append( list(map(int, sys.stdin.readline().split())) )
  trafficDict[traffics[i][0]] = [False, traffics[i][1]]

while pos < L:
  time += 1
  
  if pos not in trafficDict or trafficDict[pos][0] == True:
    pos += 1

  for traffic in traffics:
    idx, r, g = traffic[0], traffic[1], traffic[2]

    if trafficDict[idx][1] == time:
      trafficDict[idx][0] = not trafficDict[idx][0]
      
      if trafficDict[idx][0] == False:
        trafficDict[idx][1] += r
      else:
        trafficDict[idx][1] += g

print(time)
