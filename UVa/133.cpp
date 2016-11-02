#include "iostream"
#include "list"
#include "string"
#include "sstream"
#include "iomanip"

template<class T>
void forward(T& it, std::list<int>& l) {
    ++it;
    if (it == l.end()) {
        it = l.begin();
    }
}

template<class T>
void backward(T& it, std::list<int>& l) {
    if (it == l.begin()) {
        it = l.end();
    }
    --it;
}

template<class T>
void forward(T& it, int n, std::list<int>& l) {
    n--;
    while (n--) {
        forward(it, l);
    }
}

template<class T>
void backward(T& it, int n, std::list<int>& l) {
    n--;
    while (n--) {
        backward(it, l);
    }
}

int main() {
    int n, k, m;
    while (true) {
        std::cin >> n >> k >> m;
        if (n == 0) {
            break;
        }
        std::list<int> queue;
        for (int i = 1; i <= n; ++i) {
            queue.insert(queue.begin(), i);
        }
        auto it1 = queue.end();
        --it1;
        auto it2 = queue.begin();
        std::ostringstream ostr;
        while (!queue.empty()) {
            backward(it1, k, queue);
            forward(it2, m, queue);
            if (it1 == it2) {
                ostr << std::setfill(' ') << std::setw(3) << *it1 << ',';
                it2 = queue.erase(it1);
                if (it2 == queue.end()) {
                    it2 = queue.begin();
                }
                it1 = it2;
                backward(it1, queue);
            } else {
                ostr << std::setfill(' ') << std::setw(3) << *it1
                    << std::setfill(' ') << std::setw(3) << *it2 << ',';
                it2 = queue.erase(it2);
                if (it2 == queue.end()) {
                    it2 = queue.begin();
                }
                if (it1 == it2) {
                    forward(it2, queue);
                }
                it1 = queue.erase(it1);
                if (it1 == queue.end()) {
                    it1 = queue.begin();
                }
                backward(it1, queue);
            }
        }
        std::string str = ostr.str();
        std::cout << str.substr(0, str.size() - 1) << std::endl;
    }
    return 0;
}