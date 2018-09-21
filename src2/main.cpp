#include <iostream>
#include "../commonSrc/Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string path = argv[1];

    Graph *graph = new Graph(path);

    graph->readSatoutput(path);
    graph->generateSubGraphs();
    graph->writeSubGraphs(path);

    return 0;
}
