import math

N, M = map(int, input().split(' '))
if N == 0 or M == 0:
    N, M = 0, 0

board = [list(input()) for i in range(0, N)]
sqr_map = set()
max_sqr = -1

def check_sqr(num):
    global max_sqr
    if int(math.sqrt(int(num))) == math.sqrt(int(num)):
        max_sqr = max(max_sqr, int(num))

for i in range(0, N):
    for j in range(0, M):
        for r_cd in range(-N + 1, N):
            for c_cd in range(-M + 1, M):
                if r_cd == 0 and c_cd == 0:
                    check_sqr(board[i][j])
                else:
                    str_num_sum = ""
                    x, y = j, i
                    while (0 <= y < N) and (0 <= x < M):
                        num = board[y][x]
                        str_num_sum += num

                        check_sqr(str_num_sum)
                        check_sqr(str_num_sum[::-1])
                        x += c_cd
                        y += r_cd

                    cache_len = len(str_num_sum) - 1
                    reverse_num_sum = ""
                    for k in range(cache_len, -1, -1):
                        reverse_num_sum += str_num_sum[k]
                        check_sqr(reverse_num_sum)
print(max_sqr)
