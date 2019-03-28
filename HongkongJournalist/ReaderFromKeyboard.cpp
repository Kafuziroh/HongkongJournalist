//从键盘读取数据
#include <iostream>
using namespace std;
extern int SIZE_OF_ARRAY; //全局数组大小

double* ReadFromKeyboard()
{
	cout << "======================================================" << endl;
	cout << "======================从键盘读入======================" << endl;
	cout << "======================================================" << endl;
	cout << "请输入需要排序的数据个数，回车确认：";
RESETMARK1: //数据错误重置位置
	int arrayNum = 0; //数据个数
	cin >> arrayNum;
	if (arrayNum == 0)
	{
		cout << "======================================================" << endl;
		cout << "数据个数为0，不需要排序，请重新输入需要排序的数据个数：";
		goto RESETMARK1;
	}
	else if (arrayNum == 1)
	{
		cout << "======================================================" << endl;
		cout << "数据个数为1，不需要排序，请重新输入需要排序的数据个数：";
		goto RESETMARK1;
	}
	else if (arrayNum < 0)
	{
		cout << "======================================================" << endl;
		cout << "数据个数小于0，无法排序，请重新输入需要排序的数据个数：";
		goto RESETMARK1;
	}
	else if (arrayNum > 100)
	{
		cout << "======================================================" << endl;
		cout << "数据个数大于100，请通过文件输入需要排序的数据个数：";
		goto RESETMARK1;
	}
	SIZE_OF_ARRAY = arrayNum; //设置数组大小
	cout << "请输入需要排序的数据，以半角空格分隔，回车确认：" << endl;
	double *origArray = new double[arrayNum]; //传递用数据数组
	for (int i = 0; i < arrayNum; i++) {
		scanf("%lf", &origArray[i]);
	}
	return origArray;
}