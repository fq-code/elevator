#pragma once
const int MAX_WAIT_TIME = 300;//���ȴ�ʱ��
class person {
private:
	int number;//���
	int fr_floor;//����¥��
	int to_floor;//ȥ¥��
	int push_time;//�����ݵ�ʱ��
public:
	person();
	void init(int num, int from, int to, int p_time); //��ʼ�����õ��ó˿͵���Ϣ
	int GetNum();  //�õ��˿͵ı��
	int GetFr();   //�õ��˿͵ĳ�ʼ¥��
	int GetTo();   //�õ��˿͵�Ŀ��¥��
	int Getp_time();  //�õ��˿Ͱ����ݵ�ʱ��
};

person::person() {   //��ʼ��(ȫ��-1,��ʾ������)  ���������ٶ���
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



