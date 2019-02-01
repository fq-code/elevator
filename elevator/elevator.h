#pragma once
#include<string.h>
const int floors = 9;//总楼层数(一律从标号0开始,至floor-1层)
const int maxn = 12;//电梯载重(人数)
enum states { UP, DOWN, CLOSED, WAIT };//电梯运作的状态(上升、下降、关门、等待)
enum direct { U, D };//电梯运作的方向U(上),D(下)
class elevator {
private:
	int curr_floor;//电梯当前所在楼层
	int curr_per;//电梯内当前总人数
	states state;//电梯当前所处状态
	direct dire;//电梯运作的方向
	bool req[floors];//记录有请求的楼层
public:
	elevator();
	int GetFloor();//得到电梯当前楼层
	int Getper();//得到电梯当前人数
	states GetState();   //得到当前的状态
	direct GetDire();    //得到当前的方向
	bool* GetReque();    //请求序列
	void SetState(states sta);  //设置当前电梯的状态
	void SetDire(direct dir);   //设置当前电梯的方向
	void SetFloor(int i);  //设置电梯当前的楼层
	void Setper(int i);//设置电梯当前人数
	void SetReque(int i, bool b);
};

elevator::elevator() {
	curr_floor = 0;//默认1楼为本垒层
	curr_per = 0;
	state = CLOSED;
	dire = U;
	memset(req, false, sizeof req);
}
int elevator::GetFloor() {
	return curr_floor;
}
int elevator::Getper() {
	return curr_per;
}
states elevator::GetState() {
	return state;
}
direct elevator::GetDire() {
	return dire;
}
bool * elevator::GetReque() {
	return req;
}
void elevator::SetFloor(int i) {
	curr_floor = i;
}
void elevator::Setper(int i) {
	curr_per = i;
}
void elevator::SetState(states sta) {
	state = sta;
}
void elevator::SetDire(direct dir) {
	dire = dir;
}
void elevator::SetReque(int i, bool b) {
	req[i] = b;
}



