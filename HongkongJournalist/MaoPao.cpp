//ð������
#include <iostream>
#include <Windows.h>
#include "TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;

TimeData MaoPao(double str[], int len)
{
	int sum = 0;
	double run_time;
	_LARGE_INTEGER time_start; //��ʼʱ��
	_LARGE_INTEGER time_over; //����ʱ��
	double dqFreq; //��ʱ��Ƶ��
	LARGE_INTEGER f; //��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //��ʱ��ʼ
	for (int i = len; i > 0; i--) //�ܹ���Ҫ����
		for (int j = 1; j < i; j++)
		{
			if (str[j - 1] < str[j])
			{
				double temp = str[j]; //����ǰ���滻
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			sum++;
		}
	QueryPerformanceCounter(&time_over); //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("MaoPao", run_time, sum);
	return pp;
}






