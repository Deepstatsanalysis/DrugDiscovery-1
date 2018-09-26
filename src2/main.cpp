#include <iostream>
#include "../Graph/Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string path = argv[1];

    Graph *graph = new Graph(path, true);

    graph->read_sat_output(path);
    graph->generate_sub_graphs();
    graph->write_sub_graphs(path);

    return 0;
}
