#ifndef NODE_H_
#define NODE_H_
#include "Person.h"

class Node
{
public:
	Person data;
	Node *next;
	void printNode();
};

#endif