//��������
#include <iostream>
#include <windows.h>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;
int sun = 0;

TimeData ErFeng(double str[], int len)
{
	double run_time;
	_LARGE_INTEGER time_start; //��ʼʱ��
	_LARGE_INTEGER time_over; //����ʱ��
	double dqFreq; //��ʱ��Ƶ��
	LARGE_INTEGER f; //��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //��ʱ��ʼ
	double temp;
	int low, high, mid, i, j;
	for (i = 1; i < len; i++)
	{
		temp = str[i]; //���浱ǰԪ�� 
		low = 0;
		high = i - 1;
		while (low <= high) //��a[low...high]���۰������������λ��
		{
			mid = (low + high) / 2; //�ҵ��м�Ԫ��
			if (str[mid] > temp) //�����ǰԪ�ر��м�Ԫ��С����ǰԪ��Ҫ���뵽�м�Ԫ�ص����
			{
				high = mid - 1;
			}
			else //�����ǰԪ�ر��м�Ԫ�ش󣬵�ǰԪ��Ҫ���뵽�м�Ԫ�ص��Ҳ�
			{
				low = mid + 1;
			}
		}

		for (j = i - 1; j > high; --j) //Ԫ�غ��� 
		{
			str[j + 1] = str[j];
		}
		str[high + 1] = temp; //����
		sun++;
	}
	QueryPerformanceCounter(&time_over); //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("��������", run_time, sun);
	return pp;
}