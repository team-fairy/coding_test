N = int(input())
for _ in range(N):
    num, idx = map(int, input().split())
    arr = [int(oper) for oper in input().split()]
    answer = 0

    while arr:
        target = arr[0]
        if target == max(arr):
            answer += 1
            if idx == 0:
                break			
        else:
            arr.append(target)
            if idx == 0:
                idx = len(arr) - 1 # pop을 이후에 해주므로
                
        arr.pop(0) ##
        idx -= 1
    print(answer)
