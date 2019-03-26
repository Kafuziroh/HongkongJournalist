#include <iostream>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;

int GraphDrawer(TimeData arr[])
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                          数据图表                                        ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << "■ " << arr[k].GetWay() << " ■ " << arr[k].GetTangShu() << "次排序 ■" << endl;
		for (int i = 0; i <= (int((arr[k].GetTime()) / double(SIZE_OF_ARRAY / 20))) * 2; i++) //以数组总大小决定长度范围避免图表过长
		{
			cout << "■";
		}
		cout << " " << arr[k].GetTime() << "μs" << endl << endl;
	}
	return 0;
}
