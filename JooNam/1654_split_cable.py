"""
랜선 자르기 
baekjoon -1654

input
4 11
802
743
457
539

output
500

"""

import time 


def solution_print(n, arr):
    low = 1
    high = max(arr)
    res = 0

    while low <= high:
        mid = (low + high)//2
        print("mid {}".format(mid))
        cable_cnt = 0
        for i in arr:
            cable_cnt += i // mid
        print(cable_cnt)
        time.sleep(1)
        if cable_cnt < n:
            print( f"high <-- mid {high} <--{mid-1}")
            high = mid-1
            print(f"low : {low} high : {high}")
            
        else:
            if res <= mid:
                res = mid 
            print( f"low <-- mid {low} <--{mid+1}")
            print(f"res {res}")
            low = mid+1
            print(f"low : {low} high : {high}")
            
        print('-'*20)
    return res


arr = [802,743,457,539]
print(solution_print(11,arr))

# iter_, n = map(int, input().split( ))
# arr = [int(input()) for _ in range(iter_)]
# print(solution(n,arr))



def solution(n, arr):
    low = 1
    high = max(arr)
    res = 0

    while low <= high:
        mid = (low + high)//2
        cable_cnt = 0
        for i in arr:
            cable_cnt += i // mid

        if cable_cnt < n:
            high = mid-1
        else:
            if res <= mid:
                res = mid 
            low = mid+1
    return res



arr = [802,743,457,539]
print(solution(11,arr))

# iter_, n = map(int, input().split( ))
# arr = [int(input()) for _ in range(iter_)]
# print(solution(n,arr))

arr = [900,1200,500,200]
print(solution(4,arr))


