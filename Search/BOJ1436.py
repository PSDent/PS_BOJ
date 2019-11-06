N = int(input()) - 1

endNumsSet = set()
i = 1

while len(endNumsSet) < 10000:
  string = str(i)
  if string.find('666') != -1:
    endNumsSet.add(int(string))
  i += 1

endNums = list(endNumsSet)
endNums.sort()

print(endNums[N])
