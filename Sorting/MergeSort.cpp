#include<iostream>
using namespace std;
#define MAX_SIZE 100

int arr1[MAX_SIZE];

void Merge(int arr[],int low,int mid,int high)
{
	int i=low,j=mid+1;
	int k=low;
	for(;i<=mid && j<=high;)
	{
		if(arr[i]<arr[j])
			arr1[k++] = arr[i++];
		else
			arr1[k++] = arr[j++];
	}
	while(i<=mid)
		arr1[k++] = arr[i++];
	while(j<=high)
		arr1[k++] = arr[j++];
	for(int i=low;i<=high;i++,low++)
		arr[low] = arr1[low];
}

void MergeSort(int arr[],int low,int high)
{
	if(low>=high)
		return;
	int mid = (low+high)/2;
	MergeSort(arr,low,mid);
	MergeSort(arr,mid+1,high);
	Merge(arr,low,mid,high);
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	MergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout << arr1[i] << " ";
}