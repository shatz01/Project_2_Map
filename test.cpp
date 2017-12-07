#include "BSTLEAF.h"
#include "BSTROOT.h"
#include "BSTRAND.h"
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
  cop3530::Map<int, char, comparison_fn, equality_fn> *tree  = new cop3530::BSTRAND<int, char, comparison_fn, equality_fn>();
  tree->insert(10, 'a');
  tree->print_inorder();
  std::cout << std::endl;

  tree->insert(7, 'b');
  tree->print_inorder();
  std::cout << std::endl;

  tree->insert(13, 'c');
  tree->print_inorder();
  std::cout << std::endl;

  tree->insert(12, 'e');
  tree->print_inorder();
  std::cout << std::endl;

  tree->insert(14, 'f');
  tree->print_inorder();
  std::cout << std::endl;

  std::cout << "CURRENT ROOT: ";
  tree->print_root();
  std::cout << std::endl;

  tree->remove(13);
  // std::cout << tree->lookup(3) << std::endl;
  // std::cout << "size: "<< tree->size() << std::endl;
  // tree->print_root();

  // char *arr = tree->contents();
  tree->print_inorder();
  std::cout << std::endl;

  // std::cout << leaf_tree.lookup(6) << std::endl;

  // cop3530::BSTLEAF<int, int, comparison_fn, eq


  // bool seven = list->contains(7, [](const int& a, const int& b) { return a == b;});

  return 0;
}
