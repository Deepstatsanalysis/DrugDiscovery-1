/*
 * File  : Graph.h
 * Author: Shashwat Shivam, Shashank Goel
 */

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph(string file_name, bool output_mode)
{
    int num_vertices;
    int num_edges;
    int num_agencies;

    ifstream infile;
    infile.open(file_name + ".graph");

    infile >> num_vertices >> num_edges >> num_agencies;

    V = num_vertices;
    E = num_edges;
    K = num_agencies;

    if (!output_mode)
    {
        int u, v;

        int **temp_distance_matrix = new int *[V];
        for (int i = 0; i < V; i++)
            temp_distance_matrix[i] = new int[V];

        adj_matrix = temp_distance_matrix;

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj_matrix[i][j] = -1;

        for (int i = 0; i < E; i++)
        {
            infile >> u >> v;
            add_edge((u - 1), (v - 1), i);
        }
    }

    infile.close();
}

void Graph::add_edge(int u, int v, int edge_num)
{
    adj_list.push_back(make_pair(u, v));
    adj_matrix[u][v] = edge_num;
    adj_matrix[v][u] = edge_num;
}

int Graph::get_sat_term_name(char type, int i, int j, int k)
{
    switch (type)
    {
    case 'g':
    {
        return i * K + k + 1;
        break;
    }
    case 'c':
    {

        int edge_num = adj_matrix[i][j];
        int offset = V * K;
        return edge_num * K + k + offset + 1;
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
}

void Graph::generate_cnf_clause()
{
    vector<string> cnf_formula;
    string clause;

    // Every edge belongs to atleast one agency, for (i, j) in adj_list, C(ij, 1) || C(ij, 2) ...... || C(ij, k)
    for (int i = 0; i < E; i++)
    {
        clause = "";
        for (int j = 0; j < K; j++)
            clause += to_string(get_sat_term_name('c', adj_list[i].first, adj_list[i].second, j)) + " ";
        clause += "0";
        cnf_formulae.push_back(clause);
    }

    // If i and j are connected only then they can be in the same agency, if there edge (i, j) are in the grah then i and j are in the graph, if they i and j are not
    // connected then they can't be in the same agency
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < K; k++)
            {
                string term_gik = to_string(get_sat_term_name('g', i, 0, k));
                string term_gjk = to_string(get_sat_term_name('g', j, 0, k));

                if (adj_matrix[i][j] != -1)
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
                else if (i != j)
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
    for (int k1 = 0; k1 < K; k1++)
    {
        for (int k2 = k1 + 1; k2 < K; k2++)
        {
            clause = "";
            int help_variables_k1_k2[V];
            for (int i = 0; i < V; i++)
            {
                clause += to_string(help_variable_count) + " ";
                help_variables_k1_k2[i] = help_variable_count++;
            }
            clause += "0";
            cnf_formulae.push_back(clause);

            for (int i = 0; i < V; i++)
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
    variables = help_variable_count - 1;
}

void Graph::write_clause(string filename)
{
    ofstream myfile;
    myfile.open(filename + ".satinput");

    myfile << "p cnf " << variables << ' ' << cnf_formulae.size() << "\n";
    for (int i = 0; i < cnf_formulae.size(); i++)
        myfile << cnf_formulae[i] << "\n";

    myfile.close();
}

void Graph::read_sat_output(string filename)
{
    ifstream infile;
    infile.open(filename + ".satoutput");

    string result;
    int temp_result;

    infile >> result;
    if (result == "SAT")
    {
        for (int i = 0; i < K; i++)
        {
            vector<int> temp;
            result_sub_graphs.push_back(temp);
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < K; j++)
            {
                infile >> temp_result;
                if (temp_result > 0)
                    result_sub_graphs[j].push_back(i + 1);
            }
        }
    }

    infile.close();
}

void Graph::write_sub_graphs(string filename)
{
    ofstream myfile;
    myfile.open(filename + ".subgraphs");

    if (result_sub_graphs.size() == 0)
    {
        myfile << 0;
    }
    else
    {

        for (int i = 0; i < result_sub_graphs.size(); i++)
        {
            myfile << '#' << i + 1 << ' ' << result_sub_graphs[i].size() << "\n";
            for (int j = 0; j < result_sub_graphs[i].size(); j++)
                myfile << result_sub_graphs[i][j] << ' ';
            myfile << "\n";
            myfile << "\n";
        }
    }
    myfile.close();
}
