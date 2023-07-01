#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans(vector<int>&arr,int s,int endi){
    int n=arr.size();
    if(s>endi){
        pair<int,int>p{INT_MIN,INT_MAX};
        return p;
    }
    int mid=(endi+s)/2;
    pair<int,int>left=ans(arr,0,mid-1);
    pair<int,int>right=ans(arr,mid+1,endi);
    int a=max(left.first,right.first);
    int b=min(left.second,right.second);
    a=max(arr[mid],a);
    b=min(arr[mid],b);
    pair<int,int>output{a,b};
    return output;
}

    int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    pair<int,int>output=ans(arr,0,n-1);
    cout<<"The largest element is "<<output.first<<endl;
    cout<<"The smallest element is "<<output.second<<endl;

    
   
    return 0;
    }