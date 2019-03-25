//Shell����
#include <iostream>
#include <windows.h>
#include "TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData Shell(double str[], int len)
{
	int sum = 0;
	double run_time;
	_LARGE_INTEGER time_start;	//��ʼʱ��
	_LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ
	int i, j, gap;
	double temp;
	for (gap = len / 2; gap > 0; gap /= 2)//�����������
	{
		for (i = gap; i < len; i++)
		{
			for (j = i - gap; j >= 0 && str[j] > str[j + gap]; j -= gap)
			{
				temp = str[j];
				str[j] = str[j + gap];//�����gapλ�õ����������е���
				str[j + gap] = temp;
				sum++;
			}
		}
	}
	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("Shell", run_time, sum);
	return pp;
}