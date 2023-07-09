#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the data"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int s;
    cout<<"Enter the size of the subarray"<<endl;
    cin>>s;
    int MaxAve= INT_MIN;
    for (int i = 0; i < n-s+1; i++)
    {
        int sum=0;
        for(int j=i; j<i+s; j++)
        {
            sum =sum + arr[j];
        }
        if(sum>MaxAve)
        {
            MaxAve=sum;
        }

    }
    cout<<"The Maximum Average is "<< MaxAve<<endl;
    
   
    return 0;
}