#include <iostream>
//文件处理
#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"
#include "TimeData.h"
//排序方法
#include "MaoPao.h"
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
	double *arrTemp = new double[SIZE_OF_ARRAY];

	//排序
	cout << "冒泡排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData bubbleSort = MaoPao(arrTemp, SIZE_OF_ARRAY);

	cout << "选择排序中..." << endl;

	cout << "插入排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData insertSort = ChaRu(arrTemp, SIZE_OF_ARRAY);

	cout << "二分排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData splitSort = ErFeng(arrTemp, SIZE_OF_ARRAY);

	cout << "快速排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData fastSort = FastSort(arrTemp, SIZE_OF_ARRAY);

	cout << "双路快速排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData twoWayQuickSort = quicksort(arrTemp, SIZE_OF_ARRAY);

	cout << "SHELL排序中..." << endl;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData shellSort = Shell(arrTemp, SIZE_OF_ARRAY);

	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	getchar();
	return 0;
}