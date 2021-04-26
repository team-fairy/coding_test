"""
피보나치 수열 만들기
https://www.acmicpc.net/problem/2748

input 
10
output
55
"""


def pibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif dp[n-1] != 0:
        return dp[n-1]
    dp[n-1] = pibonacci(n-1) + pibonacci(n-2)
    return dp[n-1]
n = int(input())
dp = [0]*n
print(pibonacci(n))
