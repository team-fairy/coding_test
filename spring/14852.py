n = int(input())


if n == 1:
	print(2)
elif n == 2:
	print(7)
else:
	arr = []
	arr.append(2)
	arr.append(7)
	tmp = 1
	for i in range(2, n):
		arr.append((arr[i-1] * 2 + arr[i-2] * 3 + 2 * tmp) % 1000000007)
		tmp += arr[i-2]
	print(arr[-1])
