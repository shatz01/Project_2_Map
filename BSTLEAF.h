#ifndef _BSTLEAF_H_
#define _BSTLEAF_H_
#include <iostream>
#include "Map.h"
namespace cop3530{




template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2), bool (*equality_fn)( K key1 ,  K key2 )>
class BSTLEAF : public Map<K,V,comparison_fn, equality_fn>
{
private:
  struct Node
  {
    Node(K key_a, V val_a);
    K key;
    V val;
    Node *r = nullptr;
    Node *l = nullptr;
  };

public:
  BSTLEAF();
  void insert (K key, V val);
  void r_insert(Node *&rt, K key, V val);
  V remove(K key);
  V& lookup(K key);
  bool is_empty();
  void print_inorder();
  void r_print_inorder(Node *&rt);
  Node*& find_node(Node *&rt, K key);

private:
  Node *root;

};

// --- node constructor with initializer list --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
BSTLEAF<K, V, comparison_fn, equality_fn>::Node::Node(K key_a, V val_a) : key(key_a), val(val_a) {}


// --- constructor --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
BSTLEAF<K, V, comparison_fn, equality_fn>::BSTLEAF()
{
  root = nullptr;
}

// --- insert --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTLEAF<K, V, comparison_fn, equality_fn>::insert(K key, V val)
{
  r_insert(root, key, val);

}

// --- r_insert --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTLEAF<K, V, comparison_fn, equality_fn>::r_insert(Node *&rt, K key, V val)
{

  // if (!rt) // base case
  //   rt = new Node(key, val);
  // else
  //   if (comparison_fn(key, rt->key))
  //     r_insert(rt->l, key, val);
  //   else
  //     r_insert(rt->r, key, val);


  if (!rt){
    rt = new Node(key, val);
  } else {
    if (comparison_fn(key, rt->key)){
      r_insert(rt->l, key, val);
    }
    else {
      r_insert(rt->r, key, val);
    }
  }





}

// --- is_empty --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
bool BSTLEAF<K, V, comparison_fn, equality_fn>::is_empty()
{
  return (!root);
}


// --- print_inorder --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTLEAF<K, V, comparison_fn, equality_fn>::print_inorder()
{
  r_print_inorder(root);
}


// --- r_ print_inorder --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTLEAF<K, V, comparison_fn, equality_fn>::r_print_inorder(Node *&rt)
{
  // std::cout << "got here tho" << std::endl;
  if (!rt)
    return;
 // first do left node
  r_print_inorder(rt->l);

  // then print the data of node
  std::cout << rt->val << " ";

  // now recur on right child
  r_print_inorder(rt->r);
}

// --- find_node --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
typename BSTLEAF<K, V, comparison_fn, equality_fn>::Node*& BSTLEAF<K, V, comparison_fn, equality_fn>::find_node(Node *&rt, K key)
{
  if (!rt) // if we have gotten to the child of a leaf node, throw an error
    throw std::runtime_error("BSTLEAF.find_node(): key not found");
  if(equality_fn(rt->key, key))
    return rt;
  else
    return (comparison_fn(key, rt->key) ? find_node(rt->l, key) : find_node(rt->r, key));
}

// --- lookup --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
V& BSTLEAF<K, V, comparison_fn, equality_fn>::lookup(K key)
{
  return (find_node(root, key)->val);
}

// --- remove --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
V BSTLEAF<K, V, comparison_fn, equality_fn>::remove(K key)
{
  Node *node_to_remove = find_node(root, key)
  V removed_val = node_to_remove->val;

  // 3 cases
  switch(num_children(node_to_remove))
  {
    case 0: delete node_to_remove;
            node_to_remove = nullptr;
    case 1: // find previous node, write a function for it.
  }

}

// --- num_children --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
int BSTLEAF<K, V, comparison_fn, equality_fn>::num_children(Node *curr)
{
  if(curr->l && curr->r) // this node has 2 children
    return 2;
  else if (curr->l || curr->r) // this node has 1 children
    return 1;
  else // node has no children
    return 0;
}


}
#endif
