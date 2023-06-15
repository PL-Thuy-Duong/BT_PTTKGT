cpp
Copy code
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Định nghĩa một cấu trúc đỉnh trong đồ thị
struct Vertex {
    int index;      // chỉ số đỉnh
    int distance;   // khoảng cách từ đỉnh nguồn đến đỉnh này

    Vertex(int idx, int dist) : index(idx), distance(dist) {}
};

// Định nghĩa toán tử so sánh cho hàng đợi ưu tiên
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance; // so sánh theo khoảng cách tăng dần
    }
};

// Thuật toán Dijkstra để tìm đường đi ngắn nhất
void Dijkstra(const vector<vector<int>>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();

    // Khởi tạo các khoảng cách ban đầu với giá trị vô cùng lớn
    distances.assign(numVertices, numeric_limits<int>::max());

    // Đánh dấu đỉnh nguồn và đặt khoảng cách của nó bằng 0
    distances[source] = 0;

    // Tạo hàng đợi ưu tiên để lưu trữ các đỉnh theo thứ tự tăng dần của khoảng cách
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        // Lấy đỉnh có khoảng cách nhỏ nhất từ hàng đợi ưu tiên
        Vertex current = pq.top();
        pq.pop();

        int currentVertex = current.index;
        int currentDistance = current.distance;

        // Kiểm tra xem khoảng cách hiện tại có nhỏ hơn khoảng cách đã lưu trữ hay không
        if (currentDistance > distances[currentVertex])
            continue; // Nếu có, bỏ qua đỉnh này

        // Duyệt qua các đỉnh kề của đỉnh hiện tại
        for (int i = 0; i < numVertices; ++i) {
            // Nếu có cạnh nối từ đỉnh hiện tại đến đỉnh kề i
            if (graph[currentVertex][i] > 0) {
                int newDistance = currentDistance + graph[currentVertex][i];

                // Nếu khoảng cách mới tốt hơn khoảng cách đã lưu trữ
                if (newDistance < distances[i]) {
                    // Cập nhật khoảng cách
                    distances[i] = newDistance;

                    // Thêm đỉnh kề i vào hàng đợi ưu tiên
                    pq.push(Vertex(i, newDistance));
                }
            }
        }
    }
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph = {
        {0, 2, 4, 0, 0, 0},
        {0, 0, 0, 1, 3, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0; // Đỉnh nguồn

    // Mảng lưu trữ khoảng cách từ đỉnh nguồn đến các đỉnh khác
    vector<int> distances(numVertices);

    // Gọi thuật toán Dijkstra để tìm đường đi ngắn nhất
    Dijkstra(graph, source, distances);

    // In ra khoảng cách từ đỉnh nguồn đến các đỉnh còn lại
    cout << "Khoang cach tu dinh nguon " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Dinh " << i << ": " << distances[i] << endl;
    }

    return 0;
}