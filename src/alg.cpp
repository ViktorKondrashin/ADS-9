// Copyright 2022 NNTU-CS
#include <algorithm>
#include <vector>

#include "tree.h"

PMTree::PMTree(const std::vector<char>& in) : root(nullptr), input(in) {}

PMTree::~PMTree() {}

size_t factorial(int n) {
  size_t res = 1;
  for (int i = 2; i <= n; ++i) res *= i;
  return res;
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<char> current = tree.input;
  std::sort(current.begin(), current.end());
  std::vector<std::vector<char>> perms;
  do {
    perms.push_back(current);
  } while (std::next_permutation(current.begin(), current.end()));
  return perms;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  const auto perms = getAllPerms(tree);
  if (num < 1 || num > static_cast<int>(perms.size())) return {};
  return perms[num - 1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  const int n = static_cast<int>(tree.input.size());
  const size_t total = factorial(n);
  if (num < 1 || num > static_cast<int>(total)) return {};

  std::vector<char> elems = tree.input;
  std::sort(elems.begin(), elems.end());

  std::vector<char> result;
  --num;  // zero-based индекс
  for (int i = n; i > 0; --i) {
    const size_t fact = factorial(i - 1);
    const size_t idx = num / fact;
    num %= static_cast<int>(fact);
    result.push_back(elems[idx]);
    elems.erase(elems.begin() + idx);
  }
  return result;
}
