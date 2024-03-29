#include <bits/stdc++.h>
struct Node {
  Node *links[2];
};

class Trie {
  Node *root;

public:
  Trie() { root = new Node(); }
  void insert(int n) {
    Node *node = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (n >> i) & 1;
      if (!node->links[bit])
        node->links[bit] = new Node();
      node = node->links[bit];
    }
  }

  int getMax(int n) {
    Node *node = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      int bit = (n >> i) & 1;
      if (node->links[1 - bit]) {
        ans = ans | (1 << i);
        node = node->links[1 - bit];
      } else
        node = node->links[bit];
    }
    return ans;
  }
};
int maximumXor(vector<int> A) {
  Trie trie;
  for (auto &i : A)
    trie.insert(i);
  int ans = 0;
  for (auto &i : A) {
    ans = max(ans, trie.getMax(i));
  }
  return ans;
  // Write your code here.
}