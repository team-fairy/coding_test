n = int(input())
l1 = list(map(int,input().split()))
answer = [0 for _ in range(n)]
index = 1
for num in l1:
    for i in range(n,0,-1):
        if answer[:i-1].count(0) == num and answer[i-1] == 0:
            answer[i-1] = index
    index += 1
real_answer = ''
for j in answer:
    if real_answer:
        real_answer += ' '
    real_answer += str(j)
print(real_answer)
