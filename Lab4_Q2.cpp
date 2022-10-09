#include <bits/stdc++.h>
using namespace std;
void CountSort(int arr[], int n)
{
    int max=arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int count[max+1];
    for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    
    for (int i = 1; i < max+1; i++)
    {
        count[i] +=count[i-1];
    }
    int output[n];
    for (int i = n-1; i >=0; i--)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
    }
    
}
int main()
{
    cout<<"Enter the number of students"<<endl;
    int x;
    cin>>x;
    cout<<"enter the size of the arr"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    CountSort(arr,n);
    cout<<"The sorted array is"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int current= arr[0];
int ans=-1;
for (int i = 1; i < n; i++)
{
    if(current==arr[i])
    {
        ans= arr[i];
        break;
    }
    else{
        current = arr[i];
    }
}
cout<<"student who have submitted the test twice is "<<ans;

}