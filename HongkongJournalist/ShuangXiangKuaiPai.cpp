#include<iostream>
#include<algorithm>
using namespace std;
#include"TimeData.h"
#include<Windows.h>
int sum=0;//计算趟数所用
template <typename T>
//对arr[l...r]进行partition操作 
int  partition(T arr[],int l,int r)
{
	T v=arr[l];
	int j;
	j=l;
	for(int i=l+1;i<=r;i++)
	{
		if(arr[i]<v)
		{
			swap(arr[j+1],arr[i]);
			j++;
		}
	}
	swap(arr[l],arr[j]);
	return j;
	
}
//对arr[l...r]部分进行排序 
template <typename T>
void __quicksort(T arr[],int l,int r)
{
	sum++;
	if(l>=r)
	return ;
	
	int p=partition(arr,l,r);
	__quicksort(arr,l,p-1);
	__quicksort(arr,p+1,r);
}
 
template <typename T>
TimeData quicksort(T arr[],int n)
{
	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始
	__quicksort(arr,0,n-1);
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	TimeData pp("ShuangXiangKuaiPai",run_time,sum);
	return pp;
}
