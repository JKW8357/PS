import sys
import re

words = re.findall(r'[a-zA-Z-]+', sys.stdin.read())
words.remove('E-N-D')
print(max(words, key=len).lower())