//���ļ���ȡ����
#include <iostream>
#include <vector>
using namespace std;
extern int SIZE_OF_ARRAY; //ȫ�������С

double* ReadFromFiles() 
{
	cout << "========================================" << endl;
	cout << "===============���ļ�����===============" << endl;
	cout << "========================================" << endl;
	FILE *fp = NULL;
RESETMARK2: //�ļ���������λ��
	cout << "�����ӳ���ͬĿ¼�¶���\"array.txt\"�����س�ȷ��..." << endl;
	getchar();
	fp = fopen("array.txt", "r");
	if (!fp)
	{
		cout << "���ļ�ʧ�ܣ������Ƿ���\"array.txt\"λ��ͬĿ¼��" << endl;
		cout << "========================================" << endl;
		goto RESETMARK2;
	}
	std::vector<double> *arrayTemp = new vector<double>; //ʹ�ö�̬��С��vector����ʵ�ִ��ļ��ж�ȡ��������������
	while (!feof(fp)) {
		double tmp = 0;
		fscanf(fp, "%lf", &tmp);
		arrayTemp->push_back(tmp);
	}
	SIZE_OF_ARRAY = arrayTemp->capacity();
	double *backArray = new double[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		backArray[i] = arrayTemp->at(i);
	}
	fclose(fp); delete arrayTemp;
	return backArray;
}