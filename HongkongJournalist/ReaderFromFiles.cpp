//从文件读取数据
#include <iostream>
#include <vector>
using namespace std;
extern int SIZE_OF_ARRAY; //全局数组大小

double* ReadFromFiles()
{
	cout << "======================================================" << endl;
	cout << "======================从文件读入======================" << endl;
	cout << "======================================================" << endl;
	FILE *fp = NULL;
RESETMARK2: //文件错误重置位置
	cout << "1. 从程序同目录读入\"array.txt\"源数据" << endl;
	cout << "2. 读入指定文件" << endl;
	cout << "======================================================" << endl;
	cout << "请选择读入文件的方法：";
	int chooserTMP = 0;
RESETMARKFILE: //选择错误重置位置
	cin >> chooserTMP;
	if (chooserTMP != 1 && chooserTMP != 2)
	{
		getchar();
		cout << "======================================================" << endl;
		cout << "选择错误，请重新输入：";
		goto RESETMARKFILE;
	}
	else if (chooserTMP == 1) //从程序同目录赌读入"array.txt"源数据
	{
		cout << "======================================================" << endl;
		cout << "即将从程序同目录下读入\"array.txt\"，按回车确认...";
		getchar();
		getchar();
		fp = fopen("array.txt", "r");
	}
	else if (chooserTMP == 2) //读入指定文件
	{
		cout << "======================================================" << endl;
		cout << "请输入所需读取文件的完整目录：" << endl;
		getchar();
		char arraTemp[100];
		gets_s(arraTemp, 100);
		fp = fopen(arraTemp, "r");
	}

	if (!fp)
	{
		cout << "======================================================" << endl;
		cout << "打开文件失败，请重新选择" << endl;
		cout << "======================================================" << endl;
		goto RESETMARK2;
	}
 	std::vector<double> *arrayTemp = new vector<double>; //使用动态大小的vector容器实现从文件中读取不定数量的数据
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