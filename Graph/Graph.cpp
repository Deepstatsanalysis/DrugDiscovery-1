/*
 * File  : Graph.h
 * Author: Shashwat Shivam, Shashank Goel
 */

#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph(string filename)
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

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            adj_matrix[i][j] = false;

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
    adj_matrix[u][v] = true;
    adj_matrix[v][u] = true;
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

    // Every edge belongs to atleast one agency, for (i, j) in adj_list, C(ij, 1) || C(ij, 2) ...... || C(ij, k)
    for(int i = 0; i < E; i++)
    {
        clause = "";
        for(int j = 0; j < K; j++)
            clause += to_string(get_sat_term_name('c', adj_list[i].first, adj_list[i].second, j)) + " ";
        clause += "0";
        cnf_formulae.push_back(clause);
    }

    // If i and j are connected only then they can be in the same agency, if there edge (i, j) are in the grah then i and j are in the graph, if they i and j are not
    // connected then they can't be in the same agency
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            for(int k = 0; k < K; k++)
            {
                string term_gik = to_string(get_sat_term_name('g', i, 0, k));
                string term_gjk = to_string(get_sat_term_name('g', j, 0, k));

                if(adj_matrix[i][j])
                {
                    string term_cijk = to_string(get_sat_term_name('c', i, j, k));

                    clause = "";
                    clause += "-" + term_gik + " ";
                    clause += "-" + term_gjk + " ";
                    clause += term_cijk + " ";
                    clause += "0";
                    cnf_formulae.push_back(clause);

                    clause = "";
                    clause += "-" + term_cijk + " ";
                    clause += term_gik + " ";
                    clause += "0";
                    cnf_formulae.push_back(clause);

                    clause = "";
                    clause += "-" + term_cijk + " ";
                    clause += term_gjk + " ";
                    clause += "0";
                    cnf_formulae.push_back(clause);
                }
                else
                {
                    clause = "";
                    clause += "-" + term_gik + " ";
                    clause += "-" + term_gjk + " ";
                    clause += "0";
                    cnf_formulae.push_back(clause);
                }
            }
        }
    }

    // no agency is subsidary of any other agency, ~(gi1k1 -> gi1k2 && gi2k1 -> gi2k2 && ........ gink1 -> gink2)
    int help_variable_count = V * K + E * K + 1;
    for(int k1 = 0; k1 < K; k1++)
    {
        for(k2 = k1 + 1; k2 < K; k2++)
        {
            clause = "";
            int help_variables_k1_k2[V];
            for(int i = 0; i < V; i++)
            {
                clause += to_string(help_variable_count) + " ";
                help_variables_k1_k2[i] = help_variable_count++;
            }
            clause += "0";
            cnf_formulae.push_back(clause);

            for(int i = 0; i < V; i++)
            {
                clause = "";
                clause += "-" + to_string(help_variables_k1_k2[i]) + " ";
                clause += to_string(get_sat_term_name('g', i, 0, k1)) + " ";
                clause += "0";
                cnf_formulae.push_back(clause);

                clause = "";
                clause += "-" + to_string(help_variables_k1_k2[i]) + " ";
                clause += to_string(get_sat_term_name('g', i, 0, k2)) + " ";
                clause += "0";
                cnf_formulae.push_back(clause);
            }
        }
    }

}

void Graph::write_clause(string filename)
{
    ofstream myfile;
    myfile.open(path + ".satinput");
    myfile.close();
}

void Graph::read_sat_output(string filename)
{
    ifstream infile;
    infile.open(path + ".satoutput");
    infile.close();
}

void Graph::generate_sub_graphs()
{

}

void Graph::write_sub_graphs(string filename)
{
    ofstream myfile;
    myfile.open(path + ".subgraphs");
    myfile.close();
}
