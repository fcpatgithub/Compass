#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "nodeList.h"

using namespace std;

class BellmanFord {
private:
	static void init(vector<NodeList>& graph, const vector<char>& path);
public:
	static void run(vector<NodeList> graph, const vector<char>& path, vector<char> &result, int &length);
};