#include<bits/stdc++.h>
#define NINF INT_MIN
using namespace std;
  
int n,m;

//ͼͨ���ڽӱ����������ڽӱ��е�ÿ��������������ӵĶ�������ݣ��Լ��ߵ�Ȩֵ��
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};
  
// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices��
  
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
  
    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
  
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
  
    // Finds longest distances from given source vertex
    void longestPath(int s);
};
  
Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
  
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u��s list
}
  
// ͨ���ݹ������������. ��ϸ�������ɲο���������ӡ�
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // ��ǵ�ǰ����Ϊ�ѷ���
    visited[v] = true;
  
    // �������ڽӵ�ִ�еݹ����
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
  
    // ��ĳ����û���ڽӵ�ʱ���ݹ���������õ����ջ�С�
    Stack.push(v);
}

// ���ݴ���Ķ��㣬���������������·��. longestPathʹ����
// topologicalSortUtil() ������ö����������
void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];
  
    // ������еĶ���Ϊδ����
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
  
    // ��ÿ���������topologicalSortUtil���������ͼ���������д��뵽Stack�С�
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
  
    //��ʼ�������ж���ľ���Ϊ������
    //��Դ��ľ���Ϊ0
    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
  
    // �������������еĵ�
    while (Stack.empty() == false)
    {
        //ȡ�����������еĵ�һ����
        int u = Stack.top();
        Stack.pop();
  
        // ���µ������ڽӵ�ľ���
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] < dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
    int temp = 0;
    // ��ӡ�·��
    for (int i = 0; i < V; i++){
    	if(temp<dist[i])
    		temp = dist[i];
	}
	printf("%d\n",temp);
}

// Driver program to test above functions
int main()
{
    int T;
    int x,y,z;
    int indeg[10010];
    scanf("%d",&T);
    while(T--)
    {
    	memset(indeg,0,sizeof(indeg));
    	scanf("%d%d",&n,&m);
    	Graph g(n+1);
		
		for(int i = 0; i < m ;i ++)
		{
			scanf("%d%d%d",&x,&y,&z);
			g.addEdge(x,y,z);
			indeg[y]++; 
		}	
		for(int i=1;i<=n;i++){
			if(!indeg[i]){
				g.addEdge(0,i,0);
			}
		}
//		g.addEdge(0,1,0);
//		g.addEdge(0,2,0);
		g.longestPath(0);
	}

  
    return 0;
}
