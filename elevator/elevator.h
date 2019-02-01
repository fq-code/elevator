#pragma once
#include<string.h>
const int floors = 9;//��¥����(һ�ɴӱ��0��ʼ,��floor-1��)
const int maxn = 12;//��������(����)
enum states { UP, DOWN, CLOSED, WAIT };//����������״̬(�������½������š��ȴ�)
enum direct { U, D };//���������ķ���U(��),D(��)
class elevator {
private:
	int curr_floor;//���ݵ�ǰ����¥��
	int curr_per;//�����ڵ�ǰ������
	states state;//���ݵ�ǰ����״̬
	direct dire;//���������ķ���
	bool req[floors];//��¼�������¥��
public:
	elevator();
	int GetFloor();//�õ����ݵ�ǰ¥��
	int Getper();//�õ����ݵ�ǰ����
	states GetState();   //�õ���ǰ��״̬
	direct GetDire();    //�õ���ǰ�ķ���
	bool* GetReque();    //��������
	void SetState(states sta);  //���õ�ǰ���ݵ�״̬
	void SetDire(direct dir);   //���õ�ǰ���ݵķ���
	void SetFloor(int i);  //���õ��ݵ�ǰ��¥��
	void Setper(int i);//���õ��ݵ�ǰ����
	void SetReque(int i, bool b);
};

elevator::elevator() {
	curr_floor = 0;//Ĭ��1¥Ϊ���ݲ�
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



