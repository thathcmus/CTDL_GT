#include <iostream>
#include <list>
using namespace std;
//Lớp đồ thị để duyệt theo DFS
class DFSGraph
{
    int V;    // Số đỉnh của đồ thị
    list<int> *adjList;    // Danh sách liền kề
    void DFS_util(int v, bool visited[]);  //Hàm được dùng bởi DFS
public:

// Hàm tạo Đồ thị
DFSGraph(int V)
{
    this->V = V;
    adjList = new list<int>[V];
}


// Hàm thêm cạnh vào đồ thị
void addEdge(int v, int w)
{
    adjList[v].push_back(w); // Thêm w vào danh sách của v
}

void DFS();    // Hàm duyệt đồ thị theo DFS
};


void DFSGraph::DFS_util(int v, bool visited[])
{
    // Nút hiện tại đã được duyệt
    visited[v] = true;
    cout << v << " ";

    // Xử lý đệ quy tất cả các nút liền kề của nút hiện tại
    list<int>::iterator i;
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i)
    if(!visited[*i])
    DFS_util(*i, visited);
}

// Gọi hàm duyệt DFS
void DFSGraph::DFS()
{
    // Ban đầu không có nút nào được duyệt
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;

        // Duyệt từng nút bằng cách gọi đệ quy DFS_util
    for (int i = 0; i < V; i++)
    if (visited[i] == false)
    DFS_util(i, visited);
}

int main()
{
    // Tạo đồ thị
    DFSGraph gdfs(5);
    gdfs.addEdge(0, 1);
    gdfs.addEdge(0, 2);
    gdfs.addEdge(0, 3);
    gdfs.addEdge(1, 2);
    gdfs.addEdge(2, 4);
    gdfs.addEdge(3, 3);
    gdfs.addEdge(4, 4);

    cout << "\nDuyet do thi da cho theo thuat toan Tim kiem uu tien chieu sau (DFS) :"<<endl;
    gdfs.DFS();

    return 0;
}