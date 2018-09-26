#include <iostream>
#include "../Graph/Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string filename = argv[1];

    Graph *graph = new Graph(filename);

    graph -> read_sat_output(filename);
    graph -> generate_sub_graphs();
    graph -> write_sub_graphs(filename);

    return 0;
}
