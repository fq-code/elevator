#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"elevator.h"//电梯头文件
#include"person.h"//人头文件
#include"Queue.h"//等待队列
#include"List.h"//电梯内的人链表
#include<iostream>
#include<fstream>   //C++文件流
#include<iomanip>   
using namespace std;
int Time = 0;//系统的时间
int WaitTime = 0;//用于记录无人请求时间，超过300t,电梯返回本垒层
int TestTime = 0; //电梯有人进出时进行检测的计时器
int count = 0; //帮助电梯有人进出时进行检测的变量
elevator elev;//电梯(默认初始状态在本垒层等待)     
List<person> elev_list;//电梯内的人的存储链表
Queue<person> f_queue[floors];//

void readFile() {//读文件，以初始化等待队列
	ifstream infile;
	infile.open("d:\\电梯文件.txt");
	char c;
	while (1) {
		person per;
		int a, b, c, d;//分别为人的编号、来自楼层、去往楼层、来到时间
		infile >> a >> b >> c >> d;
		per.init(a, b, c, d);  //初始化乘客的信息
		int from = per.GetFr();//得到该人的来自楼层
		f_queue[from].Append(per);//将其填入相应楼层的等待队列
		if (infile.eof() != 0) break;//文件读完，退出
	}
	infile.close();
}
void reset_req() {   //重置电梯的请求数组
	for (int i = 0; i < floors; i++) {    //检测各等待队列是否有请求
										  //队列非空且队头元素来到时间等于当前时间，则该层发出请求
		if (f_queue[i].NotEmpty()) {      //非空才有可能有请求
			int size = f_queue[i].Size();
			for (int j = 0; j < size; j++) {
				if (f_queue[i].GetData(j).Getp_time() == Time) {
					cout << endl;
					cout << "*在" << Time << "t时刻*    " << f_queue[i].GetData(j).GetNum() << "号乘客按下电梯按钮，发出请求 " << "*F" << i << " ---> " << "F" << f_queue[i].GetData(j).GetTo() << "*" << endl;
					cout << endl;
					elev.SetReque(i, true);//将电梯的相应楼层的请求数组置true(模拟每来一个人，按一下电梯)
				}
			}
		}
	}
	for (int i = 0; i < elev_list.Size(); i++) {//检测电梯内人链表的去往楼层来刷新服务请求
		int to = elev_list.GetData(i).GetTo();
		elev.SetReque(to, true);//将电梯的相应楼层的请求数组置true
	}
}

void up() {//电梯上升一层楼(要用51t时间)
	int f = elev.GetFloor();//获取电梯当前楼层
//加速上升
	cout << endl;
	/*	for (int i = 1; i <= 15;++i) {
			if (i == 15) cout << "*在" << Time << "t时刻*    " << "电梯正在加速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl << endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在加速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
	int p1 = Time, q1 = 0;
	for (int i = 1; i <= 15; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q1 = Time;
	cout << "*在" << p1 << "t时刻到 " << q1 << "时刻*    " << "电梯正在加速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;
	//匀速上升
	cout << endl;
	/*	for (int i = 1; i <= 22;++i) {
			if(i==22) cout << "*在" << Time << "t时刻*    " << "电梯正在匀速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl<<endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在匀速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
	int p2 = Time, q2 = 0;
	for (int i = 1; i <= 22; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q2 = Time;
	cout << "*在" << p2 << "t时刻到 " << q2 << "时刻*    " << "电梯正在匀速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;

	//减速上升
	cout << endl;
	/*	for (int i = 1; i <= 14;++i) {
			if(i==14) cout << "*在" << Time << "t时刻*    " << "电梯正在减速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl<<endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在减速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
	int p3 = Time, q3 = 0;
	for (int i = 1; i <= 14; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q3 = Time;
	cout << "*在" << p3 << "t时刻到 " << q3 << "时刻*    " << "电梯正在减速上升，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;
	//状态变化
	elev.SetFloor(f + 1);//楼层数加一
	reset_req();
	elev.SetState(WAIT);//上完一层，电梯运行状态转换为WAIT
	elev.SetDire(U);//方向状态置U
}

void down() {//电梯电梯下降一层楼
	int f = elev.GetFloor();
	//加速下降
	cout << endl;
	int p1 = Time, q1 = 0;
	for (int i = 1; i <= 15; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q1 = Time;
	cout << "*在" << p1 << "t时刻到 " << q1 << "时刻*    " << "电梯正在加速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;
	/*	for (int i = 1; i <= 15; ++i) {
			if(i==15) cout << "*在" << Time << "t时刻*    " << "电梯正在加速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl<<endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在加速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
		//匀速下降
	cout << endl;
	/*	for (int i = 1; i <= 23; ++i) {
			if(i==23) cout << "*在" << Time << "t时刻*    " << "电梯正在匀速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl<<endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在匀速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
	int p2 = Time, q2 = 0;
	for (int i = 1; i <= 23; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q2 = Time;
	cout << "*在" << p2 << "t时刻到 " << q2 << "时刻*    " << "电梯正在匀速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;
	//减速下降
	cout << endl;
	/*	for (int i = 1; i <= 23; ++i) {
			if(i==23) cout << "*在" << Time << "t时刻*    " << "电梯正在减速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl<<endl;
			else cout << "*在" << Time << "t时刻*    " << "电梯正在减速下降，此时电梯位置: *F" << f << "到F" << f - 1 << "之间*    电梯内乘客数为："<< elev.Getper() << endl;
			Time++;//时间一增加
			reset_req();//就要刷新电梯的请求数组
		}*/
	int p3 = Time, q3 = 0;
	for (int i = 1; i <= 23; ++i) {
		Time++;//时间一增加
		reset_req();//就要刷新电梯的请求数组
	}
	q3 = Time;
	cout << "*在" << p3 << "t时刻到 " << q3 << "时刻*    " << "电梯正在减速下降，此时电梯位置: *F" << f << "到F" << f + 1 << "之间*    电梯内乘客数为：" << elev.Getper() << endl;
	//状态变化
	elev.SetFloor(f - 1);//楼层数加一
	reset_req();
	elev.SetState(WAIT);//上完一层，电梯运行状态转换为WAIT
	elev.SetDire(U);//方向状态置U
}
void open() {               //电梯开门
	int f = elev.GetFloor();//获得当前楼层
/*	for (int i = 1; i <= 20; ++i) {
		cout << "在" << Time << "t时刻    " << "电梯正在开门，此时电梯位置: *F" << f << "*" << endl;
		Time++;
		reset_req();
	}*/
	int p = Time, q = 0;
	for (int i = 0; i < 20; ++i) {
		Time++;
		reset_req;
	}
	q = Time;
	cout << "在" << p << "t时刻到 " << q << "t时刻*    " << "电梯正在开门，此时电梯位置: *F" << f << "*" << endl;
}

void close() {              //电梯关门(与开门相反)
	int f = elev.GetFloor();//获得当前楼层
/*	for (int i = 1; i <= 20; ++i) {
		cout << "在" << Time << "t时刻    " << "电梯正在关门，此时电梯位置: *F" << f << "*" << endl;
		Time++;
		reset_req();
	}*/
	int p = Time, q = 0;
	for (int i = 0; i < 20; ++i) {
		Time++;
		reset_req;
	}
	q = Time;
	cout << "在" << p << "t时刻到 " << q << "t时刻*    " << "电梯正在关门，此时电梯位置: *F" << f << "*" << endl;
}

void come_in() {        //进电梯
	int f = elev.GetFloor();
	int count = 0;
	if (f_queue[f].NotEmpty()) {//该楼等待队列非空，才可能有人上电梯(注意:有可能连续有人上电梯)
		while (1) {
			if (f_queue[f].NotEmpty()) {
				int t = f_queue[f].GetFront().Getp_time();//取队头的到达时间
				if (t > Time) break;   //队头到达时间大于系统当前时间，则无人上电梯，退出
			}
			else {    //等待队列已空，则无人上电梯，退出
				break;
			}
			bool is_in = false;//记录是否有人进电梯
			int t = f_queue[f].GetFront().Getp_time();//取队头的到达时间
			if (Time - t > MAX_WAIT_TIME) {         //等待时间大于最大忍受时间，则该人离开
				cout << "*在" << Time << "t时刻*    " << f_queue[f].GetFront().GetNum() << "号乘客由于超过最大等待时间已离开" << endl;
				f_queue[f].Delete();//从队列中删除已离开的人
			}
			else {      //等待时间小于等于最大忍受时间，则该人离开队头进入电梯
				if (elev.Getper() == maxn) {//超载
					cout << endl;
					cout << "*在" << Time << "t时刻*    " << "对不起!由于电梯人数已达上限，请稍等! 此时电梯位置：*F" << f << "*" << endl;
					cout << endl;
					break;
				}
				else {     //没超载，上!
					cout << endl;
					cout << "*在" << Time << "t时刻*    " << f_queue[f].GetFront().GetNum() << "号乘客进电梯 *在F" << f << "*" << endl;
					cout << endl;
					count++;
					if (count == 1) TestTime = Time;//队头人进，启动检测装置
					elev_list.Add(f_queue[f].GetFront());//添加到电梯内人链表
					elev.Setper(elev.Getper() + 1);
					f_queue[f].Delete();//从队列中删除已进入电梯的人
					is_in = true;
				}
			}
			if (is_in) {//有人上电梯，时间流逝25t
				for (int i = 0; i < 25; i++) {//进电梯每人用25t时间
					Time++;
					reset_req();
					if ((Time - TestTime) % 25 == 0) {
						cout << endl;
						cout << "*在" << Time << "t时刻*    " << "  电梯检测，此时电梯位置：*F" << f << "* " << "不能关门!" << endl;
						cout << endl;
					}
					cout << "*在" << Time << "t时刻*    " << "  乘客正在进电梯, 此时电梯位置：*F" << f << "*" << endl;
				}
			}
		}
	}
}

void Wait() {
	int f = elev.GetFloor();//获得电梯当前楼层
	if (!elev.GetReque()[f]) elev.SetState(CLOSED);//若该层无请求，则不理会该层
	else {//该层有请求,便开门服务(先下后上)
		open();//电梯开门;
			   /*下电梯*/
		bool is_out = false;//记录是否有人下电梯
		cout << endl;
		for (int i = 0; i < elev_list.Size(); i++) {//下电梯
			if (elev_list.GetData(i).GetTo() == f) {//该人去往楼层等于该楼层，则该人下电梯
				cout << "*在" << Time << "t时刻*    " << elev_list.GetData(i).GetNum() << "号乘客出电梯, 此时电梯位置：*F" << f << "*" << endl;
				elev_list.Delete(i);//在电梯内人链表中删除下电梯的人
				elev.Setper(elev.Getper() - 1);
				i--;//由于链表删除元素，i值应减一，才不会导致链表中有人未检测到
				is_out = true;
			}
		}
		if (is_out) {//下电梯统一用25t时间
			cout << endl;
			for (int i = 0; i < 25; i++) {
				Time++;
				reset_req();
				cout << "*在" << Time << "t时刻*    " << "  乘客出电梯, 此时电梯位置：*F" << f << "*" << endl;
			}
		}
		come_in();//上电梯
		elev.SetReque(f, false);//该楼层请求取消
		while (1) {
			Time++;
			reset_req();
			if ((Time - TestTime) % 25 == 0) {
				if (!elev.GetReque()[f]) {
					cout << endl;
					cout << "*在" << Time << "t时刻*    " << "  电梯检测, 此时电梯位置：*F" << f << "* " << "可以关门!" << endl;
					cout << endl;
					close();//关门
					elev.SetState(CLOSED);//状态转换至CLOSED
					break;
				}
				else {
					cout << endl;
					cout << "*在" << Time << "t时刻*    " << "  电梯检测, 此时电梯位置：*F" << f << "* " << endl;
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
	int f = elev.GetFloor();//获得电梯当前楼层
	if (elev.GetReque()[f]) elev.SetState(WAIT);//检测到该层有请求，状态转换至WAIT
	else {//该层无请求，测其上、方
		direct dir = elev.GetDire();//获得电梯方向状态
		switch (dir) {
		case U: {
			bool up_req = false;//该层上方是否有请求
			for (int i = floors; i > f; i--) {
				up_req = elev.GetReque()[i];
				if (up_req) break;//从顶层往下找，如果发现请求，则不再继续检测
			}
			if (up_req) {
				elev.SetState(UP);//上方有请求，置状态为UP
				WaitTime = 0;//电梯空等时，一旦有请求（即等待未超时），要将WaitTime复位
			}
			else {//上方没请求，开始检测下方，方法一样
				bool down_req = false;
				for (int i = 0; i < f; i++) {
					down_req = elev.GetReque()[i];
					if (down_req) break;
				}
				if (down_req) {//如果下方有请求
					elev.SetState(DOWN);//电梯反向
					elev.SetDire(D);//反向后的方向置D
					WaitTime = 0;
				}
				else {//如果下方也没请求，则电梯转为等候状态
					cout << "*在" << Time << "t时刻*    " << "  电梯在F" << f << "等待" << endl;
					Time++;//时间流逝一个单位
					WaitTime++;
					if (WaitTime == 300) {
						cout << endl;
						cout << "*在" << Time << "t时刻*    " << "  等待超时!电梯返回本垒层等待!" << endl;
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
				elev.SetState(DOWN);//下方有请求，置状态为DOWN
				WaitTime = 0;
			}
			else {//下方没请求，开始检测上方
				bool up_req = false;
				for (int i = floors; i > f; i--) {
					up_req = elev.GetReque()[i];
					if (up_req) break;
				}
				if (up_req) {//如果上方有请求
					elev.SetState(UP);
					elev.SetDire(U);
					WaitTime = 0;
				}
				else {//上方也没有请求
					cout << "*在" << Time << "t时刻*    " << "  电梯在F" << f << "等待" << endl;
					Time++;
					WaitTime++;
					if (WaitTime == 300) {//电梯等待时间到了300t，驳回本垒层候命
						if (f == 1) {//本身就在本垒层
							cout << endl;
							cout << "*在" << Time << "t时刻*    " << "  等待超时!电梯在本垒层候命!" << endl;
							cout << endl;
						}
						else {//本身不在本垒层
							cout << endl;
							cout << "*在" << Time << "t时刻*    " << "  等待超时!电梯返回本垒层候命!" << endl;
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