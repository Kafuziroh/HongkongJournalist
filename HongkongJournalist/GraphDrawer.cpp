#include <iostream>
#include "TimeData.h"

using namespace std;
extern int SIZE_OF_ARRAY;

int GraphDrawer(TimeData arr[])
{
	cout << "����������������������������������������������������������������������������������������������" << endl;
	cout << "��                                          ����ͼ��                                        ��" << endl;
	cout << "����������������������������������������������������������������������������������������������" << endl << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << "�� " << arr[k].GetWay() << " �� " << arr[k].GetTangShu() << "������ ��" << endl;
		for (int i = 0; i <= (int((arr[k].GetTime()) / double(SIZE_OF_ARRAY / 20))) * 2; i++) //�������ܴ�С�������ȷ�Χ����ͼ�����
		{
			cout << "��";
		}
		cout << " " << arr[k].GetTime() << "��s" << endl << endl;
	}
	return 0;
}
