nums = [int(x) for x in input().split()]
idxs = []
abc = input()
nums.sort()

for alphabet in abc:
    idx = ord(alphabet) - ord('A')
    print(nums[idx], end = ' ')
