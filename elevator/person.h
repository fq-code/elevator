#pragma once
const int MAX_WAIT_TIME = 300;//最大等待时间
class person {
private:
	int number;//编号
	int fr_floor;//来自楼层
	int to_floor;//去楼层
	int push_time;//按电梯的时间
public:
	person();
	void init(int num, int from, int to, int p_time); //初始化，得到该乘客的信息
	int GetNum();  //得到乘客的编号
	int GetFr();   //得到乘客的初始楼层
	int GetTo();   //得到乘客的目的楼层
	int Getp_time();  //得到乘客按电梯的时间
};

person::person() {   //初始化(全置-1,表示无意义)  随便输入多少都行
	number = -1;
	fr_floor = -1;
	to_floor = -1;
	push_time = -1;
}
void person::init(int num, int from, int to, int p_time) {
	number = num;
	fr_floor = from;
	to_floor = to;
	push_time = p_time;
}
int person::GetNum() {
	return number;
}
int person::GetFr() {
	return fr_floor;
}
int person::GetTo() {
	return to_floor;
}
int person::Getp_time() {
	return push_time;
}



