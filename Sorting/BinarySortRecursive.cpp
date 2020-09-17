#include<iostream>
using namespace std;

int BinarySearch(int arr[],int low,int high,int query)
{
	if(low>high)
		return -1;
	int mid = (high+low)/2;
	if(arr[mid]>query)
		return BinarySearch(arr,low,mid-1,query);
	else if(arr[mid]<query)
		return BinarySearch(arr,mid+1,high,query);
	if(arr[mid] == query)
		return mid;
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
	int res = BinarySearch(arr,0,n-1,query);
	cout << res;
	return 0;
}