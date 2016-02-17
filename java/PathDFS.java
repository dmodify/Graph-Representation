public class PathDFS{

	
	static boolean[] seen = new boolean[5];
	
	/* use adjacency matrix representation*/
	static AdjMatrixGraph G = new AdjMatrixGraph(5);

	/* use adjacency list representation*/
	//static AdjListGraph G = new AdjListGraph(5);

	public static void main(String[] args) {
		
		G.addEdge(0,3);
		G.addEdge(1,3);
		G.addEdge(3,4);
		G.addEdge(1,4);
		G.addEdge(2,4);

		System.out.println(pathExistsByDFS(0, 2));
	}

	public static boolean pathExistsByDFS(int u, int v) {
		//System.out.println(u+" : "+v);
		seen[u] = true;
		for(int j=0; j<G.size(); j++) {
			if((!seen[j]) && G.edgeExists(u, j)) {
				if(j==v)
					return true;
				if(pathExistsByDFS(j, v))
					return true;
			}
		}
		return false;
	}


}