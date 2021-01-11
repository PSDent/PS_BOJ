x = int(input())
y = int(input())

quadrant = [1, 4, 2, 3]
bit = [0, 0]

if x < 0:
    bit[0] = 1
if y < 0:
    bit[1] = 1

dec = bit[0] * 2 + bit[1] * 1
print(quadrant[dec])
