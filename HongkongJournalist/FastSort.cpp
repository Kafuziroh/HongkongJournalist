//��������
//�ų���
#include <iostream>
#include <algorithm>
#include <windows.h>
#include "TimeData.h"
using namespace std;
int TS = 0; //��������ͳ����

int partition(double arr[], int l, int r)
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

void __quicksort(double arr[], int l, int r)
{
	TS++; //��������++
	if (l >= r)
		return;
	int p = partition(arr, l, r);
	__quicksort(arr, l, p - 1);
	__quicksort(arr, p + 1, r);
}

TimeData FastSort(double arr[], int n)
{
	double run_time;
	_LARGE_INTEGER time_start; //��ʼʱ��
	_LARGE_INTEGER time_over; //����ʱ��
	double dqFreq; //��ʱ��Ƶ��
	LARGE_INTEGER f; //��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //��ʱ��ʼ

	__quicksort(arr, 0, n - 1);

	QueryPerformanceCounter(&time_over); //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq; //����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000000/��CPU��Ƶ��΢��
	
	TimeData a("��������", run_time, TS); //�������ƣ�����ʱ�䣬��������
	return a;
}