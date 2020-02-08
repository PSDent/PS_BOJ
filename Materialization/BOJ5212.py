R, C = map(int, input().split())
dirX, dirY = [0, 1, 0, -1], [-1, 0, 1, 0]
island_map = []
lx, ly = C, R
rx, ry = -1, -1

for i in range(0, R):
    line = list(input())
    island_map.append(line)

for y in range(0, R):
    for x in range(0, C):
        if island_map[y][x] == 'X':
            sea_cnt = 0
            for i in range(0, 4):
                dx = x + dirX[i]
                dy = y + dirY[i]

                if dx < 0 or dy < 0 or dx >= C or dy >= R or island_map[dy][dx] == '.':
                    sea_cnt += 1
                    if sea_cnt >= 3:
                        island_map[y][x] = '#'
                        break

            if island_map[y][x] != '#':
                if x < lx:
                    lx = x
                if x > rx:
                    rx = x
                if y < ly:
                    ly = y
                if y > ry:
                    ry = y

for y in range(ly, ry+1):
    for x in range(lx, rx + 1):
        if island_map[y][x] == '#':
            island_map[y][x] = '.'
        print(island_map[y][x], end='')
    print()
