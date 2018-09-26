/*
 * File  : Graph.h
 * Author: Shashwat Shivam, Shashank Goel
 */

#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph(string file_name)
{
    int num_vertices;
    int num_edges;
    int num_agencies;

    ifstream infile;
    infile.open(file_name + ".graph");

    infile >> num_vertices >> num_edges >> num_agecies;

    V = num_vertices;
    E = num_edges;
    K = num_agencies;

    int u, v;

    for(int i = 0; i < E; i++)
    {
        infile >> u >> v;
        add_edge(u, v);
    }

    infile.close();
}

void Graph::add_edge(int u, int v)
{
    adj_list.push_back(make_pair(u, v));
}

void Graph::generate_cnf_clause()
{
    vector< string > cnf_formula;

    // every edge belongs to atleast one agency, for (i, j) in adj_list, C(ij, 1) || C(ij, 2) ...... || C(ij, k)
    
}

void Graph::write_clause(string path)
{
    ofstream myfile;
    myfile.open(path + ".satinput");
    myfile.close();
}

void Graph::read_sat_output(string path)
{
    ifstream infile;
    infile.open(path + ".satoutput");
    infile.close();
}

void Graph::generate_sub_graphs()
{
}

void Graph::write_sub_graphs(string path)
{
    ofstream myfile;
    myfile.open(path + ".subgraphs");
    myfile.close();
}
