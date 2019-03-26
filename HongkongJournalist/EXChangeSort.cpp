#include<iostream>
#include<windows.h>
#include"TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;
TimeData ChangeSort(double a[], int n)                   //交换法排序 
{
	int i = 0, j;
	double tmp;
	double dqFreq;                                       //计时器频率
	double run_time;
	_LARGE_INTEGER time_start;	                         //开始时间
	_LARGE_INTEGER time_over;	                         //结束时间
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //计时开始
	for (i = 0; i < n - 1; i++)                          //将每一个循环的第一个数与后面的数逐一比较
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp; 
			}                                            //每一个循环第一个数字与数组中找到的更小数字交换
		}
	}
	QueryPerformanceCounter(&time_over);	             //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// 乘以1000000把单位由秒化为微秒，精度为1000 000 / （cpu主频）微秒
	TimeData aaa("交换排序", run_time, n - 1);          //方法名称，所用时间，排序趟数
	return aaa;
}