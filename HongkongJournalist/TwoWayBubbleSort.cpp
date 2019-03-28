#include <iostream>
#include <windows.h>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;
TimeData TwoWayBubbleSort(double number[], int n)
{
	double dqFreq; //计时器频率
	double run_time;
	_LARGE_INTEGER time_start; //开始时间
	_LARGE_INTEGER time_over; //结束时间
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //计时开始
	int left = 0, right = SIZE_OF_ARRAY - 1, shift = 1;
	int i;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
					shift = i;
			}
		}
		right = shift;
		for (i = right - 1; i >= left; i--)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
					shift = i + 1;
			}
		}
		left = shift;
	}
	QueryPerformanceCounter(&time_over); //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// 乘以1000000把单位由秒化为微秒，精度为1000 000 / （cpu主频）微秒
	TimeData aaa("双向冒泡排序", run_time, 2 * (n - 1)); //方法名称，所用时间，排序趟数
	return aaa;
}