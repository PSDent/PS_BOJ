constructor = [False for x in range(10001)]

def d(n):
    if constructor[n]:
        return

    for num in str(n):
        n += int(num)
    
    if n <= 10000:
        d(n)
        constructor[n] = True
    
for i in range(1, 10001):
    d(i)
    if not constructor[i]:
        print(i)
