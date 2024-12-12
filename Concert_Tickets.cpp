#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// TODO:Debug the issue
bool compDec(pair<long, long> p1, pair<long, long> p2) {
    // Sort customers by maximum price in descending order
    return p1.second > p2.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long> h(n); // h -> tickets
    vector<pair<long, long> > t(m); // t -> customers with index and max price

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        t[i] = make_pair(i, tmp); // Store index and max customer price
    }

    // Sort tickets in descending order
    sort(h.begin(), h.end(), greater<long>());

    // Sort customers by price in descending order
    sort(t.begin(), t.end(), compDec);

    vector<long> assignedTickets(m, -1); // Initialize ticket assignment (-1 means no ticket assigned)

    int i = 0, j = 0; // i -> index for tickets, j -> index for customers

    while (i < n && j < m) {
        if (t[j].second >= h[i]) {
            // If the customer can afford the ticket, assign it
            assignedTickets[t[j].first] = h[i];
            j++; // Move to the next customer
        }
        // Whether or not a ticket was assigned, move to the next ticket
        i++;
    }

    // Output the ticket assigned to each customer in their original order
    for (int i = 0; i < m; i++) {
        cout << assignedTickets[i] << endl; // Print the ticket assigned or -1 if no ticket
    }

    return 0;
}