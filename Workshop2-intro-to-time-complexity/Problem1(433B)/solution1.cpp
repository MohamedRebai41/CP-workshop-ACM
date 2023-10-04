// This solution is not optimised. The submission will fail due to TLE
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //getting the input
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    //sorting the array
    vector<int> sortedV(v);
    sort(sortedV.begin(), sortedV.end());
    //treating the queries
    int m; cin >> m;
    while(m--)
    {
        int l,r,type; cin >> type >> l >> r;
        long long sum=0;
        if(type==1)
        {
            for(int i=l-1;i<r;i++)
            {
                sum+=v[i];
            }
        }
        else
        {
            for(int i=l-1;i<r;i++)
            {
                sum+=sortedV[i];
            }
        }
        cout << sum << endl;
    }
}