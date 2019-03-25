//插入法排序
//杨楚瀛
#include<iostream>
using namespace std;
extern int SIZE_OF_ARRAY;
#include<windows.h>
#include"TimeData.h"
int sum=0;
TimeData ChaRu(double str[],int len)
{
	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始
	for(int i=1;i<len;i++)
	{
		int it=str[i];
		int iu=i-1;
		while((iu>=0)&&(it<str[iu]))//将新插入的数与之前的一个数相比较，若大则放置在最后一位，若小则放在比它大和比它小的数中间
		{
			str[iu+1]=str[iu];
			iu--;
			sum++;
		}
		str[iu+1]=it;
	}
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("ChaRu",run_time,sum);
	return pp;
}