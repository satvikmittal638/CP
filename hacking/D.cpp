#include <bits/stdc++.h>
using namespace std;


int main() {
    

    int t;
    cin >> t;
    while (t--) {
        int n ; 
        cin >> n ;
        
        vector<int> arr(n) ;
        for (int i = 0 ; i < n ; i++) cin >> arr[i] ;
        int i = 1 ;
        
        while ( i <= n/2) {
            if (arr[i-1] > arr[2*i - 1]) {
                swap(arr[i-1] ,arr[2*i - 1] ) ;
                if (i % 2 == 0) {
                    i = (i/2) -1 ;
                } else i++ ;
            } else i++ ;
        }
        
        if (is_sorted(arr.begin() , arr.end())) cout << "YES" << endl ;
        else cout << "NO" << endl ;
        
    }

    return 0;
}
