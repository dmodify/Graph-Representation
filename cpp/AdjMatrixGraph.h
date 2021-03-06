class AdjMatrixGraph{

private:
	int m_size;
	bool** m_matrix;

public:
	AdjMatrixGraph(int n_size);
	~AdjMatrixGraph(); 
	void addEdge(int u, int v);
	void removeEdge(int u, int v);

	int size();
	bool edgeExists(int u, int v);

};