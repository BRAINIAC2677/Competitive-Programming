#include <bits/stdc++.h>
using namespace std;

class UndirectedUnweightedGraph
{
    int n, m;
    vector<vector<int>> adj;
    vector<vector<int>> connected_components;

    void dfs_connected_components(int vertex, vector<bool> &visited, vector<int> &current_component);

public:
    void setn(int);
    int getn();
    void setm(int);
    int getm();
    void input_edges();
    void print_edges();
    void add_edge(int u, int v);
    // void rm_edge(int u, int v);
    vector<vector<int>> get_connected_components();
};

void UndirectedUnweightedGraph::dfs_connected_components(int vertex, vector<bool> &visited, vector<int> &current_component)
{
    visited[vertex] = true;
    current_component.push_back(vertex + 1);
    for (int next : this->adj[vertex])
    {
        if (!visited[next])
        {
            dfs_connected_components(next, visited, current_component);
        }
    }
}

void UndirectedUnweightedGraph::setn(int n)
{
    this->n = n;
    this->adj.assign(this->n, vector<int>());
}

int UndirectedUnweightedGraph::getn()
{
    return this->n;
}

void UndirectedUnweightedGraph::setm(int m)
{
    this->m = m;
}

int UndirectedUnweightedGraph::getm()
{
    return this->m;
}

void UndirectedUnweightedGraph::input_edges()
{
    // setn and setm must be called before
    int u, v;
    for (int i = 0; i < this->m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }
}

void UndirectedUnweightedGraph::print_edges()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->adj[i].size(); j++)
        {
            cout << i + 1 << " " << this->adj[i][j] + 1 << endl;
        }
    }
}

void UndirectedUnweightedGraph::add_edge(int u, int v)
{
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
    this->m++;
}

// void UndirectedUnweightedGraph::rm_edge(int u, int v)
// {
//     this->adj[u].erase(find(this->adj[u].begin(), this->adj[u].end(), v));
//     this->adj[v].erase(find(this->adj[v].begin(), this->adj[v].end(), u));
//     this->m--;
// }

vector<vector<int>> UndirectedUnweightedGraph::get_connected_components()
{
    vector<bool> visited(this->n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> current_component;
            dfs_connected_components(i, visited, current_component);
            this->connected_components.push_back(current_component);
        }
    }
    return this->connected_components;
}

int main()
{
    UndirectedUnweightedGraph g;
    int n, m;
    cin >> n >> m;
    g.setn(n);
    g.setm(m);
    g.input_edges();
    vector<vector<int>> comps = g.get_connected_components();
    int cs = comps.size();
    cout << cs - 1 << "\n";
    for (int i = 0; i < cs - 1; i++)
    {
        cout << comps[i][0] << " " << comps[i + 1][0] << "\n";
    }
    return 0;
}