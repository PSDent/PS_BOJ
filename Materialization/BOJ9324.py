n = int(input())

for i in range(n):
  isFail = False
  cnt = [ 0 for x in range(26)]
  msg = input()

  sz = len(msg)
  i = 0

  while i < sz:
    idx = ord(msg[i]) - ord('A')
    cnt[idx] += 1

    if (cnt[idx] > 0 and cnt[idx] % 3 == 0) and (i + 1 == sz or msg[i + 1] != msg[i]):
      print('FAKE')
      isFail = True
      break
    elif cnt[idx] > 0 and cnt[idx] % 3 == 0 and msg[i] == msg[i+1]:
      i += 1
    i += 1
    
  if isFail == False:
    print('OK')
