// Selection Sort ->	Traverse the array from initial+i position to end and select smallest element
// 					Swap the value of element at initial+i with smallest element
// 					Repeat the above process until initial+i become index of last element (n-1)
// 					It is an inplace sorting as it does not require any extra space
// Time Complexity(best, average, worst) -> O(n^2)

#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int arr[],int n)
{
	int mini,change;
	for(int i=0;i<n;i++)
	{
		mini = i;
		change = 0;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[i])
				mini = j;
		if(i != mini)
			swap(arr[i],arr[mini]);
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
	SelectionSort(arr,n);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	return 0;
}