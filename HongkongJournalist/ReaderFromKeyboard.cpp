//�Ӽ��̶�ȡ����
#include <iostream>
using namespace std;
extern int SIZE_OF_ARRAY; //ȫ�������С

double* ReadFromKeyboard()
{
	cout << "======================================================" << endl;
	cout << "======================�Ӽ��̶���======================" << endl;
	cout << "======================================================" << endl;
	cout << "��������Ҫ��������ݸ������س�ȷ�ϣ�";
RESETMARK1: //���ݴ�������λ��
	int arrayNum = 0; //���ݸ���
	cin >> arrayNum;
	if (arrayNum == 0)
	{
		cout << "======================================================" << endl;
		cout << "���ݸ���Ϊ0������Ҫ����������������Ҫ��������ݸ�����";
		goto RESETMARK1;
	}
	else if (arrayNum == 1)
	{
		cout << "======================================================" << endl;
		cout << "���ݸ���Ϊ1������Ҫ����������������Ҫ��������ݸ�����";
		goto RESETMARK1;
	}
	else if (arrayNum < 0)
	{
		cout << "======================================================" << endl;
		cout << "���ݸ���С��0���޷�����������������Ҫ��������ݸ�����";
		goto RESETMARK1;
	}
	else if (arrayNum > 100)
	{
		cout << "======================================================" << endl;
		cout << "���ݸ�������100����ͨ���ļ�������Ҫ��������ݸ�����";
		goto RESETMARK1;
	}
	SIZE_OF_ARRAY = arrayNum; //���������С
	cout << "��������Ҫ��������ݣ��԰�ǿո�ָ����س�ȷ�ϣ�" << endl;
	double *origArray = new double[arrayNum]; //��������������
	for (int i = 0; i < arrayNum; i++) {
		scanf("%lf", &origArray[i]);
	}
	return origArray;
}