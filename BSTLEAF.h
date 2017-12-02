#ifndef _BSTLEAF_H_
#define _BSTLEAF_H_
#include <iostream>
#include "Map.h"
namespace cop3530{

// template <typename K, typename V>
// struct Node_ssll
// {
//   E data;
//   Node_ssll *next;
// };


template <typename K, typename V, bool (*comparison_fn())(K key1)(K key2)>
class BSTLEAF : public Map<K,V,comparison_fn>
{
public:
  void insert (K key, V val);
  V remove(K key);
  V& lookup(K key);
};

// --- insert --- //
template <typename K, typename V, bool (*comparison_fn())(K key1)(K key2)>
void BSTLEAF<K, V, comparison_fn>::insert(K key, V val)
{

  std::cout << "Insert called from BSTLEAH.h" << std::endl;

}

}
#endif
