n, k = list(map(int, input().split(' ')))
multiple = 1
number, digit_of_number, digit = 0, 0, 0

for digit in range(1, 10):
    digit_num = 9 * digit * multiple

    if k - digit_num <= 0:
        digit_of_number = k % digit
        number += k // digit + (1 if digit_of_number else 0)
        break
    else:
        number += 9 * multiple
        k -= digit_num

    multiple *= 10

if number > n:
    print(-1)
else:
    print(str(number)[digit_of_number - 1])
