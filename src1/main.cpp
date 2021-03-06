#include "../Graph/Graph.h"

int main(int argc, char const *argv[])
{
    string file_name = argv[1];

    Graph *graph = new Graph(file_name, false);

    graph->generate_cnf_clause();
    graph->write_clause(file_name);

    return 0;
}
