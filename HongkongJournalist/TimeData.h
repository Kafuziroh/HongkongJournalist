#ifndef _TIMEDATA
#define _TIMEDATA

//TimeData�࣬���ڴ洢����ͳ������
#include <iostream>
#include <string>
using namespace std;

class TimeData
{
	string _way; //���򷽷�
	double _time; //����ʱ��
	int _tangShu; //��������
public:
	TimeData();
	TimeData(string way, double time, int tangShu);
	TimeData(const TimeData &timeData);
	string GetWay();
	double GetTime();
	int GetTangShu();
};

#endif // !_TIMEDATA