//TimeData类，用于存储所需统计数据
//张承扬
#include <iostream>
using namespace std;

class TimeData
{
private:
	string _way; //排序方法
	double _time; //排序时间
	int _tangShu; //排序趟数
public:
	TimeData();
	TimeData(string way, double time, double tangShu);
	string GetWay();
	double GetTime();
	double GetTangShu();
};
TimeData::TimeData() {}
TimeData::TimeData(string way, double time,double tangShu)
{
	_way = way;
	_time = time;
	_tangShu = tangShu;
}
string TimeData::GetWay()
{
	return _way;
}
double TimeData::GetTime()
{
	return _time;
}
double TimeData::GetTangShu()
{
	return _time;
}