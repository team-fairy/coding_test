a, b = list(map(int, input().split()))

memo = []

cnt = 1
while len(memo) < b:
    for _ in range(cnt):
        memo.append(cnt)
    cnt += 1

print(sum(memo[a-1:b]))
