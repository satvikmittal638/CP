import subprocess
import math
import sys
import os
import random

# --- Configuration ---
# 1. Exhaustive check for small numbers
SMALL_RANGE_END = 300

# 2. Random sampling for the middle range (301 to 199,949)
NUM_RANDOM_SAMPLES = 100 
MAX_CONSTRAINT = 200000

# 3. Exhaustive check for the very edge of the constraints
EDGE_RANGE_START = 199950

# --- Safe Import for Matplotlib ---
HAS_MATPLOTLIB = False
try:
    import matplotlib.pyplot as plt
    HAS_MATPLOTLIB = True
except ImportError as e:
    print(f"Warning: Could not import matplotlib ({e}).")
    print("Switching to TEXT-ONLY mode.")

# --- Helper: GCD ---
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# --- Helper: Count Bad Indices ---
def count_bad_indices(perm):
    n = len(perm)
    if n < 3: return 0
    bad_count = 0
    for i in range(n - 2):
        x, y, z = perm[i], perm[i+1], perm[i+2]
        if gcd(x, y) == 1 and gcd(x, z) == 1 and gcd(y, z) == 1:
            bad_count += 1
    return bad_count

# --- Helper: Run C++ Binary ---
def run_solver(binary_name, n):
    try:
        input_str = f"1\n{n}\n"
        result = subprocess.run(
            [f"./{binary_name}"],
            input=input_str,
            text=True,
            capture_output=True,
            check=True
        )
        raw_output = result.stdout.strip().split()
        # Parse output (filtering out non-digits if any noise exists)
        return [int(x) for x in raw_output if x.lstrip('-').isdigit()]
    except Exception as e:
        print(f"Error running {binary_name} for N={n}: {e}")
        return []

# --- Main Execution ---
def main():
    print("Compiling solutions...")
    try:
        subprocess.run(["g++", "-O2", "main.cpp", "-o", "my_solution"], check=True)
        subprocess.run(["g++", "-O2", "original.cpp", "-o", "orig_solution"], check=True)
    except subprocess.CalledProcessError:
        print("Compilation failed.")
        return

    # Generate Test Set
    print("Generating test cases...")
    test_n_values = list(range(3, SMALL_RANGE_END + 1))
    
    # Random samples
    random_pool = range(SMALL_RANGE_END + 1, EDGE_RANGE_START)
    if len(random_pool) > 0:
        test_n_values.extend(sorted(random.sample(random_pool, min(NUM_RANDOM_SAMPLES, len(random_pool)))))
    
    # Edge cases
    test_n_values.extend(range(EDGE_RANGE_START, MAX_CONSTRAINT + 1))
    
    # Remove duplicates and sort
    test_n_values = sorted(list(set(test_n_values)))
    
    print(f"Total Tests Planned: {len(test_n_values)}")
    print(f"  - Small Range (3-{SMALL_RANGE_END})")
    print(f"  - Random Samples ({NUM_RANDOM_SAMPLES} tests)")
    print(f"  - Edge Range ({EDGE_RANGE_START}-{MAX_CONSTRAINT})")
    print("-" * 30)

    n_values = []
    my_bad_counts = []
    orig_bad_counts = []
    
    limit_violations = 0

    for idx, n in enumerate(test_n_values):
        # Progress Bar
        if idx % 10 == 0 or idx == len(test_n_values) - 1:
            sys.stdout.write(f"\rRunning Test {idx+1}/{len(test_n_values)} [N={n}]")
            sys.stdout.flush()

        # Run Solvers
        my_perm = run_solver("my_solution", n)
        my_bad = count_bad_indices(my_perm)
        
        orig_perm = run_solver("orig_solution", n)
        orig_bad = count_bad_indices(orig_perm)
        
        n_values.append(n)
        my_bad_counts.append(my_bad)
        orig_bad_counts.append(orig_bad)
        
        if my_bad > 6:
            limit_violations += 1
            print(f"\n[FAIL] N={n} | My Bad: {my_bad} (Limit: 6)")

    print("\n" + "="*30)
    print("Testing Complete.")

    # Output Phase
    print("Generating intensive plot...")
    try:
        plt.figure(figsize=(14, 7))
        
        # Use scatter for better visibility of discrete points over large ranges
        plt.scatter(n_values, orig_bad_counts, label='Original Solution', 
                    color='red', alpha=0.5, s=15, marker='x')
        
        plt.scatter(n_values, my_bad_counts, label='My Solution', 
                    color='blue', alpha=0.5, s=15, marker='o')

        plt.axhline(y=6, color='black', linestyle=':', label='Limit (6)')
        
        plt.title(f'Stress Test: Bad Indices vs N (Up to {MAX_CONSTRAINT})')
        plt.xlabel('N (Permutation Length)')
        plt.ylabel('Number of Bad Indices')
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        # Use log scale for X axis if the range is huge, to see small N better
        plt.xscale('log') 
        
        output_file = 'intensive_comparison_plot.png'
        plt.savefig(output_file)
        print(f"Done! Plot saved to {output_file} (Note: X-axis is Log Scale)")
    except Exception as e:
            print(f"Plotting failed ({e}). Fallback to text.")
            HAS_MATPLOTLIB = False

   

if __name__ == "__main__":
    main()