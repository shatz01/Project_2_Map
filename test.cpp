#include "BSTLEAF.h"
using namespace cop3530;
// bool comparison_fn()
bool comparison_fn(int a, int b) {
  return a < b;
}

// bool comparison_fn()
bool equality_fn(int a, int b) {
  return a == b;
}

int main(){
  // cop3530::Map<int, char, (*comparison_fn)(const int& a, const int& b), (*equality_fn)(const int& a, const int& b) > *map = new cop3530::BSTLEAF<int, char, (*comparison_fn)(const int& a, const int& b), (*equality_fn)(const int& a, const int& b)>();


  BSTLEAF<int, char, comparison_fn, equality_fn > leaf_tree;
  leaf_tree.insert(5, 'a');

  // cop3530::BSTLEAF<int, int, comparison_fn, eq


  // bool seven = list->contains(7, [](const int& a, const int& b) { return a == b;});

  return 0;
}
