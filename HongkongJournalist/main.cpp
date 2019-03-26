#include <iostream>
//文件处理
#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"
#include "TimeData.h"
#include "DataCollection.h"
//排序方法
#include "MaoPao.h"
#include "ChooseSort.h"
#include "ChaRu.h"
#include "ErFeng.h"
#include "FastSort.h"
#include "ShuangXiangKuaiPai.h"
#include "Shell.h"

using namespace std;
int SIZE_OF_ARRAY = 0; //全局数组大小

int main()
{
	cout << "========================================" << endl;
	cout << "=========看谁排得快（香港记者）=========" << endl;
	cout << "========================================" << endl;

	//数据读入方法选择
	cout << "========================================" << endl;
	cout << "1. 从键盘直接输入源数据" << endl;
	cout << "2. 从文件读入源数据" << endl;
	cout << "========================================" << endl;
	cout << "请选择读入源数据的方法：";
	int chooser = 0;
	double *arr = NULL;

RESETMARK0: //数据错误重置位置
	cin >> chooser;
	if (chooser != 1 && chooser != 2)
	{
		cout << "========================================" << endl;
		cout << "选择错误，请重新输入：";
		goto RESETMARK0;
	}
	else if (chooser == 1) //从键盘直接输入源数据
	{
		arr = ReadFromKeyboard();
	}
	else if (chooser == 2) //从文件读入源数据
	{
		arr = ReadFromFiles();
	}
	cout << "========================================" << endl;
	cout << "源数据导入完成，回车进行排序" << endl;
	cout << "========================================" << endl;
	getchar();
	getchar();
	double *arrTemp = new double[SIZE_OF_ARRAY];

	//排序
	cout << "1. 冒泡排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData bubbleSort = MaoPao(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << bubbleSort.GetTime() << "μs " << "排序趟数" << bubbleSort.GetTangShu() << "次" << endl;

	cout << "3. 选择排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData chooseSort = ChooseSort(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << chooseSort.GetTime() << "μs " << "排序趟数" << chooseSort.GetTangShu() << "次" << endl;

	cout << "4. 插入排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData insertSort = ChaRu(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << insertSort.GetTime() << "μs " << "排序趟数" << insertSort.GetTangShu() << "次" << endl;

	cout << "5. 二分排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData splitSort = ErFeng(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << splitSort.GetTime() << "μs " << "排序趟数" << splitSort.GetTangShu() << "次" << endl;

	cout << "7. 快速排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData quickSort = FastSort(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << quickSort.GetTime() << "μs " << "排序趟数" << quickSort.GetTangShu() << "次" << endl;

	cout << "8. 双路快速排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData twoWQuickSort = quicksortT(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << twoWQuickSort.GetTime() << "μs " << "排序趟数" << twoWQuickSort.GetTangShu() << "次" << endl;

	cout << "10. SHELL排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData shellSort = Shell(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << shellSort.GetTime() << "μs " << "排序趟数" << shellSort.GetTangShu() << "次" << endl;
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