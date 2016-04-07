#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "nodeList.h"
#include "bellmanford.h"
#include "parser.h"

class Runner {
private:
	vector<NodeList> graph;
	vector<char> path;
	vector<char> result;
	int length;
	bool err;
public:
	Runner() { graph = vector<NodeList>(26); path = vector<char>(); result = vector<char>(); length = 0; err = false; }
	vector<NodeList> getGraph() { return graph; }
	vector<char> getPath() { return path; }
	vector<char> getResult() { return result; }
	int getLength() { return length; }
	bool getErrState() { return err; }
	void run();
};