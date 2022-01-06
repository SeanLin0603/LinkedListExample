#include "pch.h"
#include <stdio.h>

struct Node 
{ 
	int val;
	struct Node *next; 
};

Node getMiddle(Node nodeArray[])
{
	int nodeNum = 0;
	Node* node = nodeArray;
	while (node->next != nullptr)
	{
		nodeNum++;
		node = node->next;
	}
	nodeNum++;

	// init
	Node* returnNode;
	returnNode = nodeArray;
	int middle = 0;
	if (nodeNum % 2 == 0)
	{
		middle = nodeNum / 2 + 1;
	}
	else
	{
		middle = nodeNum / 2;
	}

	return nodeArray[middle];
}

int main()
{
	const int nodeNum = 6;
	Node nodeArray[nodeNum];
	
	for (int i = 0; i < nodeNum; i++)
	{
		nodeArray[i].val = i;

		if (i == nodeNum - 1)
		{
			nodeArray[i].next = nullptr;
		}
		else
		{
			nodeArray[i].next = &nodeArray[i] + 1;
		}
	}
	
	Node middleNode = getMiddle(nodeArray);

	printf("Middle node is %d.\n", middleNode.val);
}