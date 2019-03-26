#include<iostream>
#include<Windows.h>
#include<algorithm>
#include"TimeData.h"
using namespace std;
extern int SIZE_OF_ARRAY;
int sumbbb = 0;                                      //������������
template <typename T>
void __quicksort3(T arr[], int l, int r)               //��·����
{
	sumbbb++;
	if (l >= r)
		return;

	T v = arr[l];
	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	while (i < gt)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}

		else if (arr[i] > v)
		{
			swap(arr[i], arr[gt - 1]);
			gt--;
		}

		else
		{
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quicksort3(arr, l, lt - 1);
	__quicksort3(arr, gt, r);
}

TimeData ThreeRoadFastSort(double arr[], int n)
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
	__quicksort3(arr, 0, n - 1);
	QueryPerformanceCounter(&time_over);	             //��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	// ����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000 / ��cpu��Ƶ��΢��
	TimeData pp("��·��������", run_time, sumbbb); //�������ƣ�����ʱ�䣬��������
	return pp;
}
