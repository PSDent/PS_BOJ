cost = []
dp = [[0 for x in range(0, 3)] for y in range(0, 1000)]
INF = 10000000

N = int(input())

for i in range(0, N):
    cost.append(list(map(int, input().split(' '))))

dp[0][0], dp[0][1], dp[0][2] = cost[0][0], cost[0][1], cost[0][2]

min_cost = INF
for i in range(0, 3):
    dp[1][i] = INF

    dp[1][(i + 1) % 3] = dp[0][i] + cost[1][(i + 1) % 3]
    dp[1][(i + 2) % 3] = dp[0][i] + cost[1][(i + 2) % 3]

    for j in range(2, N):
        for k in range(0, 3):
            dp[j][k] = min(dp[j-1][(k + 1) % 3], dp[j-1][(k + 2) % 3]) + cost[j][k]

    min_cost = min(min_cost, min(dp[N-1][(i + 1) % 3], dp[N-1][(i + 2) % 3]))

print(min_cost)
