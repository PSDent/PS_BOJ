N = int(input())
M = int(input())
targets = list(map(int, input().split(' ')))
player = [0 for i in range(0, N)]

for i in range(0, M):
    target_paper = list(map(int, input().split(' ')))

    target = targets[i]
    fails = 0
    for j in range(0, N):
        if target_paper[j] == target:
            player[j] += 1
        else:
            fails += 1
    player[target - 1] += fails

for i in range(0, N):
    print(player[i])
