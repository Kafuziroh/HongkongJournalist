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
	TimeData(); //�޲ι��캯��
	TimeData(string way, double time, int tangShu); //���ι��캯��
	TimeData(const TimeData &timeData); //�������캯��
	string GetWay(); //��ȡ������
	double GetTime(); //��ȡ����ʱ��
	int GetTangShu(); //��ȡ��������
	void SetWay(string way); //���÷�����
	void SetTime(double time); //��������ʱ��
	void SetTangShu(int tangShu); //������������
};

#endif // !_TIMEDATA