#include <iostream>

#include "ReaderFromKeyboard.h"
#include "ReaderFromFiles.h"

#include "FastSort.h"

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
	cout << "源数据导入完成，回车进行排序。" << endl;
	cout << "========================================" << endl;

	cout << "冒泡排序中" << endl;
	cout << "选择排序中" << endl;
	cout << "插入排序中" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	return 0;
}