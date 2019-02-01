#pragma once
#include "List.h"
template <class T>
class List;
template <class T>
class ListNode {
	friend class List<T>;
private:
	ListNode<T> *next;
	T data;
public:
	ListNode(ListNode<T> *ptrnext = 0) {
		next = ptrnext;
	}
	ListNode(const T& item, ListNode<T> *ptrNext = 0) {
		data = item;
		next = ptrNext;
	}
	~ListNode(void) {}
};
template <class T>
class List {
	ListNode<T> *head;
	int size;
	ListNode<T> *Index(int i);
public:
	List();
	~List();
	int Size() const;
	void Add(const T& item); //每一次都在链表的首位添加
	T Delete(int i);
	T GetData(int i);
};

template <class T>
List<T>::List() {
	head = new ListNode<T>();
	size = 0;
}
template <class T>
List<T>::~List() {
	ListNode<T> *p, *q;
	p = head;
	while (p != 0) {
		q = p;
		p = p->next;
		delete q;
	}
	size = 0;
	head = 0;
}
template <class T>
ListNode<T> *List<T>::Index(int i) {
	if (i<-1 || i>size - 1)
		exit(0);
	if (i == -1) return head;
	ListNode<T> *p = head->next;
	int j = 0;
	while (p != 0 && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
template <class T>
int List<T>::Size() const {
	return size;
}
template <class T>
void List<T>::Add(const T& item) {
	ListNode<T> *newNode = new ListNode<T>(item, 0);
	newNode->next = head->next;
	head->next = newNode;
	size++;
}
template <class T>
T List<T>::Delete(int i) {
	if (size == 0 || i<0 || i>size - 1)//无元素可删或参数越界
		exit(0);
	ListNode<T> *s, *p = Index(i - 1);
	s = p->next;
	p->next = p->next->next;
	T x = s->data;
	delete s;
	size--;
	return x;
}
template <class T>
T List<T>::GetData(int i) {
	if (i<0 || i>size - 1)//参数越界
		exit(0);
	ListNode<T> *p = Index(i);
	return p->data;
}


