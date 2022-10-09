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
    cout<<"enter the size of the array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    CountSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Question 1
    int MostFrequent=0;
    int times=0;
    int count=1;
    int current=arr[0];
    for (int i = 1; i < n; i++)
    {
        if(current != arr[i])
        {
            if(times<count)
            {
                MostFrequent=arr[i-1];
                times= count;
            }
            count =1;
            current=arr[i];

        }
        else{
            count++;

        }
    }
    if(count>times)
    {
        MostFrequent=arr[n-1];
    }
    
    cout<<"The most frequent element is "<<MostFrequent<<endl;
    float median=4.5;
    if(n%2==0)
    {
        int a=arr[(n-1)/2]+arr[((n-1)/2)+1];
        median =a/2.0;
    }
    else{
        median = arr[(n/2)+1];
    }
    cout<<"Median is "<<median<<endl;
    float ans= MostFrequent- median;
    cout<<"The difference between the most frequent element and median is "<<ans<<endl;
    

}