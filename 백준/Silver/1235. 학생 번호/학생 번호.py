n = int(input())
student_id_numbers = [input().strip() for _ in range(n)]
length = len(student_id_numbers[0])

for digits in range(1, length + 1):
    temp = set(student_id[-digits:] for student_id in student_id_numbers)
    if len(temp) == n:
        print(digits)
        break