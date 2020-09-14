import re

num_expr = re.compile(r"\d+")
oper_expr = re.compile(r"[+-]")

expr_input = input()

nums = list(map(int, num_expr.findall(expr_input)))
opers = oper_expr.findall(expr_input)
nums_sum = nums[0]

for i in range(0, len(opers)):
    if opers[i] == '-':
        nums_sum -= sum([nums[i] for i in range(i + 1, len(nums))])
        break       
    nums_sum += nums[i + 1]
print(nums_sum)
