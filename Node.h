#pragma once
#ifndef NODE_
#define NODE_

template <class T>
class node {
public:
	T data;
	node <T>* next;
	node() { next = nullptr; }
	node(T item) {
		data = item;
		next = nullptr;
	}
};
#endif


