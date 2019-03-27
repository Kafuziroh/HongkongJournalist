#include <iostream>
#include <algorithm>
#include <fstream>
//文件处理
#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"
#include "TimeData.h"
#include "DataCollection.h"
#include "GraphDrawer.h"
#include "ShuChu.h"
//排序方法
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
int SIZE_OF_ARRAY = 0; //全局数组大小

int main()
{
	//标题
	{
		cout << "==============================================" << endl;
		cout << "============看谁排得快（香港记者）============" << endl;
		cout << "==============================================" << endl;
	}

	//数据读入方法选择
	cout << "==============================================" << endl;
	cout << "1. 读入源数据进行排序和分析" << endl;
	cout << "2. 从data_collection.txt读入排序结果直接进行分析" << endl;
	cout << "==============================================" << endl;
	cout << "请选择要执行的程序：";
	int chooser = 0;
RESETMARK00: //选择错误重置位置
	cin >> chooser;
	getchar();
	if (chooser != 1 && chooser != 2)
	{
		cout << "==============================================" << endl;
		cout << "选择错误，请重新输入：";
		goto RESETMARK00;
	}
	else if (chooser == 1) //读入源数据进行排序和分析
	{
		goto PROCESS1;
	}
	else if (chooser == 2) //从文件读入排序结果直接进行分析
	{
		FILEERRORA:
		if (ShuChu())
		{
			cout << "==============================================" << endl;
			cout << "读取文件失败或文件不存在，回车重试...";
			getchar();
			goto FILEERRORA;
		}
		getchar();
		return 0;
	}

PROCESS1: //读入源数据进行排序和分析
	//数据读入方法选择
	cout << "==============================================" << endl;
	cout << "1. 从键盘直接输入源数据" << endl;
	cout << "2. 从文件读入源数据" << endl;
	cout << "==============================================" << endl;
	cout << "请选择读入源数据的方法：";
	chooser = 0;
	double *arr = NULL;
RESETMARK0: //数据错误重置位置
	cin >> chooser;
	if (chooser != 1 && chooser != 2)
	{
		cout << "==============================================" << endl;
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

	//排序
	cout << "==============================================" << endl;
	cout << "源数据导入完成，回车进行排序...";
	getchar();
	double *arrTemp = new double[SIZE_OF_ARRAY];
	cout << "==============================================" << endl;
	cout << "1. 冒泡排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData bubbleSort = MaoPao(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << bubbleSort.GetTime() << "μs " << "排序趟数" << bubbleSort.GetTangShu() << "次" << endl;
	cout << "2. 双向冒泡排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData dbBubbleSort = TwoWayBubbleSort(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << dbBubbleSort.GetTime() << "μs " << "排序趟数" << dbBubbleSort.GetTangShu() << "次" << endl;
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
	cout << "6. 交换排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData exchangeSort = ChangeSort(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << exchangeSort.GetTime() << "μs " << "排序趟数" << exchangeSort.GetTangShu() << "次" << endl;
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
	cout << "9. 三路快速排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData trWQuickSort = ThreeRoadFastSort(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << trWQuickSort.GetTime() << "μs " << "排序趟数" << trWQuickSort.GetTangShu() << "次" << endl;
	cout << "10. SHELL排序中... ";
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrTemp[i] = arr[i];
	}
	TimeData shellSort = Shell(arrTemp, SIZE_OF_ARRAY);
	cout << "用时" << shellSort.GetTime() << "μs " << "排序趟数" << shellSort.GetTangShu() << "次" << endl;

	//文件处理
FILEERROR:
	cout << "==============================================" << endl;
	cout << "排序完成，回车输出至文件...";
	getchar();

	TimeData *dataArray = new TimeData[10]; //建立结果数组
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
	if (DataCollection(dataArray)) //如果输出失败
	{
		cout << "==============================================" << endl;
		cout << "文件生成失败，回车尝试重新生成...";
		goto FILEERROR;
	};

	//对对象数组进行排序分析
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
	opener.open("data_collection.txt", ios::app); //以追加方式打开文件
	opener << "=====排序分析用数据输出=====" << endl;
	for (int i = 0; i < 10; i++)
	{
		opener << dataArray[i].GetWay() << " " << dataArray[i].GetTime() << " " << dataArray[i].GetTangShu() << endl;
	}

DRAWERROR: //图表绘制重置点
	cout << "==============================================" << endl;
	cout << "文件已成功生成在程序目录下，回车查看图表...";
	getchar();
	if (GraphDrawer(dataArray)) //如果绘图失败
	{
		cout << "==============================================" << endl;
		cout << "图表绘制失败，回车尝试重新生成...";
		goto DRAWERROR;
	};
	
	getchar();
	return 0;
}