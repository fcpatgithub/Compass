#pragma once

struct NodeList {
	char nodeName;
	char preNode;
	int distanceToHead;
	int distanceToSource;
	struct NodeList* next;
	NodeList() { nodeName = ' '; preNode = ' '; distanceToHead = 0; distanceToSource = INT_MAX; next = NULL; }
	NodeList(char name, int distance) { nodeName = name; preNode = ' '; distanceToHead = distance; distanceToSource = INT_MAX;  next = NULL; }
	void insert(NodeList* n) { NodeList* head = this;  while (head->next) head = head->next; head->next = n; }
};