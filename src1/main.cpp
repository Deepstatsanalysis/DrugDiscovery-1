#include <iostream>
#include "../commonSrc/Graph.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{

    string path = argv[1];

    Graph *graph = new Graph(path);

    graph->generateCNFClause();
    graph->writeClause(path);

    return 0;
}
