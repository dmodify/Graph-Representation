import java.util.*;

public class AdjListGraph implements Iterable<Integer> {
	
	/* dynamic graph */
	Map<Integer, Set<Integer>> mGraph = new HashMap<Integer, Set<Integer>>();

	public AdjListGraph(int n_size) {
		for (int i=0; i<n_size; i++) {
			addNode(i);	
		}
	}

	public int size() {
		return mGraph.size();
    }

    public boolean isEmpty() {
        return mGraph.isEmpty();
    }

	public boolean addNode(Integer node) {
		if (mGraph.containsKey(node))
           	return false;
        mGraph.put(node, new HashSet<Integer>());
        return true;
    }

	public boolean nodeExists(Integer node) {
        return mGraph.containsKey(node);
    }

	public void addEdge(Integer one, Integer two) {
		if (!mGraph.containsKey(one) || !mGraph.containsKey(two))
        			throw new NoSuchElementException("Both nodes must be in the graph.");
		mGraph.get(one).add(two);
		mGraph.get(two).add(one);
    }

	public void removeEdge(Integer one, Integer two) {
		if (!mGraph.containsKey(one) || !mGraph.containsKey(two))
			throw new NoSuchElementException("Both nodes must be in the graph.");	
		mGraph.get(one).remove(two);
		mGraph.get(two).remove(one);
    }

    public boolean edgeExists(Integer one, Integer two) {
		if (!mGraph.containsKey(one) || !mGraph.containsKey(two))
			throw new NoSuchElementException("Both nodes must be in the graph.");     
		return mGraph.get(one).contains(two);
	}

	public Set<Integer> edgesFrom(Integer node) {
		Set<Integer> arcs = mGraph.get(node);
		if (arcs == null)
            		throw new NoSuchElementException("Source node does not exist.");
		return Collections.unmodifiableSet(arcs);
	}

	public boolean containsNode(Integer node) {
        return mGraph.containsKey(node);
    }

    public Iterator<Integer> iterator() {
       	return mGraph.keySet().iterator();
    }
        	
    public int numberOfEdges() {
		int count = 0;
		for (Integer node : this)
			count = count + mGraph.get(node).size();
		return count/2;
	}

}