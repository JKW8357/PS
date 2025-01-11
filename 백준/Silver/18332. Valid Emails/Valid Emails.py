import re

n = int(input())
pattern = re.compile(r'^(?!.*\.\.)(?!^\..*)(?!.*\.@)(?!.*@\.)(?!.*\.$)[\w.]{6,}@[A-Za-z\d\-.]{3,30}$', re.IGNORECASE)
valid_address = set()

for _ in range(n):
    address = input()
    if re.match(pattern, address):
        username, domain = address.split('@')
        username = re.sub(r'\.', r'', username)
        if 6 <= len(username) <= 30:
            address = f'{username}@{domain}'
            valid_address.add(address.lower())

print(len(valid_address))