#include<iostream>
#include "operate.h"
#include<windows.h>
using namespace std;
int main() {
	readFile();//读文件
	while (1) {
		states state = elev.GetState();//获得电梯当前状态
		switch (state) {     //不同的状态进行不同的操作
		case CLOSED: closed(); break;
		case UP: up(); break;
		case DOWN: down(); break;
		case WAIT: Wait(); break;
		}
	}
	system("pause");
	return 0;
}
/*
1 2 6 3
2 2 5 27
3 1 4 50
4 5 2 100
5 4 1 120
6 2 4 130
7 4 3 150
*/

/*
1 1 4 6
2 8 1 45
3 4 6 55
4 7 3 100
5 2 6 120
*/