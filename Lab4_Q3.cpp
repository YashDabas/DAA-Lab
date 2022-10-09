#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(string arr[], int n, int i)
{
    int largest=i;
    int l= 2*i+1;
    int r= 2*i+2;
    if(l<n&& (arr[largest]<arr[l]))
    {
        swap(arr[largest],arr[l]);
        largest=l;

    }
    if(r<n && (arr[largest]<arr[r]))
    {
        swap(arr[largest],arr[r]);
        largest=r;
    }
    if(largest !=i)
    {
        heapify(arr,n,largest);
    }
}
void buildheap(string arr[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void heapSort(string arr[], int n)
{
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    cout<<"Enter the number of names"<<endl;
    int n;
    cin>>n;
    string names[n];
    cout<<"Enter the names of students"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>names[i];
    }
    buildheap(names,n);
    heapSort(names,n);
    cout<<"The sorted names are "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<names[i]<<" ";
    }
   
    return 0;
}