#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "Graph.h"

using namespace std;


typedef GraphArc<int, int> Arc;
typedef GraphNode<string, int> Node;

void visit( Node * pNode ) {
	cout << "Visiting: " << pNode->data() << endl;
}

void printPath(vector<Node *> vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Path: " << vec[i]->data() << endl;
	}
}

int main(int argc, char *argv[]) {
   
	Graph<string, int> graph(6);
	
	string c = "";
	int i = 0;
	ifstream myfile;
	myfile.open ("Q1Nodes.txt");

	while ( myfile >> c ) {
		graph.addNode(c, i++);
	}

	myfile.close();
	myfile.open("Q1Arcs.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graph.addArc(from, to, weight);
	}
    myfile.close();

	// Now traverse the graph.
	//graph.breadthFirst( graph.nodeArray()[0], visit );
	//graph.breadthFirstSearch(graph.nodeArray()[0], graph.nodeArray()[15], visit);
	vector<Node *> vec;
	graph.ucs(graph.nodeArray()[4], graph.nodeArray()[1], visit, vec);
	printPath(vec);

	system("PAUSE");
	
}
