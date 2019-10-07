test = int(input())
while test:
    n = int(input())
    correct_ans = input()
    chef_answer = input()
    score = 0
    dont_grade = False
    for x in range(0, n):
        if dont_grade:
            dont_grade = False
            continue
        elif chef_answer[x] == correct_ans[x]:
            score += 1
        else:
            if chef_answer[x] == 'N':
                score += 0
            else:
                dont_grade = True
    print(score)
    test -= 1
