#include <iostream>
using namespace std;
int  max(long long arr[],int n)
{
    int large=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)large=arr[i];
    }
    return large;
}
void swap(long long* a, long long* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (long long  arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(long long arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int skew(long long arr1[],long long arr2[],int ki,int n)
{
    int mini,temp,a;
    mini=max(arr2,n);
    for(int i=1;i<=ki;i++)
    {
       temp=arr2[n-i];
       arr2[n-i]=arr1[i-1];
       arr1[i-1]=temp;
       a=max(arr2,n);
       if(a<mini)mini=a;
    }
    return mini;
}

int main()
{
    int n,k,ans;
    long long  A[100000],B[100000],C[100000],D[100000];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        C[i]=A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
        D[i]=B[i];
    }
    quickSort(A,0,n-1);
    quickSort(B,0,n-1);
    quickSort(C,0,n-1);
    quickSort(D,0,n-1);

     if(A[n-1]>B[n-1])
     {
         ans=A[n-1]+min(skew(A,B,k,n),skew(D,C,k,n));
     }
     else
     {
         ans=B[n-1]+min(skew(A,B,k,n),skew(D,C,k,n));
     }
     cout<<ans;


    return 0;
}
