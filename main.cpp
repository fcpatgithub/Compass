#include <vector>
#include <string>
#include <iostream>
#include "nodeList.h"
#include "parser.h"
#include "bellmanford.h"
#include "runner.h"

using namespace std;

int main() {
	Runner* runner = (Runner*)new Runner();
	runner->run();

	// Pause
	int a;
	cin >> a;

	return 0;
}