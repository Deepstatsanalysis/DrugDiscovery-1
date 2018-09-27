/*
 * File  : Graph.h
 * Author: Shashwat Shivam, Shashank Goel
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    // number of vertices in the graph
    int V;
    // number of edges in the graph
    int E;
    // number of agencies
    int K;

    int variables;
    // adjacency list of the graph
    vector< pair<int, int> > adj_list;
    // adjacency matrix of the graph
    int **adj_matrix;

    // list of constraint clauses of the graph
    vector<string> cnf_formulae;

    // resulting sub-graphs
    vector<vector<int>> result_sub_graphs;

  public:
    /* Takes the file name & construct the graph out of it. In outputMode only read V,E,K */
    Graph(string file_name, bool output_mode);

    /* Add an edge between u and v in the graph */
    void add_edge(int u, int v, int edge_num);

    /* assign a term name accoring to miniSAT conventions, type = 'g' or 'c' && i,j,k = appropriate labels */
    int get_sat_term_name(char type, int i, int j, int k);

    /* generate the contraint clauses for the graph */
    void generate_cnf_clause();

    /* write the clauses in a file for input by the miniSAT */
    void write_clause(string file_name);

    /* read the output of the miniSAT solver, generate the sub_graphs from the output of the miniSAT solver */
    void read_sat_output(string file_name);

    /* write the sub_graphs to a file */
    void write_sub_graphs(string file_name);
};

#endif /* GRAPH_H */
