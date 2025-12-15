#include <z3++.h>
#include <iostream>

using namespace z3;
using namespace std; // FIXED: Added this to find cout/endl

int main() {
    context c;
    optimize opt(c);
    
    expr x = c.int_const("x");
    expr y = c.int_const("y");

    opt.add(x >= 0);
    opt.add(y >= 0);
    opt.add(x + y <= 5);
    opt.add(2 * x + y <= 8);

    // FIXED: Define objective as a variable first so we can evaluate it later
    expr objective = 3 * x + y;
    opt.maximize(objective); 

    if (opt.check() == sat) {
        cout << "Status: Optimal solution found" << endl;
        
        model m = opt.get_model();
        
        // FIXED: Use m.eval(objective) instead of h.value()
        cout << "Max Objective: " << m.eval(objective) << endl;
        cout << "x = " << m.eval(x) << endl;
        cout << "y = " << m.eval(y) << endl;
    } else {
        cout << "Status: Infeasible or Unbounded" << endl;
    }

    return 0;
}