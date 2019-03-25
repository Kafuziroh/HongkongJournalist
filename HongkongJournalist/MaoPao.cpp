//冒泡排序
#include <iostream>
#include <Windows.h>
#include "TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData MaoPao(double str[], int len)
{
	int sum = 0;
	double run_time;
	_LARGE_INTEGER time_start; //开始时间
	_LARGE_INTEGER time_over; //结束时间
	double dqFreq; //计时器频率
	LARGE_INTEGER f; //计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //计时开始
	for (int i = len; i > 0; i--) //总共需要排序
		for (int j = 1; j < i; j++)
		{
			if (str[j - 1] < str[j])
			{
				double temp = str[j]; //数组前后替换
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			sum++;
		}
	QueryPerformanceCounter(&time_over); //计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("MaoPao", run_time, sum);
	return pp;
}






