from collections import Counter

s, t = map(int, input().split())
dna_string = input()
minimum_count = Counter({nucleotide : count for nucleotide, count in zip(['A', 'C', 'G', 'T'], map(int, input().split()))})
substring_count = Counter(dna_string[:t])
cnt = 1 if substring_count >= minimum_count else 0

for i in range(1, s - t + 1):
    substring_count[dna_string[i + t - 1]] += 1
    substring_count[dna_string[i - 1]] -= 1
    if substring_count >= minimum_count: cnt += 1

print(cnt)