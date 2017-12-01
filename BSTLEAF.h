#ifndef _BSTLEAF_H_
#define _BSTLEAF_H_
#include "Map.h"
namespace cop3530{

template <typename K, typename V, (*comparison_fn)(E key1)(E key2), (*equality_fn)(E key1)(E key2)>
class BSTLEAF : public Map<K,V,comparison_fn,equality_fn>
{
public:
  void insert (K key, V val);
  V remove(K key);
  V& lookup(K key);
}





}
