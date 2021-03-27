import math

input_str = input()
n = int(input_str.split()[0])
m = int(input_str.split()[1])

arr = []

for _ in range(n):
    arr.append(int(input()))

k_min = max(arr)
k_max = sum(arr)
answer = 0

if n == 1:
    print(k_min)
    exit(0)


while k_min < k_max:
    k_mid = (k_min + k_max) // 2
    substr = 1
    tmp = 0
    for i in range(n):
        if tmp + arr[i] > k_mid:
            substr += 1
            tmp = 0
        tmp += arr[i]
    if substr <= m:
        answer = k_mid
        k_max = k_mid
    else:
        k_min = k_mid + 1

if answer == 0:
    answer = math.ceil((k_min + k_max) / 2)
print(answer)