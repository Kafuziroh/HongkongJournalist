//TimeData�࣬���ڴ洢����ͳ������
//�ų���
#include <iostream>
using namespace std;

class TimeData
{
private:
	string _way; //���򷽷�
	double _time; //����ʱ��
	int _tangShu; //��������
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