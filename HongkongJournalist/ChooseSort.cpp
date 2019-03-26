//选择排序
#include <iostream>
#include <windows.h>
#include "TimeData.h"
#include <algorithm>
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData ChooseSort(double a[], int n)                     //选择法排序
{
	int i, j, k;
	double tmp;
	double dqFreq;                                       //计时器频率
	double run_time;
	_LARGE_INTEGER time_start;	                         //开始时间
	_LARGE_INTEGER time_over;	                         //结束时间
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //计时开始
	for (i = 0; i < n - 1; i++)                          //控制循环次数，一共n个数需要n-1次循环
	{
		k = i;                                           //用k标记循环次数i 
		for (j = i + 1; j < n; j++)                      //如果i不等于k说明a[i]不是最小的
		{
			if (a[j] < a[k])
				k = j;
		}
		if (i != k)                                      //如果i不等于k说明a[i]不是最小的
		{                                                //若i和k相等就说明a[i]是本次循环最小的值
			tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}                                                //数组替换
	}
	QueryPerformanceCounter(&time_over);	             //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// 乘以1000000把单位由秒化为微秒，精度为1000 000 / （cpu主频）微秒
	TimeData aaa("选择排序", run_time, n - 1); //方法名称，所用时间，排序趟数
	return aaa;
}