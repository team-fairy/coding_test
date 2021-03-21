"""
Queue printer
beakjoon -1966

input
6 0
/1/ 1 9 1 1 1 

output
5
"""

# iter view
# 6 0
# /1/ 1 9 1 1 1 


# 1  ## 이동
# 1 9 1 1 1 /1/ ## ans shift
 
# 2
# 9 1 1 1 /1/ 1

# 3  ## if max(else) <= idx : out!
# 9 out // out = 1
# 1 1 1 /1/ 1   ## shift

# 4
# 1 out // out = 2 ## if max(else) <= idx : out!
# 1 1 /1/ 1  ## shift 

# 5 
# 1 out // out = 3
# 1 /1/ 1

# 6
# 1 out // out = 4
# /1/ 1

# 7
# 1 out // out = 5 !! break!
# 1




def solution(l, idx, arr):
    check_list = [0]*l
    check_list[idx] = 1
    outcnt = 0

    left = 0
    while True:
        print(arr)
        print(check_list)
        print('-'*30)
        if l == 1:
            return 1

        if arr[left] == max(arr):
            outcnt += 1
            if check_list[left]:
                return outcnt
            else:
                check_list = check_list[left:]
            check_list.pop(0)
            arr.pop(0)

        else:
            arr = l_pop_r_append(arr)
            check_list = l_pop_r_append(check_list)


def l_pop_r_append(arr):
    arr.append(arr.pop(0))
    return arr


l = 6
idx = 0
arr = [1,1,9,1,1,1]

print(solution(l,idx,arr))


            

# test = input()
# for i in range(int(test)):
#     l, idx = input().split(' ')
#     l = int(l)
#     idx = int(idx)

#     arr = input().split(' ')
#     arr = [int(i) for i in arr]

#     print(solution(l,idx,arr))
# print(test)


# print(solution(l,idx,arr))


print('----')

test = input( "test times" )
for i in range(int(test)):
    l, idx = input("len & idx").split(' ')
    l = int(l)
    idx = int(idx)

    arr = input('arr : ').split(' ')
    arr = [int(i) for i in arr]

    print(solution(l,idx,arr))






    