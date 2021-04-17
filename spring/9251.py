def maxLCS(str1, str2):
    LCS = [[0 for _ in range(len(str1))] for _ in range(len(str2))]
    max_length = 0
    prev = 0
    for i in range(len(str1)):
        if str1[i] == str2[0] and prev == 0:
            prev = 1
        LCS[0][i] = prev
    prev = 0
    for i in range(len(str2)):
        if str1[0] == str2[i] and prev == 0:
            prev = 1
        LCS[i][0] = prev

    for i in range(1, len(str2)):
        for j in range(1, len(str1)):
            if str1[j] == str2[i]:
                LCS[i][j] = LCS[i-1][j-1] + 1
            else:
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
    return LCS[-1][-1]

str1 = input()
str2 = input()

print(maxLCS(str1, str2))