#include <iostream>
#include <fstream>
#include "../Graph/Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string filename = argv[1];

    Graph *graph = new Graph(filename, false);

    graph->generate_cnf_clause();
    graph->write_clause(filename);

    return 0;
}
