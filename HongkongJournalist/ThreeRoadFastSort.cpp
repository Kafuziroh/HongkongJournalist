//#include<iostream>
//#include<windows.h>
//#include<algorithm>
//#include"TimeData.h"
//TimeData ThreeRoadFastSort(double a[], int n, int l)
//{
//	int i, j, k;
//	double tmp;
//	double dqFreq;                                       //计时器频率
//	double run_time;
//	_LARGE_INTEGER time_start;	                         //开始时间
//	_LARGE_INTEGER time_over;	                         //结束时间
//	LARGE_INTEGER f;
//	QueryPerformanceFrequency(&f);
//	dqFreq = (double)f.QuadPart;
//	QueryPerformanceCounter(&time_start);	             //计时开始
//	template <typename T>
//	void __quicksort3(T arr[], int l, int r)
//	{
//
//		if (l >= r)
//			return;
//
//		T v = arr[l];
//		int lt = l;
//		int gt = r + 1;
//		int i = l + 1;
//		while (i < gt)
//		{
//			if (arr[i] < v)
//			{
//				swap(arr[i], arr[lt + 1]);
//				lt++;
//				i++;
//			}
//
//			else if (arr[i] > v)
//			{
//				swap(arr[i], arr[gt - 1]);
//				gt--;
//			}
//
//			else
//			{
//				i++;
//			}
//		}
//		swap(arr[l], arr[lt]);
//		__quicksort3(arr, l, lt - 1);
//		__quicksort3(arr, gt, r);
//
//	}
//	template <typename T>
//	void quicksort3(T arr[], int n)
//	{
//		__quicksort3(arr, 0, n - 1);
//	}
//	QueryPerformanceCounter(&time_over);	             //计时结束
//	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
//	// 乘以1000000把单位由秒化为微秒，精度为1000 000 / （cpu主频）微秒
//	TimeData aaa("双向冒泡法排序", run_time, 2 * (n - 1)); //方法名称，所用时间，排序趟数
//	return aaa;
//}
