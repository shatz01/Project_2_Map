#ifndef _MAP_H_
#define _MAP_H_
#include <iostream>
namespace cop3530{
template <typename K, typename V, bool (*comparison_fn)(K key1, K key2), bool (*equality_fn)(K key1, K key2)>
class Map
{
public:
  virtual void insert (K key, V val) = 0;
  // virtual V remove(K key) = 0;
  // virtual V& lookup(K key) = 0;
  // virtual bool contains(K key) = 0;
  // virtual bool is_empty() = 0;
  // virtual bool is_full() = 0;
  // virtual size_t size() = 0; // 	returns the number of key-value pairs in the map a size_t.
  // virtual void clear() = 0; // removes all key-value pairs from the map
  // virtual size_t height() = 0;
  // virtual int balance() = 0;
  // virtual LOAD???
  //
  // virtual void print(std::ostream & out) = 0;
  // virtual bool contains(E elt, bool (*equals_fn)(const E &a, const E &b)) = 0;
};


}
#endif
