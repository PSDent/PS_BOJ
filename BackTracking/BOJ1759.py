def passwordGen(idx, password, cCnt, vCnt):
  password += alphabet[idx]

  if table[alphabet[idx]]:
    vCnt += 1
  else:
    cCnt += 1
  
  if len(password) == L and checkPassword(cCnt, vCnt):
    answer.append(password)
    return None

  for i in range(idx + 1, C):
    passwordGen(i, password, cCnt, vCnt)

def checkPassword(c, v):
  if c >= 2 and v >= 1:
    return True
  else:
    return False

L, C = map(int, input().split())

answer = []
table = { chr(x + ord('a')) : 0 for x in range(0, 26)}
table['a'], table['e'], table['i'], table['o'], table['u'] = 1, 1, 1, 1, 1

alphabet = input().split()
alphabet.sort()

limit = len(alphabet) - L
for i in range(0, limit + 1):
  passwordGen(i, '', 0, 0)
answer.sort()

for password in answer:
  print(password)
