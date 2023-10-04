//This solution is optimised. It uses the concept of prefix sum.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //getting input
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    //building the prefix sum array for v
    vector<long long> pv(n+1);
    pv[0]=0;
    for (int i = 1 ; i < n+1 ; ++i) {pv[i]=v[i-1] + pv[i-1];}
    //sorting the array
    vector<int> sortedV(v);
    sort(sortedV.begin(), sortedV.end());
    //building the prefix sum array for the sorted array
    vector<long long> pSortedV(n+1);
    pSortedV[0] =  0;
    for (int i = 1 ; i < n+1 ; ++i) {pSortedV[i]=sortedV[i-1] + pSortedV[i-1];}
    //treating the queries
    int m; cin >> m;
    while(m--)
    {
        int l,r,type; cin >> type >> l >> r;
        if(type==1)
        {
            cout << pv[r] - pv[l-1] << endl;
        }
        else
        {
            cout << pSortedV[r] - pSortedV[l-1] << endl;
        }
    }
}