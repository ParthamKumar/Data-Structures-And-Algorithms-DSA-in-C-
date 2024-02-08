#include<iostream>
#include <climits>
using namespace std;

class findPath{
	int v,e;
	int *dist;
	
public:
	findPath(int ver, int edges){
		v = ver;
		e = edges;
		dist = new int[ver];
	}
	
	void solve(int arr[50][3],int scr){
		for(int i=0;i<v;++i){
			dist[i]= INT_MAX;
		}
		dist[scr]=0;
		
		for(int i=0;i<v-1;++i){
			for(int j=0;j<e;++j){
				int u = arr[j][0];
				int v = arr[j][1];
				int weight = arr[j][2];
				
				if (dist[u]!=INT_MAX && dist[u]+weight<dist[v]) {
                    dist[v] = dist[u]+weight;
                }
			}
		}
		
		for(int i=0;i<e;++i){
			int u = arr[i][0];
            int v = arr[i][1];
            int weight =arr[i][2];
            
            if (dist[u]!= INT_MAX && dist[u]+weight<dist[v]) {
                cout << -1;
                return;
            }
		}
		for (int i=0;i<v;++i) {
            if (dist[i] == INT_MAX) {
                cout << 10e8 << " ";
            } else {
                cout << dist[i] << " ";
            }
        }
	}
};

int main(){
	int v=3;
	int e =4;
	
	int graph[50][3]={{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
	int sor = 2;
	
	findPath sp(v,e);
	sp.solve(graph,sor);
}

