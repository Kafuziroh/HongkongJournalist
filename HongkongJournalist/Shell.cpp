//Shell排序
#include <iostream>
#include <windows.h>
#include "TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData Shell(double str[], int len)
{
	int sum = 0;
	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始
	int i, j, gap;
	double temp;
	for (gap = len / 2; gap > 0; gap /= 2)//分组进行排序
	{
		for (i = gap; i < len; i++)
		{
			for (j = i - gap; j >= 0 && str[j] > str[j + gap]; j -= gap)
			{
				temp = str[j];
				str[j] = str[j + gap];//将相差gap位置的两个数进行调换
				str[j + gap] = temp;
				sum++;
			}
		}
	}
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("Shell", run_time, sum);
	return pp;
}