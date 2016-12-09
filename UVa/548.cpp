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
    Node* left;
    Node* right;
    int data;
    Node(int data_) {
        data = data_;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
Node* buildTree(T it1In, T it2In, T it1Post, T it2Post, int pathValue, int& minPathValue, int& minNode) {
    if (it1In == it2In) {
        return nullptr;
    }
    auto itIn = std::find(it1In, it2In, *std::prev(it2Post));
    auto itPost = it1Post + (itIn - it1In);
    Node* root = new Node(*itIn);
    pathValue += root->data;
    root->left = buildTree(it1In, itIn, it1Post, itPost, pathValue, minPathValue, minNode);
    root->right = buildTree(std::next(itIn), it2In, itPost, std::prev(it2Post), pathValue, minPathValue, minNode);
    if (!root->left && !root->right) {
        if (pathValue < minPathValue || (pathValue == minPathValue && root->data < minNode)) {
            minPathValue = pathValue;
            minNode = root->data;
        }
    }
    return root;
}

int main() {
//    std::ifstream in("data.txt");
//    std::cin.rdbuf(in.rdbuf());
    std::string line;
    std::vector<int> inOrder;
    std::vector<int> postOrder;
    int n;
    std::stringstream iss;
    while (std::getline(std::cin, line)) {
        inOrder.clear();
        postOrder.clear();
        iss.clear();
        iss << line;
        while (iss >> n) {
            inOrder.push_back(n);
        }
        std::getline(std::cin, line);
        iss.clear();
        iss << line;
        while (iss >> n) {
            postOrder.push_back(n);
        }
        int minPathvalue = std::numeric_limits<int>::max();
        int minNode = 0;
        Node* root = buildTree(inOrder.begin(), inOrder.end(), postOrder.begin(), postOrder.end(), 0, minPathvalue, minNode);
        std::cout << minNode << std::endl;
    }
    return 0;
}
