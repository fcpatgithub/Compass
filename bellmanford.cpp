#include "bellmanford.h"

// Set source node
void BellmanFord::init(vector<NodeList>& graph, const vector<char> &path)
{
	graph[path[0] - 'A'].distanceToSource = 0;
}

void BellmanFord::run(vector<NodeList> graph, const vector<char>& path, vector<char>& result, int& length)
{
	BellmanFord::init(graph, path);
	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i].nodeName == ' ') continue;
		NodeList* head = &(graph[i]);
		NodeList* ptr = head;
		while (ptr) {
			// Update costs
			if (ptr->distanceToSource > (ptr->distanceToHead + head->distanceToSource) && ptr->nodeName != path[0]) {
				ptr->distanceToSource = ptr->distanceToHead + head->distanceToSource;
				if(ptr->nodeName != path[0]) ptr->preNode = head->nodeName;
				if (graph[ptr->nodeName - 'A'].nodeName != ' ') {
					graph[ptr->nodeName - 'A'].distanceToSource = ptr->distanceToHead + head->distanceToSource;
					if (ptr->nodeName != path[0]) graph[ptr->nodeName - 'A'].preNode = head->nodeName;
				}
			}
			ptr = ptr->next;
		}
	}

	length = INT_MAX;
	for (int i = 0; i < graph.size(); ++i) {
		const NodeList* ptr = &(graph[i]);

		// Ignore empty node
		if (graph[i].nodeName == ' ') continue;

		while (ptr) {
			// Ignore longer path and invalid path
			if (ptr->distanceToSource > length || ptr->distanceToSource < 0) {
				ptr = ptr->next;
				continue;
			}

			// Find path from destination
			if (ptr->nodeName == *(path.end() - 1)) {
				result.clear();
				const NodeList* temp = ptr;

				// Get length of the shortest path
				length = temp->distanceToSource;
				char nodeName = temp->nodeName;

				// Bottom-up finding path
				while (temp->preNode != ' ') {
					result.push_back(nodeName);
					nodeName = graph[temp->preNode - 'A'].nodeName;
					temp = &graph[temp->preNode - 'A'];
				}
				result.push_back(nodeName);
			}
			ptr = ptr->next;
		}
	}
}


