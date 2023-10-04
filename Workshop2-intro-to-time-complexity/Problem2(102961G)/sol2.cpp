//Optimised version using two pointers (O(nlogn))
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //getting the input
    int n,x; cin >> n >> x;
    vector <int> v(n);
    for(int i = 0 ;i<n;i++) cin >> v[i];
    //sorting the array int vs
    vector<int> vs(v);
    sort(vs.begin(),vs.end());
    //looking for the combination in the sorted array (in O(n) time)
    int left=0 , right = n-1;
    int val1=-1,val2=-1;
    while(left < right)
    {
        if(vs[left] + vs[right] > x) right--;
        else if(vs[left] + vs[right] < x) left++;
        else {
            val1 = vs[left]; val2=vs[right];
            break;
        }
    }
    // the sum was not found
    if(left>=right) {cout << -1 << endl; return 0;}


    // finding the indices in the unsorted array (in O(n) time)
    int leftPos=-1,rightPos=-1;
    int i=0;
    while(leftPos==-1 || rightPos == -1)
    {
        if(leftPos==-1 && val1 == v[i]) leftPos = i;
        else if(rightPos == -1 && val2 == v[i])  rightPos = i;
        i++;
    }
    cout << leftPos+1 << ' ' << rightPos+1 << endl;
    return 0;
}