class AdjMatrixGraph{

private:
	int m_size;
	bool** m_matrix;

public:
	AdjMatrixGraph(int n_size);
	~AdjMatrixGraph(); 
	int size();
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool edgeExists(int u, int v);
	int numberOfEdges();

};