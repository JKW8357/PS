s, t = map(int, input().split())
dna_string = input()
minimum_count = {nucleotide : count for nucleotide, count in zip(['A', 'C', 'G', 'T'], map(int, input().split()))}

substring_count = {char: 0 for char in 'ACGT'}
for char in dna_string[:t]:
    substring_count[char] += 1
cnt = 1 if all(substring_count[nucleotide] >= minimum_count[nucleotide] for nucleotide in 'ACGT') else 0

for i in range(1, s - t + 1):
    substring_count[dna_string[i + t - 1]] += 1
    substring_count[dna_string[i - 1]] -= 1
    if all(substring_count[nucleotide] >= minimum_count[nucleotide] for nucleotide in 'ACGT'): cnt += 1

print(cnt)