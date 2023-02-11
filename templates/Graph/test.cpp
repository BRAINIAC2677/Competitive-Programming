#include <bits/stdc++.h>
using namespace std;

class UndirectedUnweightedGraph
{
    int n, m;
    vector<vector<int>> adj;
    vector<vector<int>> connected_components;
    vector<vector<int>> cycles;

    void dfs_connected_components(int vertex, vector<bool> &visited, vector<int> &current_component);
    void dfs_cycles(int v, int p, int &current_cycle_number, vector<int> &color, vector<int> &parents, vector<int> &cycle_numbers);

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
    vector<vector<int>> get_cycles();
};

void UndirectedUnweightedGraph::dfs_cycles(int u, int p, int &current_cycle_number, vector<int> &color, vector<int> &parents, vector<int> &cycle_numbers)
{

    cout << u << "\n";
    if (color[u] == 2)
    {
        return;
    }

    if (color[u] == 1)
    {
        int cur = p;
        cycle_numbers[cur] = current_cycle_number;
        while (cur != u)
        {
            cur = parents[cur];
            cycle_numbers[cur] = current_cycle_number;
        }
        current_cycle_number++;
    }

    parents[u] = p;
    color[u] = 1;
    for (int v : this->adj[u])
    {
        if (v != parents[u])
        {
            dfs_cycles(v, u, current_cycle_number, color, parents, cycle_numbers);
        }
    }

    color[u] = 2;
}

vector<vector<int>> UndirectedUnweightedGraph::get_cycles()
{
    int current_cycle_number = 0;
    vector<int> color(this->n), parents(this->n, -1), cycle_numbers(this->n, -1);
    dfs_cycles(0, -1, current_cycle_number, color, parents, cycle_numbers);
    this->cycles.assign(current_cycle_number, vector<int>());
    for (int i = 0; i < this->n; i++)
    {
        if (cycle_numbers[i] != -1)
        {
            this->cycles[cycle_numbers[i]].push_back(i + 1); // i+1 as returned vertex are 1-indexed
        }
    }
    return this->cycles;
}

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
    // vertices of returned connected components are numbered from 1 to n
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
    cout << "\n";
    g.print_edges();
    vector<vector<int>> cycles = g.get_cycles();
    for (int i = 0; i < cycles.size(); i++)
    {
        for (int j = 0; j < cycles[i].size(); j++)
        {
            cout << cycles[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}