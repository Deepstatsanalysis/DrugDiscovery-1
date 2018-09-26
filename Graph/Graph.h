/*
 * File  : Graph.h
 * Author: Shashwat Shivam, Shashank Goel
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph
{
    int V;
    int E;
    int K;

    vector< pair< int, int > > adj_list;
    vector< string > cnf_formulae;

public:
    Graph(string path);
    void add_edge(int u, int v);
    void generate_cnf_clause();
    void write_clause(string path);
    void read_sat_output(string path);
    void generate_sub_graphs();
    void write_sub_graphs(string path);
};

#endif /* GRAPH_H */
