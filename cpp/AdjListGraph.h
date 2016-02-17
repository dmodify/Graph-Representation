#include <vector>

class AdjListGraph{

private:
	int m_size;
	std::vector<std::vector<int> >* m_list;

public:
	AdjListGraph(int n_size);
	~AdjListGraph(); 
	void addEdge(int u, int v);
	void removeEdge(int u, int v);

	int size();
	bool edgeExists(int u, int v);

};