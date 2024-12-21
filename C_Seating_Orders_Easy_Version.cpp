#include <bits/stdc++.h>
using namespace std;

bool canAchieveSeating(int n, vector<int>& queue, vector<int>& target) {
    vector<int> seat(n, -1);  // -1 means the seat is empty
    deque<int> q;
    
    // Initial queue setup, using the queue as is
    q.push_back(0); // seat 0
    q.push_back(n - 1); // seat n-1
    
    int i = 0;
    for (int person : queue) {
        int seatIndex = q.front(); // Get the seat from queue
        q.pop_back();
        
        // Put the person in the selected seat
        seat[seatIndex] = person;
        
        // Split the block into two parts
        int left = seatIndex + 1;
        int right = seatIndex - 1;
        if(left <= right) {
            if (left < right)
                q.push_back(left);
            else {
                q.push_back(right);
                }
        }
    }
    return seat == target;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> queue(n), target(n);
        for (int i = 0; i < n; i++) cin >> queue[i];
        for (int i = 0; i < n; i++) cin >> target[i];

        if (canAchieveSeating(n, queue, target)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
