x = int(input())

diag_line = 1
dir = True # 0 down 1 up

while diag_line < x:
    x -= diag_line
    diag_line += 1
    dir = not dir

left = diag_line + 1 - x
right = x
if dir:
    print(str(left) + '/' + str(right))
else:
    print(str(right) + '/' + str(left))
