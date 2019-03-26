//˫·����
#include <iostream>
#include <algorithm>
#include "TimeData.h"
#include <Windows.h>
using namespace std;

int sumAAA = 0;//������������
//��arr[l...r]����partition���� 
int  partitionT(double arr[], int l, int r)
{
	double v = arr[l];
	int j;
	j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;

}
//��arr[l...r]���ֽ������� 
void __quicksortT(double arr[], int l, int r)
{
	sumAAA++;
	if (l >= r)
		return;

	int p = partitionT(arr, l, r);
	__quicksortT(arr, l, p - 1);
	__quicksortT(arr, p + 1, r);
}

TimeData quicksortT(double arr[], int n)
{
	double run_time;
	_LARGE_INTEGER time_start;	//��ʼʱ��
	_LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ
	__quicksortT(arr, 0, n - 1);
	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("˫·��������", run_time, sumAAA);
	return pp;
}
