//数据输出至文本
#include <iostream>
#include <fstream>
#include "TimeData.h"
using namespace std;

int DataCollection(TimeData dataArray[]) {
	ofstream ofile("D:\\data_collection.txt");
	if (!ofile)
	{
		cout << "建立文件失败，请检查用户是否有程序所在文件夹的写入权限" << endl;
		return 1; //失败为1
	}
	for (int i = 0; i < 10 ; i++)
	{
		ofile << dataArray[i].GetWay() << " " << dataArray[i].GetTime() << " " << dataArray[i].GetTangShu() << endl;
	}
	return 0; //成功为0
}