#pragma once
template<typename T>
struct LinkListNode
{
	LinkListNode(){}
	LinkListNode(const T& val, LinkListNode<T>* ptl = nullptr) :_data(val), next(ptl) {}

	T _data;
	LinkListNode<T>* next;
};