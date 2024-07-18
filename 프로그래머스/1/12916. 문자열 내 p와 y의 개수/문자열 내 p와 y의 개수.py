def solution(s):
    answer = True
    cnt1 = 0
    cnt2 = 0
    isno = 0
    
    for i in range(len(s)) :
        if s[i] == 'p' or s[i] == 'P' : cnt1 += 1
        elif s[i] == 'y' or s[i] == 'Y': cnt2 += 1
        else : isno += 1
        
    if cnt1 == cnt2 or isno == len(s) : answer = True
    else : answer = False

    return answer