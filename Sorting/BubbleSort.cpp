// Bubble Sort ->  Traverse full array and swap until biggest element come to last
//                 Again Traverse full-1 array and swap until biggest element come to last
//                 Apply these unlil last element of traversal become 0

// Optimizations ->    Take a flag to check if array is already sorted, if it is, stop algorithm

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    // Size of array
    int n;
    cin >> n;
    // Array of size n
    int arr2[n];
    // Inserting element of array
    for(int i=0;i<n;i++)
        cin >> arr2[i];
    // Applying Bubble Sort Algorithm
    // Provide maximum position of traversal for each round
    for(int i=n-1;i>0;i--)
    {
        // Check if loop is sorted
        int swapped = 0;
        // Traverse till maximum traversal position - 1 (-1 b/c we compere element at j and j+1)
        for(int j=0;j<i;j++)
        {
            // Swap if element at lower index is greater than at higher
            if(arr2[j]>arr2[j+1])
            {
                swap(arr2[j],arr2[j+1]);
                swapped++;
            }
        }
        // Shows that all elements in this traversal is sorted an the rest are sorted prevously(if not sorted)
        if(swapped == 0)
            break;
    }
    // Showing the sorted array
    for(int i=0;i<n;i++)
        cout << arr2[i] << " ";
    return 0;
}