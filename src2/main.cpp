#include <iostream>
#include "../Graph/Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string file_name = argv[1];

    Graph *graph = new Graph(file_name, true);

    graph -> read_sat_output(file_name);
    graph -> write_sub_graphs(file_name);

    return 0;
}
