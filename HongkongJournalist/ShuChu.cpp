#include <iostream>
#include <fstream>
#include <sstream>
#include "TimeData.h"
#include "GraphDrawer.h"

using namespace std;

int ShuChu()
{
	ifstream ifile("data_collection.txt");
	if (!ifile)
	{
		return 1;
	}
	int i = 0, j;
	double k;
	TimeData str[10];
	char ste[20];
	string line;
	while (getline(ifile, line))
	{
		if (i > 9)
		{
			break;
		}
		stringstream ss;
		ss << line;
		ss >> ste >> k >> j;
		str[i].SetWay(ste);
		str[i].SetTime(k);
		str[i].SetTangShu(j);
		i++;
	}
	int  gap;
	TimeData temp;
	for (gap = 5; gap > 0; gap /= 2)//�����������
	{
		for (i = gap; i < 10; i++)
		{
			for (j = i - gap; j >= 0 && str[j].GetTime() > str[j + gap].GetTime(); j -= gap)
			{
				temp = str[j];
				str[j] = str[j + gap];
				str[j + gap] = temp;
			}
		}
	}
	GraphDrawer(str);
	ifile.close();
	return 0;
}
