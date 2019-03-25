//从文件读取数据
#include <iostream>
using namespace std;

double* ReadFromFiles() 
{
	cout << "========================================" << endl;
	cout << "===============从文件读入===============" << endl;
	cout << "========================================" << endl;
	
	double *origArray = new double[arrayNum]; //传递用数据数组
	for (int i = 0; i < arrayNum; i++) {
		cin >> origArray[i];
	}
	return origArray;
}