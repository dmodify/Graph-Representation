#include <string>
#include <iostream> 
#include "AdjListGraph.h"

bool pathExistsByDFS(AdjListGraph& G, int u, int v, bool* seen) {	
	seen[u] = true;
	for(int j=0; j<G.size(); j++) {
		if((!seen[j]) && G.edgeExists(u, j)) {
			if(j==v)
				return true;
			if(pathExistsByDFS(G, j, v, seen))
				return true;
		}
	}
	return false;
}

int main() {

	AdjListGraph* G = new AdjListGraph(5);
	(*G).addEdge(0,3);
	(*G).addEdge(1,3);
	(*G).addEdge(3,4);
	(*G).addEdge(1,4);
	(*G).addEdge(2,4);
	(*G).removeEdge(2,4);

	std::cout << ((*G).edgeExists(2, 4) ? "true" : "false") << std::endl;

	// bool seen[5] = {false};
	// std::cout << (pathExistsByDFS(*G, 1, 2, seen) ? "true" : "false") << std::endl;
}