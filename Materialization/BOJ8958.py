n = int(input())

for i in range(0, n):
    score = 0
    ans = input().split('X')

    for o in ans:
        o_num = len(o)
        score += int((o_num * (o_num +1)) / 2)
    print(score)
    
