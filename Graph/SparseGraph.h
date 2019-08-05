#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph {
private:
	int n, m;
	bool directed;
	vector<vector<int>> g;

public:
	SparseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for(int i =0; i < n; i++) {
			g.push_back( vector<int>() );
		}
	}

	~SparseGraph() {}

	int Vertex() { return n; }
	int Edge() { return m; }

	void addEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		g[v].push_back(w);
		if(v != w && !directed)
			g[w].push_back(v);
		m++;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		for(int i = 0; (unsigned) i < g[v].size(); i++) 
			if(g[v][i] == w)
				return true;
		return false;
	}

	void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; (unsigned) j < g[i].size() ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }


	class adjIterator {
	private:
		SparseGraph &G;
		int v;
		int index;
	public:
		adjIterator(SparseGraph &graph, int v) : G(graph) {
			this->v = v;
			this->index = 0;
		}

		int begin() {
			if(G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		int next() {
			index++;
			if((unsigned) index < G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		int end() {
			return (unsigned) index >= G.g[v].size();
		}
	};
};


#endif  //GRAPH_SPARSEGRAPH_H