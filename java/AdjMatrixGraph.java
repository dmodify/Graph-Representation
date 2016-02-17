public class AdjMatrixGraph {

	/* static graph */
	boolean[][] m_matrix;
	int m_size = 0;

	public AdjMatrixGraph(int v_size) {
		m_size = v_size;
		m_matrix = new boolean[m_size][m_size];
	}

	public int size() {
		return m_size;
	}

	public void addEdge(int u, int v) {
		m_matrix[u][v] = true;
		m_matrix[v][u] = true;
	}

	public void removeEdge(int u, int v) {
		m_matrix[u][v] = false;
		m_matrix[v][u] = false;
	}

	public boolean edgeExists(int u, int v) {
		return m_matrix[u][v];
	}

	public int numberOfEdges() {
		int count = 0;
		for (int i=0; i<m_size; i++)
			for (int j=0; j<m_size; j++)
				if(m_matrix[i][j])
					count++;

		return count/2;
	}

}