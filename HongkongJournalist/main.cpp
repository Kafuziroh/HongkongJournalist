#include <iostream>

#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"

#include "FastSort.h"

using namespace std;

int main()
{
	cout << "========================================" << endl;
	cout << "=========��˭�ŵÿ죨��ۼ��ߣ�=========" << endl;
	cout << "========================================" << endl;
	//���ݶ��뷽��ѡ��
	cout << "========================================" << endl;
	cout << "1. �Ӽ���ֱ������Դ����" << endl;
	cout << "2. ���ļ�����Դ����" << endl;
	cout << "========================================" << endl;
	cout << "��ѡ�����Դ���ݵķ�����";
	int chooser = 0;
RESETMARK0: //���ݴ�������λ��
	cin >> chooser;
	if (chooser != 1 && chooser != 2)
	{
		cout << "========================================" << endl;
		cout << "ѡ��������������룺";
		goto RESETMARK0;
	}
	else if (chooser == 1) //�Ӽ���ֱ������Դ����
	{
		double *tmp = ReadFromKeyboard();
	}
	else if (chooser == 2) //���ļ�����Դ����
	{

	}
	return 0;
}