"""
baekjoon : 6236


- 입력1
7 5
100
400
300
100
500
101
400


- 출력1
500
"""
import time 

def check( k, arr, n ):
    init_k = k
    remain = k
    cnt = 1
    for v in arr:
        if v <= remain:
            remain -= v
        else:
            cnt += 1
            if n < cnt: # over cnt
                return False
            remain = init_k - v
    print(cnt)
    return True


def solution(k, arr, n):
    left = max(arr)
    right = sum(arr)
    res = right

    while left <= right:
        mid = (left+right)//2
        if check(mid, arr, n):
            right = mid - 1
            if res > mid:
                res = mid
        else:
            left = mid + 1
        print(mid)
        print('-'*20)
        time.sleep(0.5)
    print(res)
    
    # if cnt > n: # k의 값이 크다. 
    #     return True

arr = [100,400,300,100,500,101,400]
solution(500, arr, 5)
