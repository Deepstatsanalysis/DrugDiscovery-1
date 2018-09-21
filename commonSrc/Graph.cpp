#include "Graph.h"
#include <fstream>

Graph::Graph(string path)
{
    int V, E, K;
    int v1, v2;
    ifstream infile;
    infile.open(path + ".graph");

    infile >> V >> E >> K;

    this->V = V;
    this->E = E;
    this->K = K;

    for (int i = 0; i < E; i++)
    {
        infile >> v1 >> v2;
        this->addEdge(v1, v2);
    }

    infile.close();
}

void Graph::addEdge(int v1, int v2)
{
}

void Graph::generateCNFClause()
{
}

void Graph::writeClause(string path)
{
    ofstream myfile;
    myfile.open(path + ".satinput");

    // Write to file
    // myfile << "Writing this to a file.\n";

    myfile.close();
}

void Graph::readSatoutput(string path)
{
    ifstream infile;
    infile.open(path + ".satoutput");

    // Read Output

    infile.close();
}

void Graph::generateSubGraphs()
{
}

void Graph::writeSubGraphs(string path)
{
    ofstream myfile;
    myfile.open(path + ".subgraphs");

    // Write to file
    // myfile << "Writing this to a file.\n";

    myfile.close();
}