//ѡ������
#include <iostream>
#include <windows.h>
#include "TimeData.h"
#include <algorithm>
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData ChooseSort(double a[], int n)                     //ѡ������
{
	int i, j, k;
	double tmp;
	double dqFreq;                                       //��ʱ��Ƶ��
	double run_time;
	_LARGE_INTEGER time_start;	                         //��ʼʱ��
	_LARGE_INTEGER time_over;	                         //����ʱ��
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	             //��ʱ��ʼ
	for (i = 0; i < n - 1; i++)                          //����ѭ��������һ��n������Ҫn-1��ѭ��
	{
		k = i;                                           //��k���ѭ������i 
		for (j = i + 1; j < n; j++)                      //���i������k˵��a[i]������С��
		{
			if (a[j] < a[k])
				k = j;
		}
		if (i != k)                                      //���i������k˵��a[i]������С��
		{                                                //��i��k��Ⱦ�˵��a[i]�Ǳ���ѭ����С��ֵ
			tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}                                                //�����滻
	}
	QueryPerformanceCounter(&time_over);	             //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// ����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000 / ��cpu��Ƶ��΢��
	TimeData aaa("ѡ������", run_time, n - 1); //�������ƣ�����ʱ�䣬��������
	return aaa;
}