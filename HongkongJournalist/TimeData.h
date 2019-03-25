#ifndef _TIMEDATA
#define _TIMEDATA

//TimeData类，用于存储所需统计数据
#include <iostream>
#include <string>
using namespace std;

class TimeData
{
	string _way; //排序方法
	double _time; //排序时间
	int _tangShu; //排序趟数
public:
	TimeData();
	TimeData(string way, double time, int tangShu);
	TimeData(const TimeData &timeData);
	string GetWay();
	double GetTime();
	int GetTangShu();
};

#endif // !_TIMEDATA