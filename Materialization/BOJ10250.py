T = int(input())

for i in range(0, T):
    H, W, N = list(map(int, input().split(' ')))

    y = N % H if N % H > 0 else H
    x = N // H + 1 - (1 if N % H == 0 else 0)

    print(str(y) + '{:0>2}'.format(str(x)))
