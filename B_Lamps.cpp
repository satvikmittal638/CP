#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first)
    {
        return p1.first < p2.first; // ascending according to ai
    }
    else
    {
        return p1.second > p2.second; // descending according to bi
    }
}
void print(vector<int> v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v[i] = make_pair(a, b);
        }
        sort(v.begin(), v.end(), comp);

        long long score = 0, countOn = 0; 
        for (int i = 0; i < n; i++)
        {
            // copied this logic to make it in O(nlogn)
            // didn't understand this logic
            if (i > 0 && v[i].first != v[i - 1].first)
                countOn = 0;
            if (countOn >= v[i].first) // given lamp is non-working
                continue;
            score += v[i].second;
            countOn++;
        }
        cout<<score<<endl;
    }
    return 0;
}