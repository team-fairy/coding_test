# n <= 50, len(a) <= 1000
n = int(input())
a = list(map(int,input().split()))
# a = [2,3,1] b = [1,2,3] p = [1,2,0]
b = sorted(a)
result = []
for i in a:
    k = b.index(i)
    b[k] = 1e9
    result.append(k)

result = ' '.join(map(str,result))
print(result)