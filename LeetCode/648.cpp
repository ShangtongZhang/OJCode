#include "iostream"
#include "vector"
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
#include "unordered_map"
#include "unordered_set"
#include "numeric"
#include "cmath"

class Solution {
public:
  class Node {
  public:
    char data;
    bool end;
    std::vector<Node*> children;
    Node(char c) : data(c), end(false), children(26) {}
  };
  void insert(Node* node, std::string& word, int pos) {
    if (pos == word.size()) {
      node->end = true;
      return;
    }
    char c = word[pos];
    if (!node->children[c - 'a']) {
      node->children[c - 'a'] = new Node(c);
    }
    insert(node->children[c - 'a'], word, pos + 1);
  }
  bool search(Node* node, std::string& word, int pos, std::string& res) {
    if (!node) {
      return false;
    }
    if (node->end) {
      return true;
    }
    if (pos == word.size()) {
      return false;
    }
    char c = word[pos];
    if (!node->children[c - 'a']) {
      return false;
    }
    res.push_back(c);
    return search(node->children[c - 'a'], word, pos + 1, res);
  }
  std::string replaceWords(std::vector<std::string>& dict, std::string sentence) {
    Node* root = new Node(0);
    for (auto& word : dict) {
      insert(root, word, 0);
    }
    std::stringstream ss(sentence);
    std::string word;
    std::string res;
    while (ss >> word) {
      std::string prefix;
      if (search(root, word, 0, prefix)) {
        res += prefix;
      } else {
        res += word;
      }
      res += ' ';
    }
    res.pop_back();
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<std::string> dict{"ll","now","uap","xn","mtxbk","en","ifm","tty","j","i","ezfyt","k","wpl","rnw","yuuax","fvy","km","ewko","suvti","ddv","dzrfc","f","nkyb","cpme","ensn","bjh","soacg","gd","a","lcwbs","pjze","bwlm","svk","um","rpy","mwyo","iqj","hsiki","yv","sdtd","jns","cfadn","gxotu","uoj","xzao","ug","qnlvo","fgbp","dx","m","wp","yoyf","fyzl","z","mjcso","s","b","u","ad","zrerd","pyxxs","g","pgakz","v","owrpk","slhb","rprt"};
  std::cout << s.replaceWords(dict, "zsyrupfxkwyzxnfkb nvsxmebaqwtejtdikjdb owabmqdbbo ltorldoq w xuyjdxmov hamjfoeae sqlftbmeywleeiscndj p jxu zoslotzcttjnbotki wyhyyueudixnorx vdglkopp cfakarjbf aboaszt onbffyfr cjpfrjqkolnamygqqj uwphkibxemxensz zouhcybstkbdyg ubfwglanyquhwlrglvc givqubayvmrvholkcke vkvyjrjraiollmlt npofa ffwnkttyp gwabsiibv vy tyrsvbuxticx e zfksmowe pdrlwocngdlpv n ouylngqjxilaqlkn zbxhafxxpvjkqpwdsy ssnsy itufigmudtvbv jw sfupomzekekabo caas nkmgrpuhskf rhifdognhfdoo pzecptqfzfvoa jzdlf zkcerlkxxqjy xzkwdgergjosa hgbovwtpzcpwtlwy tly ibtefvaozlsxo jopulkb mmgngozepqlpnqhvkn vwlbuktoipbncdnzhud urnocwb yfsrzjtvbt ybqbkflsz evlxlycwmlttaxlxdfjg xk tjjruytuikaucpcfxr ktbgnifciauv asvclppedfhf mldkna kbqtlbdwgftpzbojvsxm smzgn kyx zgclfw nsywjvgdicwccdoknm rhelltyrist fcijinwjev t");
  return 0;
}