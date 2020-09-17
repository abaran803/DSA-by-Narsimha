// Shell Sort ->	Similer to insertion sort but with some changes
// 					In insertion sort we compere adjacent element
// 					In shell sort we compere adjacent element with gap distance

#include<bits/stdc++.h>
using namespace std;

void ShellSort(int arr[],int n)
{
	// Initially gap = total_size/2
	int gap = n/2;
	// Here i is treated as current gap
	for(int i=gap;i>0;i/=2)
	{
		// Applying insertion sort with gap distance
		for(int j=i;j<n;j++)
		{
			int temp =  arr[j];
			int k;
			for(k=j;k>=i && arr[k-i]>temp;k-=i)
				arr[k] = arr[k-i];
			arr[k] = temp;
		}
	}
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
	ShellSort(arr,n);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
}