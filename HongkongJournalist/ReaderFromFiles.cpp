//���ļ���ȡ����
#include <iostream>
#include <vector>
using namespace std;
extern int SIZE_OF_ARRAY; //ȫ�������С

double* ReadFromFiles()
{
	cout << "======================================================" << endl;
	cout << "======================���ļ�����======================" << endl;
	cout << "======================================================" << endl;
	FILE *fp = NULL;
RESETMARK2: //�ļ���������λ��
	cout << "1. �ӳ���ͬĿ¼����\"array.txt\"Դ����" << endl;
	cout << "2. ����ָ���ļ�" << endl;
	cout << "======================================================" << endl;
	cout << "��ѡ������ļ��ķ�����";
	int chooserTMP = 0;
RESETMARKFILE: //ѡ���������λ��
	cin >> chooserTMP;
	if (chooserTMP != 1 && chooserTMP != 2)
	{
		getchar();
		cout << "======================================================" << endl;
		cout << "ѡ��������������룺";
		goto RESETMARKFILE;
	}
	else if (chooserTMP == 1) //�ӳ���ͬĿ¼�Ķ���"array.txt"Դ����
	{
		cout << "======================================================" << endl;
		cout << "�����ӳ���ͬĿ¼�¶���\"array.txt\"�����س�ȷ��...";
		getchar();
		getchar();
		fp = fopen("array.txt", "r");
	}
	else if (chooserTMP == 2) //����ָ���ļ�
	{
		cout << "======================================================" << endl;
		cout << "�����������ȡ�ļ�������Ŀ¼��" << endl;
		getchar();
		char arraTemp[100];
		gets_s(arraTemp, 100);
		fp = fopen(arraTemp, "r");
	}

	if (!fp)
	{
		cout << "======================================================" << endl;
		cout << "���ļ�ʧ�ܣ�������ѡ��" << endl;
		cout << "======================================================" << endl;
		goto RESETMARK2;
	}
 	std::vector<double> *arrayTemp = new vector<double>; //ʹ�ö�̬��С��vector����ʵ�ִ��ļ��ж�ȡ��������������
	while (!feof(fp)) {
		double tmp = 0;
		fscanf(fp, "%lf", &tmp);
		arrayTemp->push_back(tmp);
	}
	SIZE_OF_ARRAY = arrayTemp->size();
	double *backArray = new double[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		backArray[i] = arrayTemp->at(i);
	}
	fclose(fp); delete arrayTemp;
	return backArray;
}