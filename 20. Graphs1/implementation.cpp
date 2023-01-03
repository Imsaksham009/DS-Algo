#include <iostream>

using namespace std;

void print(int **edges, int n,int sv,bool* visited)
{
    cout<<sv<<" ";
    visited[sv] = true;

    for(int i{0};i<n;i++)
    {
        if(edges[sv][i] == 1)
        {
            if(visited[i]) continue;
            print(edges,n,i,visited);
        }
    }
}

int main()
{
    int n{0}, e{0};
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i{0}; i < n; i++)
    {
        edges[i] = new int[n];
    }

    // fill GV's with 0
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // take input and make entry of 1 in 2-d array
    for (int i{0}; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i{0}; i < n; i++)
        visited[i] = false;
    print(edges, n,0,visited);

    delete[] visited;

    for (int i{0}; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    
    return 0;
}