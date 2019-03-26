#include<iostream>
#include<windows.h>
#include"TimeData.h"
TimeData TwoWayBubbleSort(double a[], int n)
{
	int i, k;
	int left = 1, right = n - 1;
	double tmp;
	double dqFreq;                                       //计时器频率
	double run_time;
	_LARGE_INTEGER time_start;	                         //开始时间
	_LARGE_INTEGER time_over;	                         //结束时间
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //计时开始
	do
	{
		for (i = right; i >= left; i--)                  //正向部分
		{
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				k = i;
			}
		}
		left = k + 1;
		for (i = left; i < right; i++)                   //反向部分
		{
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				k = i;
			}
		}
		right = k - 1;
	} while (left <= right);
	QueryPerformanceCounter(&time_over);	             //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// 乘以1000000把单位由秒化为微秒，精度为1000 000 / （cpu主频）微秒
	TimeData aaa("双向冒泡排序", run_time, 2 * (n - 1)); //方法名称，所用时间，排序趟数
	return aaa;
}