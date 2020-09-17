#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int query)
{
	int low = 0,high = n-1,mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(arr[mid]>query)
			high = mid-1;
		else if(arr[mid]<query)
			low = mid+1;
		else
			return mid;
	}
	return -1;
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
	int query;
	cin >> query;
	int res = BinarySearch(arr,n,query);
	cout << res;
	return 0;
}