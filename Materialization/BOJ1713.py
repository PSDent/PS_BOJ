import sys
from collections import defaultdict

N = int(input())
K = int(input())
frame = defaultdict(int)
recomm_list = list(map(int, sys.stdin.readline().split()))

for i in range(K):
    num = recomm_list[i]
    if num in frame:
        frame[num][0] += 1
    else:
        if len(frame) < N:
            frame[num] = [1, i]
        else:
            srt_frame = sorted(frame, key=lambda key: (frame[key][0], frame[key][1]) )
            key = srt_frame.pop(0)
            frame.pop(key)
            frame[num] = [1, i]
ans = sorted(list(frame))
for i in range(N):
    print(ans[i], end = ' ')
