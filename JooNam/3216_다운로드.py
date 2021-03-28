"""
baekjoon : 3216
다운로드를 받으면서 노래가 끊기지 않을때 까지 듣고 싶을때, 최소한의 시작해야 할 시간은?
https://www.acmicpc.net/problem/3216


input
4
2 1
1 5
3 3
2 4

output
7

## 증가량 기준으로 계산하기..
이전에 필요했던 시간들도 같이 고려하는 것도 좋은 방법.
play_time = [2,1,3,2]
down_load = [1,5,3,4] 

"""
#1 
# 2-1초 
#/ 1초 남은 시간 
#/ +1 

#2 
# 1-5 = -4초 + #1/1 
#/ 0초 남은시간 
#/-3 , --> +3 

#3
# 3-3 = 0초 + 0초 
#/ 0초 남은시간 
#/ ++0

#4
# 4-2 = -2초 + 0초 
#/ 0초 남은시간
#/ ++2


play_times = []
downloads = []
for i in range(int(input())):
    a,d = map(int, input().split())    
    play_times.append(a)
    downloads.append(d)

def solution(play_time, download_time):
    rest_time = play_time[0]
    need_time = download_time[0]

    for i in range(1,len(play_time)):
        gap = download_time[i]-rest_time
        # print(gap)
        need_time += max(gap,0)
        rest_time = abs(min(gap,0))+play_time[i]
    print(need_time)
 
solution(play_times, downloads)
