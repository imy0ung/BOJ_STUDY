def solution(s):
    answer = ''
    lst = list(map(int,s.split()))
    mn = min(lst)
    mx = max(lst)
    answer = str(mn) + ' ' + str(mx)
    return answer