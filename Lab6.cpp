#include <bits/stdc++.h>
using namespace std;
pair<int,int> ans(vector <int> & arr, int si, int size)
{
    if(si>size)
    {
        pair<int,int> base;
        base.first=INT_MIN;
        base.second= INT_MAX;
        return base;
    }
    int mid= (si+size)/2;
    pair<int,int> l=ans(arr,0,mid-1);
    pair<int,int> r = ans(arr, mid+1,size);
    int max;
    pair<int,int> sol;
    int rtemp=max(l.first,r.first);
    sol.first=max(arr[mid],rtemp);
    sol.second=min(arr[mid],min(l.second,r.second));
    return sol;

}

int main(){
    int n;
    cin>>n;
     vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    pair<int,int>output = ans(arr,0,n-1);
    cout<<output.first<<output.second<<endl;

    
   
    return 0;
}