#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"elevator.h"//����ͷ�ļ�
#include"person.h"//��ͷ�ļ�
#include"Queue.h"//�ȴ�����
#include"List.h"//�����ڵ�������
#include<iostream>
#include<fstream>   //C++�ļ���
#include<iomanip>   
using namespace std;
int Time = 0;//ϵͳ��ʱ��
int WaitTime = 0;//���ڼ�¼��������ʱ�䣬����300t,���ݷ��ر��ݲ�
int TestTime = 0; //�������˽���ʱ���м��ļ�ʱ��
int count = 0; //�����������˽���ʱ���м��ı���
elevator elev;//����(Ĭ�ϳ�ʼ״̬�ڱ��ݲ�ȴ�)     
List<person> elev_list;//�����ڵ��˵Ĵ洢����
Queue<person> f_queue[floors];//

void readFile() {//���ļ����Գ�ʼ���ȴ�����
	ifstream infile;
	infile.open("d:\\�����ļ�.txt");
	char c;
	while (1) {
		person per;
		int a, b, c, d;//�ֱ�Ϊ�˵ı�š�����¥�㡢ȥ��¥�㡢����ʱ��
		infile >> a >> b >> c >> d;
		per.init(a, b, c, d);  //��ʼ���˿͵���Ϣ
		int from = per.GetFr();//�õ����˵�����¥��
		f_queue[from].Append(per);//����������Ӧ¥��ĵȴ�����
		if (infile.eof() != 0) break;//�ļ����꣬�˳�
	}
	infile.close();
}
void reset_req() {   //���õ��ݵ���������
	for (int i = 0; i < floors; i++) {    //�����ȴ������Ƿ�������
										  //���зǿ��Ҷ�ͷԪ������ʱ����ڵ�ǰʱ�䣬��ò㷢������
		if (f_queue[i].NotEmpty()) {      //�ǿղ��п���������
			int size = f_queue[i].Size();
			for (int j = 0; j < size; j++) {
				if (f_queue[i].GetData(j).Getp_time() == Time) {
					cout << endl;
					cout << "*��" << Time << "tʱ��*    " << f_queue[i].GetData(j).GetNum() << "�ų˿Ͱ��µ��ݰ�ť���������� " << "*F" << i << " ---> " << "F" << f_queue[i].GetData(j).GetTo() << "*" << endl;
					cout << endl;
					elev.SetReque(i, true);//�����ݵ���Ӧ¥�������������true(ģ��ÿ��һ���ˣ���һ�µ���)
				}
			}
		}
	}
	for (int i = 0; i < elev_list.Size(); i++) {//���������������ȥ��¥����ˢ�·�������
		int to = elev_list.GetData(i).GetTo();
		elev.SetReque(to, true);//�����ݵ���Ӧ¥�������������true
	}
}

void up() {//��������һ��¥(Ҫ��51tʱ��)
	int f = elev.GetFloor();//��ȡ���ݵ�ǰ¥��
//��������
	cout << endl;
	/*	for (int i = 1; i <= 15;++i) {
			if (i == 15) cout << "*��" << Time << "tʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl << endl;
			else cout << "*��" << Time << "tʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
	int p1 = Time, q1 = 0;
	for (int i = 1; i <= 15; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q1 = Time;
	cout << "*��" << p1 << "tʱ�̵� " << q1 << "ʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;
	//��������
	cout << endl;
	/*	for (int i = 1; i <= 22;++i) {
			if(i==22) cout << "*��" << Time << "tʱ��*    " << "��������������������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl<<endl;
			else cout << "*��" << Time << "tʱ��*    " << "��������������������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
	int p2 = Time, q2 = 0;
	for (int i = 1; i <= 22; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q2 = Time;
	cout << "*��" << p2 << "tʱ�̵� " << q2 << "ʱ��*    " << "��������������������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;

	//��������
	cout << endl;
	/*	for (int i = 1; i <= 14;++i) {
			if(i==14) cout << "*��" << Time << "tʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl<<endl;
			else cout << "*��" << Time << "tʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
	int p3 = Time, q3 = 0;
	for (int i = 1; i <= 14; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q3 = Time;
	cout << "*��" << p3 << "tʱ�̵� " << q3 << "ʱ��*    " << "�������ڼ�����������ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;
	//״̬�仯
	elev.SetFloor(f + 1);//¥������һ
	reset_req();
	elev.SetState(WAIT);//����һ�㣬��������״̬ת��ΪWAIT
	elev.SetDire(U);//����״̬��U
}

void down() {//���ݵ����½�һ��¥
	int f = elev.GetFloor();
	//�����½�
	cout << endl;
	int p1 = Time, q1 = 0;
	for (int i = 1; i <= 15; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q1 = Time;
	cout << "*��" << p1 << "tʱ�̵� " << q1 << "ʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;
	/*	for (int i = 1; i <= 15; ++i) {
			if(i==15) cout << "*��" << Time << "tʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl<<endl;
			else cout << "*��" << Time << "tʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
		//�����½�
	cout << endl;
	/*	for (int i = 1; i <= 23; ++i) {
			if(i==23) cout << "*��" << Time << "tʱ��*    " << "�������������½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl<<endl;
			else cout << "*��" << Time << "tʱ��*    " << "�������������½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
	int p2 = Time, q2 = 0;
	for (int i = 1; i <= 23; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q2 = Time;
	cout << "*��" << p2 << "tʱ�̵� " << q2 << "ʱ��*    " << "�������������½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;
	//�����½�
	cout << endl;
	/*	for (int i = 1; i <= 23; ++i) {
			if(i==23) cout << "*��" << Time << "tʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl<<endl;
			else cout << "*��" << Time << "tʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f - 1 << "֮��*    �����ڳ˿���Ϊ��"<< elev.Getper() << endl;
			Time++;//ʱ��һ����
			reset_req();//��Ҫˢ�µ��ݵ���������
		}*/
	int p3 = Time, q3 = 0;
	for (int i = 1; i <= 23; ++i) {
		Time++;//ʱ��һ����
		reset_req();//��Ҫˢ�µ��ݵ���������
	}
	q3 = Time;
	cout << "*��" << p3 << "tʱ�̵� " << q3 << "ʱ��*    " << "�������ڼ����½�����ʱ����λ��: *F" << f << "��F" << f + 1 << "֮��*    �����ڳ˿���Ϊ��" << elev.Getper() << endl;
	//״̬�仯
	elev.SetFloor(f - 1);//¥������һ
	reset_req();
	elev.SetState(WAIT);//����һ�㣬��������״̬ת��ΪWAIT
	elev.SetDire(U);//����״̬��U
}
void open() {               //���ݿ���
	int f = elev.GetFloor();//��õ�ǰ¥��
/*	for (int i = 1; i <= 20; ++i) {
		cout << "��" << Time << "tʱ��    " << "�������ڿ��ţ���ʱ����λ��: *F" << f << "*" << endl;
		Time++;
		reset_req();
	}*/
	int p = Time, q = 0;
	for (int i = 0; i < 20; ++i) {
		Time++;
		reset_req;
	}
	q = Time;
	cout << "��" << p << "tʱ�̵� " << q << "tʱ��*    " << "�������ڿ��ţ���ʱ����λ��: *F" << f << "*" << endl;
}

void close() {              //���ݹ���(�뿪���෴)
	int f = elev.GetFloor();//��õ�ǰ¥��
/*	for (int i = 1; i <= 20; ++i) {
		cout << "��" << Time << "tʱ��    " << "�������ڹ��ţ���ʱ����λ��: *F" << f << "*" << endl;
		Time++;
		reset_req();
	}*/
	int p = Time, q = 0;
	for (int i = 0; i < 20; ++i) {
		Time++;
		reset_req;
	}
	q = Time;
	cout << "��" << p << "tʱ�̵� " << q << "tʱ��*    " << "�������ڹ��ţ���ʱ����λ��: *F" << f << "*" << endl;
}

void come_in() {        //������
	int f = elev.GetFloor();
	int count = 0;
	if (f_queue[f].NotEmpty()) {//��¥�ȴ����зǿգ��ſ��������ϵ���(ע��:�п������������ϵ���)
		while (1) {
			if (f_queue[f].NotEmpty()) {
				int t = f_queue[f].GetFront().Getp_time();//ȡ��ͷ�ĵ���ʱ��
				if (t > Time) break;   //��ͷ����ʱ�����ϵͳ��ǰʱ�䣬�������ϵ��ݣ��˳�
			}
			else {    //�ȴ������ѿգ��������ϵ��ݣ��˳�
				break;
			}
			bool is_in = false;//��¼�Ƿ����˽�����
			int t = f_queue[f].GetFront().Getp_time();//ȡ��ͷ�ĵ���ʱ��
			if (Time - t > MAX_WAIT_TIME) {         //�ȴ�ʱ������������ʱ�䣬������뿪
				cout << "*��" << Time << "tʱ��*    " << f_queue[f].GetFront().GetNum() << "�ų˿����ڳ������ȴ�ʱ�����뿪" << endl;
				f_queue[f].Delete();//�Ӷ�����ɾ�����뿪����
			}
			else {      //�ȴ�ʱ��С�ڵ����������ʱ�䣬������뿪��ͷ�������
				if (elev.Getper() == maxn) {//����
					cout << endl;
					cout << "*��" << Time << "tʱ��*    " << "�Բ���!���ڵ��������Ѵ����ޣ����Ե�! ��ʱ����λ�ã�*F" << f << "*" << endl;
					cout << endl;
					break;
				}
				else {     //û���أ���!
					cout << endl;
					cout << "*��" << Time << "tʱ��*    " << f_queue[f].GetFront().GetNum() << "�ų˿ͽ����� *��F" << f << "*" << endl;
					cout << endl;
					count++;
					if (count == 1) TestTime = Time;//��ͷ�˽����������װ��
					elev_list.Add(f_queue[f].GetFront());//��ӵ�������������
					elev.Setper(elev.Getper() + 1);
					f_queue[f].Delete();//�Ӷ�����ɾ���ѽ�����ݵ���
					is_in = true;
				}
			}
			if (is_in) {//�����ϵ��ݣ�ʱ������25t
				for (int i = 0; i < 25; i++) {//������ÿ����25tʱ��
					Time++;
					reset_req();
					if ((Time - TestTime) % 25 == 0) {
						cout << endl;
						cout << "*��" << Time << "tʱ��*    " << "  ���ݼ�⣬��ʱ����λ�ã�*F" << f << "* " << "���ܹ���!" << endl;
						cout << endl;
					}
					cout << "*��" << Time << "tʱ��*    " << "  �˿����ڽ�����, ��ʱ����λ�ã�*F" << f << "*" << endl;
				}
			}
		}
	}
}

void Wait() {
	int f = elev.GetFloor();//��õ��ݵ�ǰ¥��
	if (!elev.GetReque()[f]) elev.SetState(CLOSED);//���ò������������ò�
	else {//�ò�������,�㿪�ŷ���(���º���)
		open();//���ݿ���;
			   /*�µ���*/
		bool is_out = false;//��¼�Ƿ������µ���
		cout << endl;
		for (int i = 0; i < elev_list.Size(); i++) {//�µ���
			if (elev_list.GetData(i).GetTo() == f) {//����ȥ��¥����ڸ�¥�㣬������µ���
				cout << "*��" << Time << "tʱ��*    " << elev_list.GetData(i).GetNum() << "�ų˿ͳ�����, ��ʱ����λ�ã�*F" << f << "*" << endl;
				elev_list.Delete(i);//�ڵ�������������ɾ���µ��ݵ���
				elev.Setper(elev.Getper() - 1);
				i--;//��������ɾ��Ԫ�أ�iֵӦ��һ���Ų��ᵼ������������δ��⵽
				is_out = true;
			}
		}
		if (is_out) {//�µ���ͳһ��25tʱ��
			cout << endl;
			for (int i = 0; i < 25; i++) {
				Time++;
				reset_req();
				cout << "*��" << Time << "tʱ��*    " << "  �˿ͳ�����, ��ʱ����λ�ã�*F" << f << "*" << endl;
			}
		}
		come_in();//�ϵ���
		elev.SetReque(f, false);//��¥������ȡ��
		while (1) {
			Time++;
			reset_req();
			if ((Time - TestTime) % 25 == 0) {
				if (!elev.GetReque()[f]) {
					cout << endl;
					cout << "*��" << Time << "tʱ��*    " << "  ���ݼ��, ��ʱ����λ�ã�*F" << f << "* " << "���Թ���!" << endl;
					cout << endl;
					close();//����
					elev.SetState(CLOSED);//״̬ת����CLOSED
					break;
				}
				else {
					cout << endl;
					cout << "*��" << Time << "tʱ��*    " << "  ���ݼ��, ��ʱ����λ�ã�*F" << f << "* " << endl;
					cout << endl;
				}
			}
			if (elev.GetReque()[f]) {
				come_in();
			}
		}
	}
}

void closed() {
	int f = elev.GetFloor();//��õ��ݵ�ǰ¥��
	if (elev.GetReque()[f]) elev.SetState(WAIT);//��⵽�ò�������״̬ת����WAIT
	else {//�ò������󣬲����ϡ���
		direct dir = elev.GetDire();//��õ��ݷ���״̬
		switch (dir) {
		case U: {
			bool up_req = false;//�ò��Ϸ��Ƿ�������
			for (int i = floors; i > f; i--) {
				up_req = elev.GetReque()[i];
				if (up_req) break;//�Ӷ��������ң���������������ټ������
			}
			if (up_req) {
				elev.SetState(UP);//�Ϸ���������״̬ΪUP
				WaitTime = 0;//���ݿյ�ʱ��һ�������󣨼��ȴ�δ��ʱ����Ҫ��WaitTime��λ
			}
			else {//�Ϸ�û���󣬿�ʼ����·�������һ��
				bool down_req = false;
				for (int i = 0; i < f; i++) {
					down_req = elev.GetReque()[i];
					if (down_req) break;
				}
				if (down_req) {//����·�������
					elev.SetState(DOWN);//���ݷ���
					elev.SetDire(D);//�����ķ�����D
					WaitTime = 0;
				}
				else {//����·�Ҳû���������תΪ�Ⱥ�״̬
					cout << "*��" << Time << "tʱ��*    " << "  ������F" << f << "�ȴ�" << endl;
					Time++;//ʱ������һ����λ
					WaitTime++;
					if (WaitTime == 300) {
						cout << endl;
						cout << "*��" << Time << "tʱ��*    " << "  �ȴ���ʱ!���ݷ��ر��ݲ�ȴ�!" << endl;
						getchar();
						exit(0);

					}
					reset_req();
					elev.SetState(CLOSED);
				}
			}
			break;
		}
		case D: {
			bool down_req = false;
			for (int i = 0; i < f; i++) {
				down_req = elev.GetReque()[i];
				if (down_req) break;
			}
			if (down_req) {
				elev.SetState(DOWN);//�·���������״̬ΪDOWN
				WaitTime = 0;
			}
			else {//�·�û���󣬿�ʼ����Ϸ�
				bool up_req = false;
				for (int i = floors; i > f; i--) {
					up_req = elev.GetReque()[i];
					if (up_req) break;
				}
				if (up_req) {//����Ϸ�������
					elev.SetState(UP);
					elev.SetDire(U);
					WaitTime = 0;
				}
				else {//�Ϸ�Ҳû������
					cout << "*��" << Time << "tʱ��*    " << "  ������F" << f << "�ȴ�" << endl;
					Time++;
					WaitTime++;
					if (WaitTime == 300) {//���ݵȴ�ʱ�䵽��300t�����ر��ݲ����
						if (f == 1) {//������ڱ��ݲ�
							cout << endl;
							cout << "*��" << Time << "tʱ��*    " << "  �ȴ���ʱ!�����ڱ��ݲ����!" << endl;
							cout << endl;
						}
						else {//�����ڱ��ݲ�
							cout << endl;
							cout << "*��" << Time << "tʱ��*    " << "  �ȴ���ʱ!���ݷ��ر��ݲ����!" << endl;
						}
						getchar();
						exit(0);
					}
					reset_req();
					elev.SetState(CLOSED);
				}
			}
			break;
		}
		}
	}
}