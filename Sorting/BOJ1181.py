N = int(input())
words = [ set() for i in range(1001)]

for i in range(N):
    word = input()
    sz = len(word)
    words[sz].add(word)
    
for word in words:
    sortedSet = sorted(word)
    for x in sortedSet:
          print(x)
