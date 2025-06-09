// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class PMTree {
 public:
  struct Node {
    char value;
    std::vector<Node*> children;
    explicit Node(char v) : value(v) {}
  };

  explicit PMTree(const std::vector<char>& in);
  ~PMTree();

  Node* root;
  std::vector<char> input;

 private:
  PMTree(const PMTree&) = delete;
  PMTree& operator=(const PMTree&) = delete;
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);
size_t factorial(int n);

#endif  // INCLUDE_TREE_H_
