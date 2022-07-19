#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int start,int end)
{
  // pivot is always be my first element
  int pivot=arr[start];
  int i=start;
  int j=end;

  while( i<j )
    {
      // move i until a greater element is fond then pivot
      while(arr[i] <= pivot)
        {
          i++;
        }

      // move j until a samller or equal element is found then           pivot
      while( arr[j] > pivot )
        {
          j--;
        }

      // swap them if i<j
      if(i<j)
      {
        swap(arr[i],arr[j]);
      }
      
    }

  // swap pivot with j-index
  swap( arr[j],arr[start] );

    return j;
  
}

void quick_sort(int *arr, int start, int end)
{
  // base case
  // we need mimimum 2 elements
  if( start < end )
  {
    // find the pivot element correct place
    // i.e find the correct postion of start/pivot in the array such that all elements before this is less then pivot element ans right to it is greater
    int pivot= partition(arr, start, end);

    // recursive call to left part of pivot
    quick_sort(arr, start, pivot-1);

    // recursive call to right part of pivot
    quick_sort(arr, pivot+1,end);
    
  }
  
}

int main() {

  int arr[100];
  int n;
  cout<<" enter the size of array  : ";
  cin>>n;

  cout<<endl<<" enter the elements : "<<endl;

  for(int i=0;i<n;i++)
    {
      cout<<" "<<i+1<<" :  ";
      cin>>arr[i];
    }

  cout<<endl;

  cout<<" elements before sorting : "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<" "<<arr[i]<<" ";
    }cout<<endl;

  quick_sort(arr,0,n-1);
  cout<<endl;

  cout<<" elements after sorting : "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<" "<<arr[i]<<" ";
    }cout<<endl;
  
  return 0;
}