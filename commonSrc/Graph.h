/* 
 * File:   Graph.h
 * Author: Shashwat Shivam
 *
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

public:
  Graph(string path);
  void addEdge(int v1, int v2);
  void generateCNFClause();
  void writeClause(string path);
  void readSatoutput(string path);
  void generateSubGraphs();
  void writeSubGraphs(string path);
};

#endif /* GRAPH_H */