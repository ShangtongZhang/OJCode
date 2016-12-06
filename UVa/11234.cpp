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

class Node {
public:
    Node* left;
    Node* right;
    char data;
    Node(char data_) {
        data = data_;
        left = right = nullptr;
    }
    Node(char data_, Node* left_, Node* right_) {
        data = data_;
        left = left_;
        right = right_;
    }
};

void BFS(Node* root, std::string& data) {
    std::queue<Node*> info;
    info.push(root);
    while (!info.empty()) {
        Node* n = info.front();
        data = n->data + data;
        info.pop();
        if (n->left) {
            info.push(n->left);
        }
        if (n->right) {
            info.push(n->right);
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    while (n--) {
        std::string str;
        std::cin >> str;
        std::vector<Node*> info;
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (std::islower(*it)) {
                info.push_back(new Node(*it));
                continue;
            }
            Node* op1 = info.back();
            info.pop_back();
            Node* op2 = info.back();
            info.pop_back();
            info.push_back(new Node(*it, op2, op1));
        }
        std::string data;
        BFS(info.back(), data);
        std::cout << data << std::endl;
    }
    return 0;
}
