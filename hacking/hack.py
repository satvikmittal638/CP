# Save as gen.py and run: python gen.py > test.txt
print(1)            # T = 1
N = 200000          # Max N
print(N)
# Print permutation: 200000 199999 ... 2 1
print(*list(range(N, 0, -1)))