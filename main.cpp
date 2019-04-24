#include<iostream>
#include <list>
using namespace std;
int *v, *adj, adj_count=0;

class Graph {

private:
      int counts;
public:
      int** matrix;
      Graph(int counts)
       {
          this->counts = counts;
          matrix = new int*[counts];
          for (int i = 0; i < counts; i++)
            {
                matrix[i] = new int[counts];
                for (int j = 0; j < counts; j++)
                    matrix[i][j] = 0;
            }
      }
      void addEdge(int i, int j)
      {
            if (i >= 0 && i < counts && j > 0 && j < counts) {
                  matrix[i][j] = 1;
                  matrix[j][i] = 1;
            }
      }
      void removeEdge(int i, int j)
      {
            if (i >= 0 && i < counts && j > 0 && j < counts) {
                  matrix[i][j] = 0;
                  matrix[j][i] = 0;
            }

      }
      bool isEdge(int i, int j) {
            if (i >= 0 && i < counts && j > 0 && j < counts)
                  return matrix[i][j];
            else
                  return false;
      }
      int getCounts()
      {
          return counts;
      }
};

void DFS(int i, Graph g)
{
    int counts;
    counts = g.getCounts();
    cout << i << "->";
    v[i] = 1;
    for(int j=0; j<counts;j++)
    {
        if(v[j]==0 && g.matrix[i][j]==1)
            DFS(j, g);
    }


}

void BFS(int start, Graph g)
{
    int counts;
    counts = g.getCounts();
    v[start] = 1;
    for(int j=0; j<counts;j++)
    {
        if(v[j]==0 && g.matrix[start][j]==1)
        {
            adj[adj_count++] = j;
            DFS(j, g);
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(4,6);

    v=new int[g.getCounts()];
    for (int i=0; i<g.getCounts(); i++)
    {
        v[i]=0;
    }

    cout << "For DFS: " << endl;
    DFS(0, g);

    adj = new int[100];
    for (int i=0; i<g.getCounts(); i++)
    {
        v[i]=0;
    }

    cout <<endl << "For BFS: " << endl;
    BFS(0, g);
    for(int i=0; i<adj_count; i++)
    {
        cout << adj[i] << "->" ;
    }
}
