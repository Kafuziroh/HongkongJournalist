//��������
#include <iostream>
#include <windows.h>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;

TimeData ChaRu(double str[], int len)
{
	double run_time;
	_LARGE_INTEGER time_start; //��ʼʱ��
	_LARGE_INTEGER time_over; //����ʱ��
	double dqFreq; //��ʱ��Ƶ��
	LARGE_INTEGER f; //��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start); //��ʱ��ʼ
	for (int i = 1; i < len; i++)
	{
		int it = str[i];
		int iu = i - 1;
		while ((iu >= 0) && (it < str[iu])) //���²��������֮ǰ��һ������Ƚϣ���������������һλ����С����ڱ�����ͱ���С�����м�
		{
			str[iu + 1] = str[iu];
			iu--;
		}
		str[iu + 1] = it;
	}
	QueryPerformanceCounter(&time_over); //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	TimeData pp("��������", run_time, len - 1);
	return pp;
}