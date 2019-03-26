#include <iostream>
#include <algorithm>
#include <fstream>
//�ļ�����
#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"
#include "TimeData.h"
#include "DataCollection.h"
#include "GraphDrawer.h"
//���򷽷�
#include "MaoPao.h"
#include "ChooseSort.h"
#include "ChaRu.h"
#include "ErFeng.h"
#include "FastSort.h"
#include "ShuangXiangKuaiPai.h"
#include "Shell.h"
#include "EXChangeSort.h"
#include "TwoWayBubbleSort.h"
#include "ThreeRoadFastSort.h"

using namespace std;
int SIZE_OF_ARRAY = 0; //ȫ�������С

int main()
{
	//����
	{
		cout << "==============================================" << endl;
		cout << "============��˭�ŵÿ죨��ۼ��ߣ�============" << endl;
		cout << "==============================================" << endl;
	}

	//���ݶ��뷽��ѡ��
	cout << "==============================================" << endl;
	cout << "1. �Ӽ���ֱ������Դ����" << endl;
	cout << "2. ���ļ�����Դ����" << endl;
	cout << "==============================================" << endl;
	cout << "��ѡ�����Դ���ݵķ�����";
	int chooser = 0;
	double *arr = NULL;
RESETMARK0: //���ݴ�������λ��
	cin >> chooser;
	if (chooser != 1 && chooser != 2)
	{
		cout << "==============================================" << endl;
		cout << "ѡ��������������룺";
		goto RESETMARK0;
	}
	else if (chooser == 1) //�Ӽ���ֱ������Դ����
	{
		arr = ReadFromKeyboard();
	}
	else if (chooser == 2) //���ļ�����Դ����
	{
		arr = ReadFromFiles();
	}

	//����
	cout << "==============================================" << endl;
	cout << "Դ���ݵ�����ɣ��س���������...";
	getchar();
	double *arrTemp = new double[SIZE_OF_ARRAY];
	cout << "==============================================" << endl;
	cout << "1. ð��������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData bubbleSort = MaoPao(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << bubbleSort.GetTime() << "��s " << "��������" << bubbleSort.GetTangShu() << "��" << endl;
	cout << "2. ˫��ð��������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData dbBubbleSort = TwoWayBubbleSort(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << dbBubbleSort.GetTime() << "��s " << "��������" << dbBubbleSort.GetTangShu() << "��" << endl;
	cout << "3. ѡ��������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData chooseSort = ChooseSort(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << chooseSort.GetTime() << "��s " << "��������" << chooseSort.GetTangShu() << "��" << endl;
	cout << "4. ����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData insertSort = ChaRu(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << insertSort.GetTime() << "��s " << "��������" << insertSort.GetTangShu() << "��" << endl;
	cout << "5. ����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData splitSort = ErFeng(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << splitSort.GetTime() << "��s " << "��������" << splitSort.GetTangShu() << "��" << endl;
	cout << "6. ����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData exchangeSort = ChangeSort(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << exchangeSort.GetTime() << "��s " << "��������" << exchangeSort.GetTangShu() << "��" << endl;
	cout << "7. ����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData quickSort = FastSort(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << quickSort.GetTime() << "��s " << "��������" << quickSort.GetTangShu() << "��" << endl;
	cout << "8. ˫·����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData twoWQuickSort = quicksortT(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << twoWQuickSort.GetTime() << "��s " << "��������" << twoWQuickSort.GetTangShu() << "��" << endl;
	cout << "9. ��·����������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData trWQuickSort = ThreeRoadFastSort(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << trWQuickSort.GetTime() << "��s " << "��������" << trWQuickSort.GetTangShu() << "��" << endl;
	cout << "10. SHELL������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData shellSort = Shell(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << shellSort.GetTime() << "��s " << "��������" << shellSort.GetTangShu() << "��" << endl;

	//�ļ�����
FILEERROR:
	cout << "==============================================" << endl;
	cout << "������ɣ��س��鿴���ܶԱ������������ļ�...";
	getchar();

	TimeData *dataArray = new TimeData[10]; //�����������
	dataArray[0] = bubbleSort;
	dataArray[1] = dbBubbleSort;
	dataArray[2] = chooseSort;
	dataArray[3] = insertSort;
	dataArray[4] = splitSort;
	dataArray[5] = exchangeSort;
	dataArray[6] = quickSort;
	dataArray[7] = twoWQuickSort;
	dataArray[8] = trWQuickSort;
	dataArray[9] = shellSort;
	if (DataCollection(dataArray)) //������ʧ��
	{
		goto FILEERROR;
	};
	cout << "==============================================" << endl;
	cout << "�ļ�������ɣ��س��鿴���ݶԱ����...";
	getchar();

	//�Զ�����������������
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (dataArray[j].GetTime() > dataArray[j + 1].GetTime())
			{
				swap(dataArray[j], dataArray[j + 1]);
			}
		}
	}
	fstream opener;
	opener.open("D:\\data_collection.txt", ios::app); //��׷�ӷ�ʽ���ļ�
	opener << "=====����������������=====" << endl;
	for (int i = 0; i < 10; i++)
	{
		opener << dataArray[i].GetWay() << " " << dataArray[i].GetTime() << " " << dataArray[i].GetTangShu() << endl;
	}

	GraphDrawer(dataArray);
	getchar();
	return 0;
}