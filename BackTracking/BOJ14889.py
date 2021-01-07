N = int(input())
table = list()
team = [0 for x in range(N)]
team_score = [0, 0]
min_diff = 100000

def calc_team_score():
    global team_score, min_diff, team

    for i in range(N):
        for j in range(i + 1, N):
            if team[i] == team[j]:
                team_score[team[i]] += table[i][j] + table[j][i]

    min_diff = min(min_diff, abs(team_score[0] - team_score[1]))
    team_score = [0, 0]

def make_team(idx, cnt):
    global team

    team[idx] = 1

    if cnt == 0:
        calc_team_score()
        team[idx] = 0
        return

    for i in range(idx + 1, N - cnt + 1):
        make_team(i, cnt - 1)
    team[idx] = 0

for i in range(0, N):
    table.append(list(map(int, input().split(' '))))

for i in range(0, N // 2 + 1):
    make_team(i, N // 2 - 1)

print(min_diff)
