import sys

N, C = map(int, input().split())
fireworksSet = set()

for i in range(N):
    fireworksSet.add(int(sys.stdin.readline()[:-1]))

fireworks = list(fireworksSet)
sz = len(fireworks)

day = 0
days = [ 0 for x in range(C + 1)]

for i in range(sz):
    for j in range(1, C + 1):
        if j % fireworks[i] == 0:
            if days[j] == 0:
                day += 1
            days[j] += 1

print(day)
