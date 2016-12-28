#include "iostream"
#include "vector"
#include "math.h"
#include "map"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "sstream"
#include "queue"
#include "fstream"
#include "iomanip"
#include "cstring"
#include "bitset"
#include "time.h"

constexpr int MAX_L = 205;
constexpr int INF = 0x7FFFFFFF;

bool visited[MAX_L][MAX_L][MAX_L];
int minW[MAX_L];

class Node {
public:
    int a;
    int b;
    int c;
    int w;
};

auto cmp = [](Node& l, Node& r) {
    return l.w > r.w;
};

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n, maxA, maxB, maxC, target;
    std::cin >> n;
    while (n--) {
        std::memset(visited, 0, sizeof(visited));
        std::cin >> maxA >> maxB >> maxC >> target;
        for (int i = 0; i <= target; ++i) {
            minW[i] = INF;
        }
        
        int flag = false;
//        std::vector<int> minW(MAX_L, INF);
        std::priority_queue<Node, std::vector<Node>, decltype(cmp)> path(cmp);
        path.push(Node{0, 0, maxC, 0});
        while (!path.empty()) {
            Node u = path.top();
            path.pop();
            visited[u.a][u.b][u.c] = true;
            
            if (u.a == target || u.b == target || u.c == target) {
                flag = true;
                std::cout << u.w << ' ' << target << std::endl;
                break;
            }
            
            minW[u.a] = std::min(minW[u.a], u.w);
            minW[u.b] = std::min(minW[u.b], u.w);
            minW[u.c] = std::min(minW[u.c], u.w);
            
            int w;
            
            {
                w = std::min(u.a, maxB - u.b);
                Node v{u.a - w, u.b + w, u.c, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }

            {
                w = std::min(u.a, maxC - u.c);
                Node v{u.a - w, u.b, u.c + w, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }
            
            {
                w = std::min(u.b, maxC - u.c);
                Node v{u.a, u.b - w, u.c + w, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }
            
            {
                w = std::min(u.b, maxA - u.a);
                Node v{u.a + w, u.b - w, u.c, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }
            
            {
                w = std::min(u.c, maxA - u.a);
                Node v{u.a + w, u.b, u.c - w, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }
            
            {
                w = std::min(u.c, maxB - u.b);
                Node v{u.a, u.b + w, u.c - w, u.w + w};
                if (w > 0 && !visited[v.a][v.b][v.c]) {
                    path.push(v);
                }
            }
        }
        if (!flag) {
            while (minW[target] == INF) {
                target--;
            }
            std::cout << minW[target] << ' ' << target << std::endl;
        }
    }
    return 0;
}
