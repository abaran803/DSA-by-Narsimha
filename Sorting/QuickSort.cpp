#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// From DSA Narsimha Karumanchi
// int pivot(int arr[],int low,int high)
// {
// 	int pivot = high;
// 	int left = low;
// 	int right = high-1;
// 	if(left == right)
// 		return pivot;
// 	while(left<right)
// 	{
// 		while(arr[left]<pivot)
// 			left++;
// 		while(arr[right]>pivot)
// 			right--;
// 		if(arr[left]>arr[right] && left<right)
// 			swap(arr[left],arr[right]);
// 	}
// 	swap(arr[left],arr[pivot]);
// 	return left;
// }

// From GFG
int pivot(int arr[],int low,int high)
{
	int pivot = high;
	int left = low-1;
	for(int i=low;i<=high-1;i++)
	{
		if(arr[i]<arr[pivot])
		{
			left++;
			swap(arr[i],arr[left]);
		}
	}
	swap(arr[left+1],arr[pivot]);
	return left+1;
}

void QuickSort(int arr[],int low,int high)
{
	if(low >= high)
		return;
	int Pivot = pivot(arr,low,high);
	QuickSort(arr,low,Pivot-1);
	QuickSort(arr,Pivot+1,high);
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
	QuickSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	return 0;
}