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
	TimeData(); //无参构造函数
	TimeData(string way, double time, int tangShu); //带参构造函数
	TimeData(const TimeData &timeData); //拷贝构造函数
	string GetWay(); //获取方法名
	double GetTime(); //获取运行时间
	int GetTangShu(); //获取排序趟数
	void SetWay(string way); //设置方法名
	void SetTime(double time); //设置运行时间
	void SetTangShu(int tangShu); //设置排序趟数
};

#endif // !_TIMEDATA