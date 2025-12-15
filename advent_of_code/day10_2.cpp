#include<bits/stdc++.h>
#include <z3++.h> // SMT solver

using namespace std;
using namespace z3;

#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// Helper to parse integers from a string
vector<int> toInts(const string &s) {
    vector<int> v;
    string cur;
    for (char ch : s) {
        if (isdigit(ch) || ch == '-') cur += ch;
        else if (!cur.empty()) {
            v.push_back(stoi(cur));
            cur.clear();
        }
    }
    if (!cur.empty()) v.push_back(stoi(cur));
    return v;
}

int main()
{
    fastio;
    vector<string> lights;
    vector<vector<int>> jolts;
    vector<vector<vector<int>>> buttons;
    string line;

    // --- INPUT PARSING ---
    while (getline(cin, line)) {
        if(line.empty()) continue;
        string insideSquare;
        vector<string> insideParen;
        vector<string> insideBrace;

        for (int i = 0; i < (int)line.size(); i++) {
            if (line[i] == '[') {
                int j = line.find(']', i);
                insideSquare = line.substr(i + 1, j - i - 1);
                i = j;
            }
            else if (line[i] == '(') {
                int j = line.find(')', i);
                insideParen.push_back(line.substr(i + 1, j - i - 1));
                i = j;
            }
            else if (line[i] == '{') {
                int j = line.find('}', i);
                insideBrace.push_back(line.substr(i + 1, j - i - 1));
                i = j;
            }
        }
        lights.push_back(insideSquare);

        vector<vector<int>> machineButtons;
        for (auto &s : insideParen) {
            machineButtons.push_back(toInts(s));
        }
        buttons.push_back(machineButtons);

        vector<int> machineJolts;
        for (auto &s : insideBrace) {
            for (int x : toInts(s)) machineJolts.push_back(x);
        }
        jolts.push_back(machineJolts);
    }
    
    // --- SOLVING ---
    ll ans = 0;
    
    for(int z = 0; z < jolts.size(); z++){
        context c;
        optimize opt(c);
        
        int num_lights = jolts[z].size();
        int num_buttons = buttons[z].size();

        // build Inverted Map: Light Index -> List of Button Indices that affect it
        // lt_btn[i] contains a list of buttons that toggle light i
        vector<vector<int>> lt_btn(num_lights);
        
        for(int btn_idx = 0; btn_idx < num_buttons; btn_idx++){
            for(int light_affected : buttons[z][btn_idx]){
                if(light_affected < num_lights) {
                    lt_btn[light_affected].push_back(btn_idx);
                }
            }
        }

        // Add Constraints: For each light, sum(presses) == target_jolt
        for(int i = 0; i < num_lights; i++){
            expr tot_sum = c.int_val(0);
            
            for(int btn_idx : lt_btn[i]){
                string name = "x_" + to_string(btn_idx);
                tot_sum = tot_sum + c.int_const(name.c_str());
            }
            
            // The sum of presses for this light must equal the required jolt value
            opt.add(tot_sum == c.int_val(jolts[z][i]));
        }

        // define Objective: Minimize total button presses
        expr obj = c.int_val(0);
        for(int i = 0; i < num_buttons; i++){
            string name = "x_" + to_string(i);
            expr x = c.int_const(name.c_str());
            
            // buttons cannot be pressed negative times
            opt.add(x >= 0); 
            
            obj = obj + x;
        }
        
        opt.minimize(obj);

        // solve and Retrieve
        if(opt.check() == sat){
            model m = opt.get_model();
            // get_numeral_int64() safely converts Z3 integer to C++ long long
            ans += m.eval(obj).get_numeral_int64();
        }
        else{
            cout << "Machine " << z << " is unsatisfiable (no solution found)\n";
        }
    }

    cout << ans << endl;
    return 0;
}