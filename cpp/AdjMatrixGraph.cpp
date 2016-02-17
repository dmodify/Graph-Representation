#include "AdjMatrixGraph.h"

AdjMatrixGraph::AdjMatrixGraph(int n_size) {
	this->m_size = n_size;
	m_matrix = new bool*[m_size];
	for(int i=0; i<m_size; i++) {
		m_matrix[i] = new bool[m_size];
		for(int j=0; j<m_size; j++)
			m_matrix[i][j] = false;
	}
}

AdjMatrixGraph::~AdjMatrixGraph() {
	for (int i=0; i<m_size; i++)
		delete[] m_matrix[i];
	delete[] m_matrix;
}

void AdjMatrixGraph::addEdge(int u, int v) {
	m_matrix[u][v] = true;
	m_matrix[v][u] = true;
}

void AdjMatrixGraph::removeEdge(int u, int v) {
	m_matrix[u][v] = false;
	m_matrix[v][u] = false;
}

int AdjMatrixGraph::size() {
	return m_size;
}

bool AdjMatrixGraph::edgeExists(int u, int v) {
	return m_matrix[u][v];
}


