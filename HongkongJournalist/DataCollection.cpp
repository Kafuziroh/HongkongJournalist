//����������ı�
#include <iostream>
#include <fstream>
#include "TimeData.h"
using namespace std;

int DataCollection(TimeData dataArray[]) {
	ofstream ofile("D:\\data_collection.txt");
	if (!ofile)
	{
		cout << "�����ļ�ʧ�ܣ������û��Ƿ��г��������ļ��е�д��Ȩ��" << endl;
		return 1; //ʧ��Ϊ1
	}
	for (int i = 0; i < 10 ; i++)
	{
		ofile << dataArray[i].GetWay() << " " << dataArray[i].GetTime() << " " << dataArray[i].GetTangShu() << endl;
	}
	return 0; //�ɹ�Ϊ0
}