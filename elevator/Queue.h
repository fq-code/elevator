#pragma once
#include "Queue.h"
template <class T> class Queue;  //�Ȱ���������ˣ���Ȼһ�ᶨ�������ÿһ���ʱ������
template <class T>  //���޷�ȷ���������͵�ʱ�򣬿�����T����
class QueueNode {
	friend class Queue<T>;//����LinQueue<T>Ϊ��Ԫ
private:
	QueueNode<T> *next;//ָ��
	T data;//����
public:
	QueueNode(const T& item, QueueNode<T> *ptrNext = 0)  //���캯��
		:data(item), next(ptrNext) {}
	~QueueNode() {};//��������
};
template <class T>
class Queue {
private:
	QueueNode<T> *front;//��ͷָ��
	QueueNode<T> *rear;//��βָ��
	int count;//������
public:
	Queue(void);
	~Queue(void);
	int Size();
	void Append(const T& item);//�����
	T Delete(void);//������
	T GetFront(void) const;//ȡ��ͷ����Ԫ��
	T GetData(int i) const;//ȡ���е�i��Ԫ�أ����ڽ������е�Ԫ�ذ��հ����ݵ�ʱ���С����������
	bool NotEmpty(void) const {  //�ǿշ�(�ǿ�Ϊ1)
		return count != 0;
	};
};

template <class T>
Queue<T>::Queue(void) {//���캯����ʼ��
	front = rear = 0;
	count = 0;
}
template <class T>
Queue<T>::~Queue(void) {//���������ó�ʼ״̬
	QueueNode<T> *p, *q;
	p = front;
	while (p != 0) {   //��ն���
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
void Queue<T>::Append(const T& item) {                   //ÿ�ν���βָ��ָ����ӵ�Ԫ��
	QueueNode<T> *newNode = new QueueNode<T>(item, 0);   //�����ǰ������Ԫ�ظ���Ϊ1����ͬʱ��front��
	if (rear != 0) rear->next = newNode;                 //rearָ����ӵ�Ԫ��
	rear = newNode;
	if (front == 0) front = newNode;
	count++;                                              //��Ӻ�Ҫ������Ԫ�ظ�����һ
}
template <class T>
T Queue<T>::Delete(void) {                 //���Ӳ�������ɾ������Ԫ�أ����Ƚ�Ҫɾ��Ԫ�ص���һ��Ԫ��
	if (count == 0) exit(0);               //��һ�£��ɼ�Ϊp��Ȼ��ɾ��front�󣬽�p��front����
	QueueNode<T> *p = front->next;
	T data = front->data;
	delete front;
	front = p;
	count--;                               //���Ӻ�Ҫ������Ԫ�ظ�����һ
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

