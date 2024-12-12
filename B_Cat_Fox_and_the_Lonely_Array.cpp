#include <iostream>
#include <vector>
using namespace std;
/*
Checks if the array can be k-lonely
*/
bool iskLonely(long long k, vector<long long> v)
{
    vector<long long> countBit(20, 0);
    int i = 0, j = 0;
    // first window
    while (j < k)
    {
        for (int pos = 0; pos < 20; pos++)
        {
            countBit[pos] += v[j] & (1 << pos);
        }
        j++;
    }
    long long firstAns = 0;
    for (int pos = 0; pos < 20; pos++)
    {
        firstAns += (1 << pos)*(countBit[pos]>0);
    }
    // process the subsequent windows
    // we start at j=k
    while (j < v.size())
    {
        for (int pos = 0; pos < 20; pos++)
        {
            // add the jth element to the window
            countBit[pos] += v[j] & (1 << pos);
            // remove the ith element from the window
            countBit[pos] -= v[i] & (1 << pos);
        }
        // find the ans for this window
        long long ans = 0;
        for (int pos = 0; pos < 20; pos++)
        {
            ans += (1 << pos)*(countBit[pos]>0);
        }
        if (firstAns != ans)
        {
            return 0;
        }
        // update variables
        i++;
        j++;
    }
    return 1;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long &i : v)
        {
            cin >> i;
        }
        // binary search the minimum k
        long long low = 1, high = n;
        // searches until it is down to the last 2 elements
        while (low+1< high)
        {
            long long mid = low + (high - low + 1) / 2;
            if (iskLonely(mid, v))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        if(iskLonely(low,v)){
            cout<<low;
        }else{
            cout<<high;
        }
        cout<<endl;
    }
    return 0;
}