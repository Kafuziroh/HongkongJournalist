#include <iostream>
//�ļ�����
#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"
#include "TimeData.h"
#include "DataCollection.h"
//���򷽷�
#include "MaoPao.h"
#include "ChooseSort.h"
#include "ChaRu.h"
#include "ErFeng.h"
#include "FastSort.h"
#include "ShuangXiangKuaiPai.h"
#include "Shell.h"

using namespace std;
int SIZE_OF_ARRAY = 0; //ȫ�������С

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
	double *arr = NULL;

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
		arr = ReadFromKeyboard();
	}
	else if (chooser == 2) //���ļ�����Դ����
	{
		arr = ReadFromFiles();
	}
	cout << "========================================" << endl;
	cout << "Դ���ݵ�����ɣ��س���������" << endl;
	cout << "========================================" << endl;
	getchar();
	getchar();
	double *arrTemp = new double[SIZE_OF_ARRAY];

	//����
	cout << "1. ð��������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData bubbleSort = MaoPao(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << bubbleSort.GetTime() << "��s " << "��������" << bubbleSort.GetTangShu() << "��" << endl;

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

	cout << "10. SHELL������... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData shellSort = Shell(arrTemp, SIZE_OF_ARRAY);
	cout << "��ʱ" << shellSort.GetTime() << "��s " << "��������" << shellSort.GetTangShu() << "��" << endl;
	getchar();
	getchar();

	TimeData *dataArray = new TimeData[10];
	dataArray[0] = bubbleSort;
	dataArray[1] = bubbleSort;
	dataArray[2] = chooseSort;
	dataArray[3] = insertSort;
	dataArray[4] = splitSort;
	dataArray[5] = bubbleSort;
	dataArray[6] = quickSort;
	dataArray[7] = twoWQuickSort;
	dataArray[8] = bubbleSort;
	dataArray[9] = shellSort;
	if (DataCollection(dataArray))
	{

	};
	getchar();
	getchar();
	return 0;
}