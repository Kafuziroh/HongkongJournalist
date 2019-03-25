//快速排序
//张承扬
#include <iostream>
#include <algorithm>
#include <windows.h>
#include "TimeData.h"
using namespace std;
int TS = 0; //排序趟数统计器

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
	TS++; //排序趟数++
	if (l >= r)
		return;
	int p = partition(arr, l, r);
	__quicksort(arr, l, p - 1);
	__quicksort(arr, p + 1, r);
}

TimeData FastSort(double arr[], int n)
{
	double run_time;
	_LARGE_INTEGER time_start; //开始时间
	_LARGE_INTEGER time_over; //结束时间
	double dqFreq; //计时器频率
	LARGE_INTEGER f; //计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //计时开始

	__quicksort(arr, 0, n - 1);

	QueryPerformanceCounter(&time_over); //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq; //乘以1000000把单位由秒化为微秒，精度为1000000/（CPU主频）微秒
	
	TimeData a("快速排序", run_time, TS); //方法名称，所用时间，排序趟数
	return a;
}