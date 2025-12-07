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

# Adjust MAX_N based on your expected complexity
# If O(N) or O(N log N) -> Try MAX_N = 10000
# If O(N^2)           -> Keep MAX_N = 2000
MAX_N = 5000          
START_N = 100
STEP_N = 100
TRIALS_PER_BATCH = 20 # Number of test cases per input file
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

def generate_increasing_array(n, all_odd=False):
    """
    Generates a strictly increasing sequence.
    mode 'all_odd': Forces all numbers to be odd (Stress Test)
    """
    arr = []
    # Start with a random base
    current = random.randint(1, 100)
    if all_odd and current % 2 == 0: current += 1

    for _ in range(n):
        arr.append(current)
        # Add random increment (must be > 0)
        increment = random.randint(1, 50)
        if all_odd:
            # If we need odd numbers, we must add an even increment
            if increment % 2 != 0: increment += 1
        current += increment
        
    return " ".join(map(str, arr))

def generate_batch_input(n, count):
    """
    Creates an input file content complying with the problem format:
    t
    n
    a1 a2 ... an
    """
    lines = [f"{count}"]
    for _ in range(count):
        lines.append(f"{n}")
        # Mix 50% random arrays and 50% 'all odd' arrays (Harder case)
        use_odd = random.choice([True, False])
        lines.append(generate_increasing_array(n, all_odd=use_odd))
    return "\n".join(lines)

def measure_batch_time(n, count):
    """Runs the batch and returns AVERAGE time per test case."""
    input_str = generate_batch_input(n, count)
    
    exe = f"./{EXECUTABLE}"
    if os.name == 'nt': exe = f".\\{EXECUTABLE}.exe"

    try:
        start = time.perf_counter()
        run = subprocess.run(
            [exe], 
            input=input_str, 
            capture_output=True, 
            text=True, 
            timeout=10 
        )
        end = time.perf_counter()
        
        if run.returncode != 0:
            print(f"⚠️ Runtime Error at N={n}")
            return None
            
        total_time = end - start
        return total_time / count 

    except subprocess.TimeoutExpired:
        print(f"⚠️ Timeout at N={n}")
        return None

# --- Models for Curve Fitting ---
def model_linear(x, a): return a * x
def model_nlogn(x, a): return a * x * np.log2(x)
def model_quad(x, a): return a * x**2

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
        
        x_data.append(n)
        y_data.append(avg_t)
        print(f"{n:<10} | {avg_t:.6f}")

    x_np = np.array(x_data)
    y_np = np.array(y_data)

    # --- Curve Fitting ---
    # We constrain 'a' to be positive for meaningful bounds
    popt_lin, _ = curve_fit(model_linear, x_np, y_np, bounds=(0, np.inf))
    popt_nlogn, _ = curve_fit(model_nlogn, x_np, y_np, bounds=(0, np.inf))
    popt_quad, _ = curve_fit(model_quad, x_np, y_np, bounds=(0, np.inf))

    # Calculate Error (MSE)
    def get_mse(func, param):
        residuals = y_np - func(x_np, param)
        return np.sum(residuals**2)

    mse = {
        "O(N)": get_mse(model_linear, popt_lin[0]),
        "O(N log N)": get_mse(model_nlogn, popt_nlogn[0]),
        "O(N^2)": get_mse(model_quad, popt_quad[0])
    }
    
    best_fit = min(mse, key=mse.get)
    print(f"\n🏆 Best Fit Algorithm: {best_fit}")

    # --- Plotting ---
    plt.figure(figsize=(10, 6))
    
    plt.scatter(x_np, y_np, color='black', label='Actual Runtime', zorder=5)
    
    x_smooth = np.linspace(START_N, MAX_N, 500)
    plt.plot(x_smooth, model_linear(x_smooth, *popt_lin), '--', label='O(N) Fit', alpha=0.5)
    plt.plot(x_smooth, model_nlogn(x_smooth, *popt_nlogn), '--', label='O(N log N) Fit', alpha=0.5)
    plt.plot(x_smooth, model_quad(x_smooth, *popt_quad), '--', label='O(N^2) Fit', linewidth=2)

    plt.title(f"Complexity Analysis: Even Modulo Pair\nLikely Complexity: {best_fit}")
    plt.xlabel("Input Size (N)")
    plt.ylabel("Time (seconds)")
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    plt.show()

if __name__ == "__main__":
    analyze()