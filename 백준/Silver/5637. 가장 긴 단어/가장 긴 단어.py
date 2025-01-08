import sys
import re

text = sys.stdin.read()
pattern = re.compile('[a-zA-Z0-9-]+')
words = list(pattern.findall(text))
words.remove('E-N-D')
print(max(words, key=len).lower())