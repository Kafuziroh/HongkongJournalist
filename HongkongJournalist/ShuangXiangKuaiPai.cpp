//双路快排
#include <iostream>
#include <algorithm>
#include "TimeData.h"
#include <Windows.h>
using namespace std;

int sumAAA = 0;//计算趟数所用
//对arr[l...r]进行partition操作 
int  partitionT(double arr[], int l, int r)
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
//对arr[l...r]部分进行排序 
void __quicksortT(double arr[], int l, int r)
{
	sumAAA++;
	if (l >= r)
		return;

	int p = partitionT(arr, l, r);
	__quicksortT(arr, l, p - 1);
	__quicksortT(arr, p + 1, r);
}

TimeData quicksortT(double arr[], int n)
{
	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始
	__quicksortT(arr, 0, n - 1);
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("双路快速排序", run_time, sumAAA);
	return pp;
}
