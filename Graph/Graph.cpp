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

int Graph::get_sat_term_name(char type, int i, int j, int k)
{

}

string Graph::get_graph_term_name(int sat_term)
{

}

void Graph::generate_cnf_clause()
{
    vector< string > cnf_formula;
    string clause;

    // every edge belongs to atleast one agency, for (i, j) in adj_list, C(ij, 1) || C(ij, 2) ...... || C(ij, k)
    for(int i = 0; i < E; i++)
    {
        clause = "";
        for(int j = 0; j < K; j++)
            clause += to_string(get_sat_term_name('c', adj_list[i].first, adj_list[i].second, j)) + " ";
        clause += "0";
        cnf_formula.push_back(clause);
    }

    // every

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
