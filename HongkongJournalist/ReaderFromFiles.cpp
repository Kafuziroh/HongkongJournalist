//���ļ���ȡ����
#include <iostream>
using namespace std;

double* ReadFromFiles() 
{
	cout << "========================================" << endl;
	cout << "===============���ļ�����===============" << endl;
	cout << "========================================" << endl;
	
	double *origArray = new double[arrayNum]; //��������������
	for (int i = 0; i < arrayNum; i++) {
		cin >> origArray[i];
	}
	return origArray;
}