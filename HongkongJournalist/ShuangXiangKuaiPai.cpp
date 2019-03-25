#include<iostream>
#include<algorithm>
using namespace std;
#include"TimeData.h"
#include<Windows.h>
int sum=0;//������������
template <typename T>
//��arr[l...r]����partition���� 
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
//��arr[l...r]���ֽ������� 
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
	_LARGE_INTEGER time_start;	//��ʼʱ��
	_LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ
	__quicksort(arr,0,n-1);
	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("ShuangXiangKuaiPai",run_time,sum);
	return pp;
}
