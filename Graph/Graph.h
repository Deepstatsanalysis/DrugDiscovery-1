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

    // adjacency list of the graph
    vector< pair< int, int > > adj_list;
    // adjacency matrix of the graph
    bool adj_matrix[V][V];
    // list of constraint clauses of the graph
    vector< string > cnf_formulae;

public:
    /* Takes the file name & construct the graph out of it */
    Graph(string filename);

    /* Add an edge between u and v in the graph */
    void add_edge(int u, int v);

    /* assign a term name accoring to miniSAT conventions, type = 'g' or 'c' && i,j,k = appropriate labels */
    int get_sat_term_name(char type, int i, int j, int k);

    /* assign a term name accoring to simple, understandable conventions, sat_term = 5, -4 ( x5, -x4) */
    string get_graph_term_name(int sat_term);

    /* generate the contraint clauses for the graph */
    void generate_cnf_clause();

    /* write the clauses in a file for input by the miniSAT */
    void write_clause(string filename);

    /* read the output of the miniSAT solver */
    void read_sat_output(string filename);

    /* generate the sub_graphs from the output of the miniSAT solver */
    void generate_sub_graphs();

    /* write the sub_graphs to a file */
    void write_sub_graphs(string filename);
};

#endif /* GRAPH_H */
