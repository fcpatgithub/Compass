#include "parser.h"
using namespace std;

void Parser::parseEdge(vector<NodeList>& graph)
{
	string line;
	getline(cin, line);
	vector<string> edges = vector<string>();
	split(line, edges, ' ');
	char nodeName = 'A';
	char nodeName2 = 'B';
	int distance = 0;
	for (int i = 0; i < edges.size(); ++i) {
		string edge = edges[i];
		nodeName = edge[0];
		nodeName2 = edge[1];
		if (nodeName - 'A' < 0 || nodeName - 'A' > 25) throw runtime_error("Fail to parse edge");
		distance = strtol(edge.substr(2, edge.length() - 2).c_str(), NULL, 10);
		if (graph[nodeName - 'A'].nodeName == ' ') graph[nodeName - 'A'] = NodeList(nodeName, 0);
		NodeList* node = (NodeList*)new NodeList(nodeName2, distance);
		graph[nodeName - 'A'].insert(node);
	}
	cin.clear();
	cin.sync();
}

void Parser::parsePath(vector<char>& path)
{
	string p;
	cin >> p;
	for (int i = 0; i < p.length(); ++i) if (isupper(p[i])) path.push_back(p[i]);
	if (path.empty()) throw runtime_error("Empty path!");
	cin.clear();
	cin.sync();
}

void Parser::split(string str, vector<string>& result, char c)
{
	int start = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == c) {
			result.push_back(str.substr(start, i - start));
			start = i + 1;
		}
		else if (i == str.length() - 1) {
			result.push_back(str.substr(start, i - start + 1));
		}
	}
}
