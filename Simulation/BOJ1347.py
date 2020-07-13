dir_x = [0, 1, 0, -1]
dir_y = [1, 0, -1, 0]

maze = [[' ' for j in range(0, 101)] for i in range(0, 101)]

N = int(input())
move_log = input()

lx, ly, rx, ry = 50, 50, 50, 50
px, py, dir = 50, 50, 0

maze[py][px] = '.'

for log in move_log:
    if log == 'R':
        dir = (dir - 1) % 4
    elif log == 'L':
        dir = (dir + 1) % 4
    else:
        nx = dir_x[dir]
        ny = dir_y[dir]

        px += nx
        py += ny

        if py < ry:
            ry += ny
        if px > rx:
            rx += nx
        if py > ly:
            ly += ny
        if px < lx:
            lx += nx
        maze[py][px] = '.'

for i in range(ry, ly + 1):
    line = []
    for j in range(lx, rx + 1):
        if maze[i][j] == '.':
            line.append('.')
        else:
            line.append('#')
    print(*line, sep='')
