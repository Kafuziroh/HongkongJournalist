//从文件读取数据
#include <iostream>
#include <vector>
using namespace std;
extern int SIZE_OF_ARRAY; //全局数组大小

double* ReadFromFiles() 
{
	cout << "========================================" << endl;
	cout << "===============从文件读入===============" << endl;
	cout << "========================================" << endl;
	FILE *fp = NULL;
RESETMARK2: //文件错误重置位置
	cout << "即将从程序同目录下读入\"array.txt\"，按回车确认..." << endl;
	getchar();
	fp = fopen("array.txt", "r");
	if (!fp)
	{
		cout << "打开文件失败，请检查是否有\"array.txt\"位于同目录下" << endl;
		cout << "========================================" << endl;
		goto RESETMARK2;
	}
	std::vector<double> *arrayTemp = new vector<double>; //使用动态大小的vector容器实现从文件中读取不定数量的数据
	while (!feof(fp)) {
		double tmp = 0;
		fscanf(fp, "%lf", &tmp);
		arrayTemp->push_back(tmp);
	}
	SIZE_OF_ARRAY = arrayTemp->capacity();
	double *backArray = new double[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		backArray[i] = arrayTemp->at(i);
	}
	fclose(fp); delete arrayTemp;
	return backArray;
}