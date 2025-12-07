import subprocess
import time
import random
import numpy as np
import matplotlib.pyplot as plt
import sys
import os
from scipy.optimize import curve_fit

# ================= CONFIGURATION =================
CPP_FILE = "sol.cpp"
EXECUTABLE = "sol"

# CRITICAL: Ensure your C++ code uses 'string' or 'vector' to handle large N.
# If you used 'char s[100]', you MUST change it to 'string s' first!
MAX_N = 3000          # We need N=3000 to see the difference between O(N) and O(N^2)
START_N = 100         # Skip the tiny Ns where system noise dominates
STEP_N = 100          # Larger steps to save time
TRIALS_PER_BATCH = 20 # Keep this moderate since N is large now
# =================================================

def compile_cpp():
    print(f"🔨 Compiling {CPP_FILE}...")
    cmd = ["g++", "-O2", CPP_FILE, "-o", EXECUTABLE]
    if os.name == 'nt': cmd[-1] += ".exe"
    
    res = subprocess.run(cmd, capture_output=True, text=True)
    if res.returncode != 0:
        print("❌ Compilation Failed:\n", res.stderr)
        sys.exit(1)
    print("✅ Compilation Success.")

def generate_valid_walk(n):
    """Generates a solvable S and T pair using random valid moves."""
    # Start with random T
    t = [random.choice('01') for _ in range(n)]
    s = list(t) # Copy T to S
    
    # Apply valid scrambles
    scrambles = n * 2
    for _ in range(scrambles):
        l = random.randint(0, n-1)
        r = random.randint(l, n-1)
        # Check palindrome
        sub = s[l:r+1]
        if sub == sub[::-1]:
            # Flip
            for k in range(l, r+1):
                s[k] = '1' if s[k] == '0' else '0'
                
    return "".join(s), "".join(t)

def generate_batch_input(n, count):
    """Creates a string content for input file with 'count' test cases."""
    lines = [f"{count}"]
    for _ in range(count):
        s, t = generate_valid_walk(n)
        lines.append(f"{n}")
        lines.append(s)
        lines.append(t)
    return "\n".join(lines)

def measure_batch_time(n, count):
    """Runs the batch and returns AVERAGE time per test case."""
    input_str = generate_batch_input(n, count)
    
    exe = f"./{EXECUTABLE}"
    if os.name == 'nt': exe = f".\\{EXECUTABLE}.exe"

    try:
        start = time.perf_counter()
        # We assume the solution reads T, then T test cases
        run = subprocess.run(
            [exe], 
            input=input_str, 
            capture_output=True, 
            text=True, 
            timeout=10 # Timeout for the whole batch
        )
        end = time.perf_counter()
        
        if run.returncode != 0:
            print(f"⚠️ Runtime Error at N={n}")
            return None
            
        total_time = end - start
        return total_time / count # Return average time per case

    except subprocess.TimeoutExpired:
        print(f"⚠️ Timeout at N={n}")
        return None

def model_linear(x, a): return a * x
def model_nlogn(x, a): return a * x * np.log2(x)
def model_quad(x, a): return a * x**2
def model_cubic(x, a): return a * x**3

def analyze():
    compile_cpp()
    
    x_data = []
    y_data = []
    
    print(f"\n🚀 Starting Analysis (N={START_N} to {MAX_N})...")
    print(f"{'N':<10} | {'Avg Time (s)':<15}")
    print("-" * 30)

    for n in range(START_N, MAX_N + 1, STEP_N):
        avg_t = measure_batch_time(n, TRIALS_PER_BATCH)
        if avg_t is None: break
        
        # Filter out tiny timings (system noise) for cleaner graphs
        # or just keep them.
        x_data.append(n)
        y_data.append(avg_t)
        
        print(f"{n:<10} | {avg_t:.6f}")

    x_np = np.array(x_data)
    y_np = np.array(y_data)

    # --- Curve Fitting ---
    # We fit 'a' for each model to minimize error
    popt_lin, _ = curve_fit(model_linear, x_np, y_np)
    popt_nlogn, _ = curve_fit(model_nlogn, x_np, y_np)
    popt_quad, _ = curve_fit(model_quad, x_np, y_np)
    popt_cubic, _ = curve_fit(model_cubic, x_np, y_np)

    # Calculate residuals (How bad is the fit?)
    def get_mse(func, param):
        residuals = y_np - func(x_np, param)
        return np.sum(residuals**2)

    mse = {
        "O(N)": get_mse(model_linear, popt_lin[0]),
        "O(N log N)": get_mse(model_nlogn, popt_nlogn[0]),
        "O(N^2)": get_mse(model_quad, popt_quad[0]),
        "O(N^3)": get_mse(model_cubic, popt_cubic[0])
    }
    
    best_fit = min(mse, key=mse.get)
    print(f"\n🏆 Best Fit Algorithm: {best_fit}")

    # --- Plotting ---
    plt.figure(figsize=(12, 7))
    
    # Plot Actual Data
    plt.scatter(x_np, y_np, color='black', label='Your Code (Actual)', zorder=5)
    plt.plot(x_np, y_np, color='black', alpha=0.3)

    # Generate smooth lines for theoretical models
    x_smooth = np.linspace(START_N, MAX_N, 500)
    
    plt.plot(x_smooth, model_linear(x_smooth, *popt_lin), '--', label=f'O(N) Fit', alpha=0.5)
    plt.plot(x_smooth, model_nlogn(x_smooth, *popt_nlogn), '--', label=f'O(N log N) Fit', alpha=0.5)
    plt.plot(x_smooth, model_quad(x_smooth, *popt_quad), '--', label=f'O(N^2) Fit', linewidth=2)
    plt.plot(x_smooth, model_cubic(x_smooth, *popt_cubic), '--', label=f'O(N^3) Fit', alpha=0.5)

    plt.title(f"Empirical Time Complexity Analysis\nLikely Complexity: {best_fit}")
    plt.xlabel("Input Size (N)")
    plt.ylabel("Execution Time (seconds)")
    plt.legend()
    plt.grid(True, which="both", ls="-", alpha=0.2)
    
    print("📊 Graph generated. Check the popup window!")
    plt.show()

if __name__ == "__main__":
    analyze()