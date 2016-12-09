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

class Node {
public:
    std::vector<Node*> children;
    char data;
    Node(int data_) : children(4, nullptr) {
        data = data_;
    }
};

template <class T>
Node* buildTree(T& it) {
    Node* root = new Node(*it);
    if (*it != 'p') {
        ++it;
        return root;
    }
    ++it;
    for (auto& child : root->children) {
        child = buildTree(it);
    }
    return root;
}

template <class T>
void skipTree(T& it) {
    for (size_t i = 0; i < 4; ++i) {
        ++it;
        if (*it == 'p') {
            skipTree(it);
        }
    }
    ++it;
}

template <class T>
void addTree(Node* root, T& it) {
    if (root->data == 'p' && *it == 'p') {
        ++it;
        for (auto child : root->children) {
            addTree(child, it);
        }
    } else if (root->data == 'p' && *it == 'f') {
        ++it;
        root->data = 'f';
        root->children.resize(4, nullptr);
    } else if (root->data == 'p' && *it == 'e') {
        ++it;
    } else if (root->data == 'f' && *it == 'p') {
        skipTree(it);
    } else if (root->data == 'e' && *it == 'p') {
        ++it;
        root->data = 'p';
        for (auto& child : root->children) {
            child = buildTree(it);
        }
    } else if (root->data == 'f' && (*it == 'f' || *it == 'e')) {
        ++it;
    } else if (root->data == 'e' && *it == 'e') {
        ++it;
    } else if (root->data == 'e' && *it == 'f') {
        ++it;
        root->data = 'f';
    }
}

int DFS(Node* root, int weight) {
    int sum = 0;
    if (root->data == 'f') {
        sum += weight;
    } else if (root->data == 'p') {
        for (auto child : root->children) {
            sum += DFS(child, weight / 4);
        }
    }
    return sum;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::string line;
    while (n--) {
        std::cin >> line;
        auto it = line.begin();
        Node* root = buildTree(it);
        std::cin >> line;
        it = line.begin();
        addTree(root, it);
        std::cout << "There are " << DFS(root, 1024) << " black pixels." << std::endl;
    }
    return 0;
}
