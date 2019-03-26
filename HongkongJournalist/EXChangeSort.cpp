#include<iostream>
#include<windows.h>
#include"TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;
TimeData ChangeSort(double a[], int n)                   //���������� 
{
	int i = 0, j;
	double tmp;
	double dqFreq;                                       //��ʱ��Ƶ��
	double run_time;
	_LARGE_INTEGER time_start;	                         //��ʼʱ��
	_LARGE_INTEGER time_over;	                         //����ʱ��
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //��ʱ��ʼ
	for (i = 0; i < n - 1; i++)                          //��ÿһ��ѭ���ĵ�һ��������������һ�Ƚ�
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp; 
			}                                            //ÿһ��ѭ����һ���������������ҵ��ĸ�С���ֽ���
		}
	}
	QueryPerformanceCounter(&time_over);	             //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// ����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000 / ��cpu��Ƶ��΢��
	TimeData aaa("��������", run_time, n - 1);          //�������ƣ�����ʱ�䣬��������
	return aaa;
}