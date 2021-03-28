"""
beakjoon : 2631 줄세우기

https://www.acmicpc.net/problem/2631

줄이 세워저 있는 경우, 정렬 될 수 있는 최소한의 이동은?

input
7
3
7
5
2
6
1
4

output
4

# 핵심
3 7 5 2 6 1 4
에서 이미 정렬 되어있는 부분을 제외한 원소의 갯수가, 최소 이동수가 된다.
/3/ 7 /5/ 2 /6/ 1 4 이렇게 3,5,6 이 arr에서 가장 긴 최대 정렬이 되어 있음으로 (LIS 알고리즘)
이를 제외한 7,2,1,4 4개만 움직이면 되는 것이다.

"""
# arr = [ int(input()) for _ in range(int(input()))]

def solution(line):
    length = len(line)
    dp = [1]*length
    max = 0
    max_arr = 0
    for i in range(1, length):
        
        for j in range(i):
            if (line[i] > line[j]) and (dp[j]+1 > dp[i]):
                dp[i] = dp[j]+1
                print(f"lines : {line}")
                print(f"dp : {dp}", end = '\n\n')
        if dp[i] > max:
            max = dp[i]
    return length-max


lines = [3,7,5,2,6,1,4]
print(solution(lines))             
    
