//二分排序
#include <iostream>
#include <windows.h>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;
int sun = 0;

TimeData ErFeng(double str[], int len)
{
	double run_time;
	_LARGE_INTEGER time_start; //开始时间
	_LARGE_INTEGER time_over; //结束时间
	double dqFreq; //计时器频率
	LARGE_INTEGER f; //计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //计时开始
	double temp;
	int low, high, mid, i, j;
	for (i = 1; i < len; i++)
	{
		temp = str[i]; //保存当前元素 
		low = 0;
		high = i - 1;
		while (low <= high) //在a[low...high]中折半查找有序插入的位置
		{
			mid = (low + high) / 2; //找到中间元素
			if (str[mid] > temp) //如果当前元素比中间元素小，当前元素要插入到中间元素的左侧
			{
				high = mid - 1;
			}
			else //如果当前元素比中间元素大，当前元素要插入到中间元素的右侧
			{
				low = mid + 1;
			}
		}

		for (j = i - 1; j > high; --j) //元素后移 
		{
			str[j + 1] = str[j];
		}
		str[high + 1] = temp; //插入
		sun++;
	}
	QueryPerformanceCounter(&time_over); //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("二分排序", run_time, sun);
	return pp;
}