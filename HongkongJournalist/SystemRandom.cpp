#include <iostream>
#include <ctime>
using namespace std;

double* creator() 
{
	int i, k = 0;
	int arr[10000];                          //�������飬�������ɵ������
	double res[10000];                       //���������飬������
	srand((unsigned)time(NULL));
	while (k != 10000) {                     //��������     
		arr[k] = rand();                 //ע����������ķ�Χ
		++k;                             //cout<<list[k]<<" ";  //������     
	}  
	for (i = 0; i != k; ++i) {           //���
		res[i] = arr[i] / 100.0;
	}
	return res;
}