//unoptimised brute force version (checking every combination) O(n²)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x; cin >> n >> x;
    vector <int> v(n);
    for(int i = 0 ;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && v[i] + v[j] == x) {
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            } 
        }
    }
    cout << -1 << endl;
}