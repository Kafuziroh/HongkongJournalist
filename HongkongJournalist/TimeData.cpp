#include "TimeData.h"

TimeData::TimeData()
{
	_way = "";
	_time = 0;
	_tangShu = 0;
}
TimeData::TimeData(string way, double time, int tangShu)
{
	_way=way;
	_time = time;
	_tangShu = tangShu;
}
TimeData::TimeData(const TimeData &timeData)
{
	_way=timeData._way;
	_time = timeData._time;
	_tangShu = timeData._tangShu;
}
string TimeData::GetWay()
{
	return _way;
}
double TimeData::GetTime()
{
	return _time;
}
int TimeData::GetTangShu()
{
	return _tangShu;
}
void TimeData::SetWay(string way)
{
	_way = way;
}
void TimeData::SetTime(double time)
{
	_time = time;
}
void TimeData::SetTangShu(int tangShu)
{
	_tangShu = tangShu;
}
