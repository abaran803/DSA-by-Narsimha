// Insertion Sort ->	Sort the element till index i
// 					If any element is greater than element at i it will be replaced with its previous element
// 					Repeat process until element is greater than element at i or index of element i is greater than 0
// 					Repeat the above process until traversal reach to the end

// Time Complexity(Average,Worst) ->	O(n^2)
// Time Complexity(Best) -> O(n)

#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp = arr[i];
		j = i;
		while(arr[j-1]>temp && j>0)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
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
	InsertionSort(arr,n);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	return 0;
}