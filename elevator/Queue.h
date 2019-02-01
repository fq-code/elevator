#pragma once
#include "Queue.h"
template <class T> class Queue;  //先把这个定义了，不然一会定义队列中每一块的时候会出错
template <class T>  //当无法确定数据类型的时候，可以用T代替
class QueueNode {
	friend class Queue<T>;//定义LinQueue<T>为友元
private:
	QueueNode<T> *next;//指针
	T data;//数据
public:
	QueueNode(const T& item, QueueNode<T> *ptrNext = 0)  //构造函数
		:data(item), next(ptrNext) {}
	~QueueNode() {};//析构函数
};
template <class T>
class Queue {
private:
	QueueNode<T> *front;//队头指针
	QueueNode<T> *rear;//队尾指针
	int count;//计数器
public:
	Queue(void);
	~Queue(void);
	int Size();
	void Append(const T& item);//入队列
	T Delete(void);//出队列
	T GetFront(void) const;//取队头数据元素
	T GetData(int i) const;//取队列第i个元素，用于将队列中的元素按照按电梯的时间从小到大来排序
	bool NotEmpty(void) const {  //非空否(非空为1)
		return count != 0;
	};
};

template <class T>
Queue<T>::Queue(void) {//构造函数初始化
	front = rear = 0;
	count = 0;
}
template <class T>
Queue<T>::~Queue(void) {//析构函数置初始状态
	QueueNode<T> *p, *q;
	p = front;
	while (p != 0) {   //清空队列
		q = p;
		p = p->next;
		delete q;
	}
	count = 0;
	front = rear = 0;
}
template <class T>
int Queue<T>::Size() {
	return count;
}
template <class T>
void Queue<T>::Append(const T& item) {                   //每次将队尾指针指向入队的元素
	QueueNode<T> *newNode = new QueueNode<T>(item, 0);   //如果当前队列中元素个数为1，就同时将front和
	if (rear != 0) rear->next = newNode;                 //rear指向入队的元素
	rear = newNode;
	if (front == 0) front = newNode;
	count++;                                              //入队后，要将队列元素个数加一
}
template <class T>
T Queue<T>::Delete(void) {                 //出队操作就是删除队首元素，首先将要删的元素的下一个元素
	if (count == 0) exit(0);               //存一下，可记为p，然后删除front后，将p给front即可
	QueueNode<T> *p = front->next;
	T data = front->data;
	delete front;
	front = p;
	count--;                               //出队后，要将队列元素个数减一
	return data;
}
template <class T>
T Queue<T>::GetFront(void) const {
	if (count == 0) exit(0);
	return front->data;
}
template <class T>
T Queue<T>::GetData(int i) const {
	if (i<0 || i>count - 1) exit(0);
	QueueNode<T> *p = front;
	int j = 0;
	while (p != 0 && j < i) {
		p = p->next;
		j++;
	}
	return p->data;
}

