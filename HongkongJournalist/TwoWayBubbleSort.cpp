#include <iostream>
#include <windows.h>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;
TimeData TwoWayBubbleSort(double number[], int n)
{
	double dqFreq; //��ʱ��Ƶ��
	double run_time;
	_LARGE_INTEGER time_start; //��ʼʱ��
	_LARGE_INTEGER time_over; //����ʱ��
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //��ʱ��ʼ
	int left = 0, right = SIZE_OF_ARRAY - 1, shift = 1;
	int i;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
					shift = i;
			}
		}
		right = shift;
		for (i = right - 1; i >= left; i--)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
					shift = i + 1;
			}
		}
		left = shift;
	}
	QueryPerformanceCounter(&time_over); //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// ����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000 / ��cpu��Ƶ��΢��
	TimeData aaa("˫��ð������", run_time, 2 * (n - 1)); //�������ƣ�����ʱ�䣬��������
	return aaa;
}