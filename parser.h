#pragma once
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <stdlib.h>
#include "nodeList.h"
using namespace std;

class Parser {
public:
	static void parseEdge(vector<NodeList> &graph);
	static void parsePath(vector<char> &path);
private:
	static void split(string str, vector<string> &result, char c);
};