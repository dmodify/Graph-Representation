#include <algorithm> 
#include "AdjListGraph.h"


AdjListGraph::AdjListGraph(int n_size) {
	this->m_size = n_size;
	m_list = new std::vector<std::vector<int> >();
	for(int i=0; i<m_size; i++) {
		(*m_list).push_back(std::vector<int>());
	}
}

AdjListGraph::~AdjListGraph() {
	while (!(*m_list).empty())
		(*m_list).pop_back();
	delete m_list;
}

void AdjListGraph::addEdge(int u, int v) {
	(*m_list)[u].push_back(v);
	(*m_list)[v].push_back(u);
}

void AdjListGraph::removeEdge(int u, int v) {
	std::vector<int>::iterator it_u = std::find((*m_list)[u].begin(), (*m_list)[u].end(), v);
	(*m_list)[u].erase(it_u);
	std::vector<int>::iterator it_v = std::find((*m_list)[v].begin(), (*m_list)[v].end(), u);
	(*m_list)[v].erase(it_v);
}

int AdjListGraph::size() {
	return m_size;
}

bool AdjListGraph::edgeExists(int u, int v) {
	std::vector<int>::iterator it = std::find((*m_list)[u].begin(), (*m_list)[u].end(), v);
	if(it != (*m_list)[u].end())
		return true;
	else
		return false;
}

