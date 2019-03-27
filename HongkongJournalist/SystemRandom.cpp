#include <iostream>
#include <ctime>
using namespace std;

double* creator() 
{
	int i, k = 0;
	int arr[10000];                          //整数数组，保存生成的随机数
	double res[10000];                       //浮点数数组，保存结果
	srand((unsigned)time(NULL));
	while (k != 10000) {                     //生成整数     
		arr[k] = rand();                 //注意随机整数的范围
		++k;                             //cout<<list[k]<<" ";  //调试用     
	}  
	for (i = 0; i != k; ++i) {           //输出
		res[i] = arr[i] / 100.0;
	}
	return res;
}