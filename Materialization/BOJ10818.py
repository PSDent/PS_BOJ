N = int(input())

min_val, max_val = 1000000, -1000000

for val in list(map(int, input().split(' '))):
    min_val = min(val, min_val)
    max_val = max(val, max_val)

print(f"{min_val} {max_val}")
