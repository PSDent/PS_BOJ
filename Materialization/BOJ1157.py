cnts = [0 for i in range(26)]

s = input()

for ch in s:
    cnts[ord(ch.lower()) - ord('a')] += 1

max_cnt = 0
max_cnt_idx = 0
for i in range(0, 26):
    cnt = cnts[i]
    if cnt > max_cnt:
        max_cnt = cnt
        max_cnt_idx = i

if cnts.count(max_cnt) == 1:
    print(chr(max_cnt_idx + ord('a')).upper())
else:
    print("?")
