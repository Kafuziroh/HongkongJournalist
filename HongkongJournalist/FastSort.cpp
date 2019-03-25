//øÏ≈≈
#include<iostream>
#include<algorithm>
using namespace std;

int partition(double arr[], int l, int r)
{
	double v = arr[l];
	int j;
	j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

void __quicksort(double arr[], int l, int r)
{
	if (l >= r)
		return;
	int p = partition(arr, l, r);
	__quicksort(arr, l, p - 1);
	__quicksort(arr, p + 1, r);
}

void FastSort(double arr[], int n)
{
	__quicksort(arr, 0, n - 1);
}