#include<iostream>
#include <list>
using namespace std;

//Lớp này đại diện cho một đồ thị có hướng bằng cách sử dụng
// biểu diễn danh sách liềnkề
class Graph
{
    int V;    // Số đỉnh

    // Con trỏ trỏ đến một mảng chứa danh sách liền kề
    list<int> *adj;
public:
    Graph(int V);  // Hàm tạo để thêm một cạnh vào đồ thị
    void addEdge(int v, int w);

    // in duyệt BFS từ một nguồn nhất định s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Thêm w vào danh sách của v.
}

void Graph::BFS(int s)
{
    // Đánh dấu tất cả các đỉnh là chưa được duyệt
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Tạo hàng chờ cho BFS
    list<int> queue;

    // Đánh dấu các đỉnh hiện tại là đã được duyệt và thêm nó vào hàng đợi
    visited[s] = true;
    queue.push_back(s);

    // 'i' sẽ được sử dụng để lấy tất cả các đỉnh liền kề của một đỉnh
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Xếp hàng đợi một đỉnh từ hàng đợi và in nó
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Lấy tất cả các đỉnh liền kề của đỉnh s. Nếu một vùng liền kề chưa được truy cập, đánh dấu nó đã được truy cập và xếp vào hàng chờ
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

//Chương trình điều khiển để kiểm tra các phương thức của lớp đồ thị
int main()
{
    // Tạo một đồ thị đã cho như trong sơ đồ trên
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 3);
    g.addEdge(4, 4);

    cout << "Duyet do thi da cho theo thuat toan Tim kiem uu tien chieu rong (BFS) "
         << "(bat dau tu nut 0) \n";
    g.BFS(0);

    return 0;
}