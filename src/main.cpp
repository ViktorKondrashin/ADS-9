// Copyright 2022 NNTU-CS
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "tree.h"

int main() {
  std::vector<char> in = {'1', '2', '3'};
  PMTree tree(in);

  for (const auto& perm : getAllPerms(tree)) {
    for (char c : perm) std::cout << c;
    std::cout << '\n';
  }

  std::cout << "getPerm1(1): ";
  for (char c : getPerm1(tree, 1)) std::cout << c;
  std::cout << '\n';

  std::cout << "getPerm2(2): ";
  for (char c : getPerm2(tree, 2)) std::cout << c;
  std::cout << '\n';

  for (int n = 3; n <= 7; ++n) {
    std::vector<char> alpha;
    for (int i = 0; i < n; ++i) alpha.push_back('a' + i);
    PMTree t(alpha);

    std::mt19937 gen(42);
    std::uniform_int_distribution<> dist(1, static_cast<int>(factorial(n)));
    int k = dist(gen);

    const auto t0 = std::chrono::high_resolution_clock::now();
    getAllPerms(t);
    const auto t1 = std::chrono::high_resolution_clock::now();
    getPerm1(t, k);
    const auto t2 = std::chrono::high_resolution_clock::now();
    getPerm2(t, k);
    const auto t3 = std::chrono::high_resolution_clock::now();

    const double dt_all  = std::chrono::duration<double>(t1 - t0).count();
    const double dt_p1   = std::chrono::duration<double>(t2 - t1).count();
    const double dt_p2   = std::chrono::duration<double>(t3 - t2).count();

    std::cout << "n=" << n << ": getAllPerms=" << dt_all
              << "s getPerm1=" << dt_p1 << "s getPerm2=" << dt_p2 << "s\n";
  }
  return 0;
}
