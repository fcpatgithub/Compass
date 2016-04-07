#include "runner.h"

void Runner::run()
{
	// Parse input
	do {
		try {
			Parser::parseEdge(graph);
			Parser::parsePath(path);
			err = false;
		}
		catch (runtime_error err) {
			this->err = true;
			graph = vector<NodeList>(26);
			path.clear();
			cout << err.what() << endl;
			cout << "Please make sure input is valid and try again." << endl;
		}
	} while (err);
	
	// Find shortest path for node pairs and merge them
	for (int i = 0; i < path.size() - 1; ++i) {
		vector<char> r = vector<char>();
		vector<char> nodePair = vector<char>();
		int len = 0;

		nodePair.push_back(path[i]);
		nodePair.push_back(path[i + 1]);

		// Bellman-Ford algorithm
		BellmanFord::run(graph, nodePair, r, len);

		// Merge length
		length += len;
		
		// Path is found from destination to source, reverse it
		reverse(r.begin(), r.end());

		// merge path
		for (int j = 0; j < r.size(); ++j) {
			vector<char>::iterator fiter = find(result.begin(), result.end(), r[j]);
			if (fiter == result.end()) result.push_back(r[j]);
		}
	}

	// Output
	cout << "The shortest path from " << path[0] << " to ";
	for (int i = 1; i < path.size(); ++i) {
		cout << path[i];
		if (i != path.size() - 1) cout << " to ";
		else cout << " is: " << endl;
	}
	cout << "Length: " << length << endl;
	cout << "Path: ";

	for (vector<char>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter;
		if (iter != result.end() - 1) cout << "->";
		else cout << endl;
	}
}
