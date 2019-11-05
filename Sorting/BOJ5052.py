import sys

T = int(input())

for i in range(T):
    n = int(input())
    nums = []
    isConsistency = True

    prefix = set()
    for j in range(n):
        nums.append(sys.stdin.readline()[0: -1])

    nums.sort()
    
    for word in nums:
        string = ''
        for ch in word:
            string += ch

            if string in prefix:
                print("NO")
                isConsistency = False
                break

        if isConsistency == False:
            break

        prefix.add(word)

    if isConsistency:
        print("YES")
