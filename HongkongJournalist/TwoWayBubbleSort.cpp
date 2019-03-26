#include<iostream>
#include<windows.h>
#include"TimeData.h"
TimeData TwoWayBubbleSort(double a[], int n)
{
	int i, k;
	int left = 1, right = n - 1;
	double tmp;
	double dqFreq;                                       //��ʱ��Ƶ��
	double run_time;
	_LARGE_INTEGER time_start;	                         //��ʼʱ��
	_LARGE_INTEGER time_over;	                         //����ʱ��
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //��ʱ��ʼ
	do
	{
		for (i = right; i >= left; i--)                  //���򲿷�
		{
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				k = i;
			}
		}
		left = k + 1;
		for (i = left; i < right; i++)                   //���򲿷�
		{
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				k = i;
			}
		}
		right = k - 1;
	} while (left <= right);
	QueryPerformanceCounter(&time_over);	             //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// ����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000 / ��cpu��Ƶ��΢��
	TimeData aaa("˫��ð������", run_time, 2 * (n - 1)); //�������ƣ�����ʱ�䣬��������
	return aaa;
}