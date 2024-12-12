#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    // Sample input string
    string input;cin>>input;
    
    // Vector to store the pairs of (a, b)
    vector<pair<int, int>> pairs;
    
    // Variables for extracting the numbers from the string
    size_t pos = 0;
    
    // Loop to find all "mul(a, b)" patterns
    while ((pos = input.find("mul(", pos)) != string::npos) {
        // Extract the substring starting from the found position
        size_t start = pos + 4;  // Skip "mul("
        size_t end = input.find(")", start);
        
        // Extract the part between the parentheses
        string sub_str = input.substr(start, end - start);
        
        // Now, extract the numbers from the substring
        size_t comma_pos = sub_str.find(",");
        int a = stoi(sub_str.substr(0, comma_pos)); // Extract first number
        int b = stoi(sub_str.substr(comma_pos + 1)); // Extract second number
        
        // Store the pair
        pairs.push_back({a, b});
        
        // Move the position forward to continue searching for the next "mul("
        pos = end + 1;
    }

    // Multiply the extracted pairs and display the result
    for (const auto& p : pairs) {
        int result = p.first * p.second;
        cout << "mul(" << p.first << ", " << p.second << ") = " << result << endl;
    }

    return 0;
}