#include<bits/stdc++.h>
using namespace std;

pair<int,int> BP( vector <int> arr, int si, int ei)
{
    int n= arr.size();
    if(si>ei)
    {
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    int mid= (si+ei)/2;
    pair<int,int> left = BP(arr, 0, mid-1);
    pair<int,int> right = BP(arr,mid+1,ei);
    int Mi= min(left.first, right.first);
    int Ma = max(left.second, right.second);
    int MiBP= min(arr[mid],Mi);
    int MaBP = max(arr[mid], Ma);
    pair <int,int> ans= {MiBP, MaBP};
    return ans;


}

int main(){
    int n;
    cout<<"Enter the number of readings"<<endl;
    cin>>n;
    vector <int> arr(n);
    cout<<"Enter the readings"<<endl;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        arr[i]=t;
    }
    pair<int,int> answer= BP(arr,0,n-1);
    cout<<"The minimum Blood Pressure is "<< answer.first<<endl<<"The maximum Blood Pressure is "<< answer.second<<endl;
   
    return 0;
}