#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;

struct Canh {
    int u, v, w; // Cạnh từ u đến v với trọng số w
};

class Graph {
private:
    int dinh;
    vector<vector<pair<int, int>>> adjList; // Danh sách kề với trọng số
    vector<Canh> canh;

public:
    Graph(int vertices) : dinh(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w); // Nếu đồ thị vô hướng
        canh.push_back({ u, v, w });
    }

    void display() {
        for (int i = 0; i < dinh; i++) {
            cout << "Dinh " << i << ": ";
            for (auto& p : adjList[i]) {
                cout << "(" << i << ", " << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }

    // Hàm tìm kiếm và hợp nhất cho thuật toán Kruskal
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void unionSet(vector<int>& parent, int x, int y) {
        parent[x] = y;
    }

    // Thuật toán Kruskal
    void kruskal() {
        sort(canh.begin(), canh.end(), [](Canh a, Canh b) {
            return a.w < b.w;
            });

        vector<int> parent(dinh, -1);

        cout << "\nCay khung toi thieu (Kruskal):" << endl;
        for (auto& edge : canh) {
            int x = find(parent, edge.u);
            int y = find(parent, edge.v);

            if (x != y) {
                cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
                unionSet(parent, x, y);
            }
        }
    }

    // Thuật toán Dijkstra
    void dijkstra(int start) {
        vector<int> dist(dinh, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start });
        dist[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& p : adjList[u]) {
                int v = p.first;
                int weight = p.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        cout << "Duong di ngan nhat tu dinh " << start << " den cac dinh khac:" << endl;
        for (int i = 0; i < dinh; i++) {
            cout << "Dinh " << i << ": "
                << (dist[i] == INT_MAX ? "Khong co duong di" : toString(dist[i])) << endl;
        }
    }

    // Hàm chuyển đổi int sang string bằng stringstream
    string toString(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
};

void displayMenu()
{
    cout << "\n====== DO THI ======" << endl;
    cout << "1. Thuat toan Kruskal" << endl;
    cout << "2. Thuat toan Dijkstra" << endl;
    cout << "3. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    int dinh, canh;
    cout << "Nhap so dinh: "; cin >> dinh;
    Graph g(dinh);
    cout << "Nhap so canh: "; cin >> canh;

    cout << "Nhap thong tin cua canh (u, v, w): ";
    for (int i = 0; i < canh; i++)
    {
        int u, v, w;
        cout << "\nNhap canh " << i << ": "; 
        cout << "\n +) Nhap dinh dau: "; cin >> u;
        cout << "\n +) Nhap dinh cuoi: "; cin >> v;
        cout << "\n +) Nhap trong so: "; cin >> w;
        g.addEdge(u, v, w);
    }

    cout << "Danh sach ke:" << endl;
    g.display();
    int menu = 0, choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1: {
            g.kruskal();
            break;
        }

        case 2: {
            int start;
            cout << "Nhap dinh bat dau: ";
            cin >> start;
            g.dijkstra(start);
            break;
        }

        case 3: {
            exit(0);
        }
        }
    } while (menu == 0);
    

    return 0;
}
