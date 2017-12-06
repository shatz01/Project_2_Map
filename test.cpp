#include "BSTLEAF.h"
#include "BSTROOT.h"
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


  // BSTLEAF<int, char, comparison_fn, equality_fn > leaf_tree;
  cop3530::Map<int, char, comparison_fn, equality_fn> *tree  = new cop3530::BSTROOT<int, char, comparison_fn, equality_fn>();
  tree->insert(1, 'a');
  tree->insert(5, 'b');
  tree->insert(3, 'c');
  std::cout << tree->lookup(3) << std::endl;
  // tree->ins
  // tree->insert(13, 'c');
  // tree->insert(14, 'f');
  // tree->insert(12, 'e');
  // tree->remove(13);
  std::cout << "size: "<< tree->size() << std::endl;
  tree->print_root();

  // char *arr = tree->contents();
  tree->print_inorder();
  std::cout << std::endl;

  // std::cout << leaf_tree.lookup(6) << std::endl;

  // cop3530::BSTLEAF<int, int, comparison_fn, eq


  // bool seven = list->contains(7, [](const int& a, const int& b) { return a == b;});

  return 0;
}
