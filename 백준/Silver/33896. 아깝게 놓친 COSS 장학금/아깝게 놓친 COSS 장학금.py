n = int(input())
students = []
for _ in range(n):
    name, score, risk, cost = input().split()
    final_score = (int(score) ** 3) // (int(cost) * (int(risk) + 1))
    students.append([-final_score, int(cost), name])
students.sort()
print(students[1][2])