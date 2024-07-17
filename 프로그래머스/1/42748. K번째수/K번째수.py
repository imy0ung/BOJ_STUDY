def solution(array, commands):
    answer = []
    for i in range(0, len(commands)) :
        x = []
        x = array[commands[i][0] - 1 : commands[i][1]]
        x = sorted(x)
        answer.append(x[commands[i][2]-1])
    return answer