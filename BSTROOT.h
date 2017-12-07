#ifndef _BSTROOT_H_
#define _BSTROOT_H_
#include <iostream>
#include "Map.h"
namespace cop3530{




template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2), bool (*equality_fn)( K key1 ,  K key2 )>
class BSTROOT : public Map<K,V,comparison_fn, equality_fn>
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
  BSTROOT();
  void insert (K key, V val);
  void r_insert(Node *&rt, K key, V val);
  V remove(K key);
  V& lookup(K key);
  bool is_empty();
  void print_inorder();
  void r_print_inorder(Node *&rt);
  Node*& find_node(Node *&rt, K key);
  int num_children(Node *curr);
  Node*& find_parent(Node *&rt, K key);
  bool is_l_of_parent(Node *child, Node *parent);
  bool has_left(Node *curr);
  bool has_right(Node *curr);
  size_t size();
  size_t r_size(Node *rt);
  V* contents();
  void r_contents(Node *rt, V *arr, size_t &i);
  void ext_remove(Node *&rt);
  Node*& smallest_node(Node *&rt);
  void rotate_left(Node *&rt);
  void rotate_right(Node *&rt);
  void print_root();

private:
  Node *root;

};

// --- node constructor with initializer list --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
BSTROOT<K, V, comparison_fn, equality_fn>::Node::Node(K key_a, V val_a) : key(key_a), val(val_a) {}


// --- constructor --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
BSTROOT<K, V, comparison_fn, equality_fn>::BSTROOT()
{
  root = nullptr;
}

// --- print_root --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::print_root()
{
  std::cout << "Root: " << root->val << std::endl;
}

// --- insert --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::insert(K key, V val)
{
  r_insert(root, key, val);

}

// --- r_insert --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::r_insert(Node *&rt, K key, V val)
{
  if (!rt){
    rt = new Node(key, val);
    return;
  } else {
    if (comparison_fn(key, rt->key)){
      r_insert(rt->l, key, val);
      rotate_right(rt);
    }
    else {
      r_insert(rt->r, key, val);
      rotate_left(rt);
    }
  }
}

// --- rotate_left --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::rotate_left(Node *&rt)
{
  if( !rt->r ) // this if return is only because of the case inserting 1, 5, 3
    return;

  Node *tmp = rt;
  rt = rt->r;
  tmp->r = rt->l;
  rt->l = tmp;


  // Node *tmp = rt->r;
  // if (tmp->l)
  //   rt->r = tmp->l;
  // else
  //   rt->r = nullptr;
  // tmp->l = rt;
  // root = tmp;
}

// --- rotate_right --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::rotate_right(Node *&rt)
{
  if( !rt->l ) // this if return is only because of the case inserting 1, 5, 3
    return;

  Node *tmp = rt;
  rt = rt->l;
  tmp->l = rt->r;
  rt->r = tmp;
  // Node *tmp = rt->l;
  // if (tmp->r)
  //   rt->l = tmp->r;
  // else
  //   rt->l = nullptr;
  // tmp->r = rt;
  // root = tmp;
}



// --- is_empty --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
bool BSTROOT<K, V, comparison_fn, equality_fn>::is_empty()
{
  return (!root);
}


// --- print_inorder --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::print_inorder()
{
  r_print_inorder(root);
}


// --- r_ print_inorder --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::r_print_inorder(Node *&rt)
{
  // std::cout << "got here tho" << std::endl;
  if (!rt)
    return;
 // first do left node
  r_print_inorder(rt->l);

  // then print the data of node
  std::cout << rt->val << " | ";

  // now right
  r_print_inorder(rt->r);
}

// --- find_node --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
typename BSTROOT<K, V, comparison_fn, equality_fn>::Node*& BSTROOT<K, V, comparison_fn, equality_fn>::find_node(Node *&rt, K key)
{
  if (!rt) // if we have gotten to the child of a leaf node, throw an error
    throw std::runtime_error("BSTROOT.find_node(): key not found");
  if(equality_fn(rt->key, key))
    return rt;
  else
    return (comparison_fn(key, rt->key) ? find_node(rt->l, key) : find_node(rt->r, key));
}

// --- lookup --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
V& BSTROOT<K, V, comparison_fn, equality_fn>::lookup(K key)
{
  return (find_node(root, key)->val);
}

// --- remove --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
V BSTROOT<K, V, comparison_fn, equality_fn>::remove(K key)
{
  Node *node_to_remove = find_node(root, key);
  bool remove_root = false;
  if (node_to_remove == root){
    remove_root = true;
  }



  if (!remove_root){ // node that you want to remove IS NOT the root
    Node *node_to_removes_parent = find_parent(root, node_to_remove->key);
    bool l_of_parent = is_l_of_parent(node_to_remove, node_to_removes_parent);
    V removed_val = node_to_remove->val;

    // 3 cases
    switch(num_children(node_to_remove))
    {
      case 0: if(l_of_parent)
                node_to_removes_parent->l = nullptr;
              else
                node_to_removes_parent->r = nullptr;
              delete node_to_remove;
              break;

      case 1: if (l_of_parent)
                if (has_left(node_to_remove))
                  node_to_removes_parent->l = node_to_remove->l;
                else
                  node_to_removes_parent->l = node_to_remove->r;
              else
                if (has_left(node_to_remove))
                  node_to_removes_parent->r = node_to_remove->l;
                else
                  node_to_removes_parent->r = node_to_remove->r;
              delete node_to_remove;
              break;

      case 2: // first find smallest node in right subtree
              // std::cout << "GOOD GOOD" << std::endl;
              Node *sm_nd = smallest_node(node_to_remove->r);
              // std::cout << sm_nd->val << std::endl;
              // now get the key and value of the node you need to remove to the smallest nodes pair
              K new_key = sm_nd->key;
              V new_val = sm_nd->val;

              // now I need to delete the smallest node
              ext_remove(sm_nd);

              node_to_remove->key = new_key;
              node_to_remove->val = new_val;
              break;
    }
    return removed_val;
  } else { // node that you want to remove IS the root
    V removed_val = node_to_remove->val;

    // 3 cases
    switch(num_children(node_to_remove))
    {
      case 0: delete node_to_remove;
              root = nullptr;
              break;

      case 1: if (has_left(node_to_remove))
              {
                root = root->l;
                delete node_to_remove;
              } else {
                root = root->r;
                delete node_to_remove;
              }
              break;

      case 2: // first find smallest node in right subtree
              Node *sm_nd = smallest_node(node_to_remove->r);
              // now get the key and value of the node you need to remove to the smallest nodes pair
              K new_key = sm_nd->key;
              V new_val = sm_nd->val;

              // now I need to delete the smallest node
              ext_remove(sm_nd);

              node_to_remove->key = new_key;
              node_to_remove->val = new_val;
              break;
    }

    return removed_val;
  }
}

// --- ext_remove --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::ext_remove(Node *&rt)
{
  Node *node_to_remove = rt;
  Node *node_to_removes_parent = find_parent(root, rt->key);
  bool l_of_parent = is_l_of_parent(node_to_remove, node_to_removes_parent);

  switch(num_children(node_to_remove))
  {
    case 0: if(l_of_parent)
              node_to_removes_parent->l = nullptr;
            else
              node_to_removes_parent->r = nullptr;
            delete node_to_remove;
            break;

    case 1: if (l_of_parent)
              if (has_left(node_to_remove))
                node_to_removes_parent->l = node_to_remove->l;
              else
                node_to_removes_parent->l = node_to_remove->r;
            else
              if (has_left(node_to_remove))
                node_to_removes_parent->r = node_to_remove->l;
              else
                node_to_removes_parent->r = node_to_remove->r;
            delete node_to_remove;
            break;
  }
}

// --- smallest_node --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
typename BSTROOT<K, V, comparison_fn, equality_fn>::Node*& BSTROOT<K, V, comparison_fn, equality_fn>::smallest_node(Node *&rt)
{
  // just need to traverse as far left as possible
  if(!rt->l)
    return rt;
  return smallest_node(rt->l);
}


// --- num_children --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
int BSTROOT<K, V, comparison_fn, equality_fn>::num_children(Node *curr)
{
  if(curr->l && curr->r) // this node has 2 children
    return 2;
  else if (curr->l || curr->r) // this node has 1 children
    return 1;
  else // node has no children
    return 0;
}

// --- find_parent --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
typename BSTROOT<K, V, comparison_fn, equality_fn>::Node*& BSTROOT<K, V, comparison_fn, equality_fn>::find_parent(Node *&rt, K key)
{
  // we will only look for its parent if it has more than 1 node in tree
  if(rt->l)
  {
    if(equality_fn((rt->l)->key, key))
      return rt;
  }
  if (rt->r) {
    if(equality_fn((rt->r)->key, key))
      return rt;
  }
  return (comparison_fn(key, rt->key) ? find_parent(rt->l, key) : find_parent(rt->r, key));
}

// --- is_l_of_parent --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
bool BSTROOT<K, V, comparison_fn, equality_fn>::is_l_of_parent(Node *child, Node *parent)
{
  if (parent->l)
  {
    if((parent->l)->key == child->key)
      return true;
  }
  return false;
}

// --- has_left --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
bool BSTROOT<K, V, comparison_fn, equality_fn>::has_left(Node *curr)
{
  return curr->l;
}

// --- has_right --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
bool BSTROOT<K, V, comparison_fn, equality_fn>::has_right(Node *curr)
{
  return curr->r;
}

// --- size --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
size_t BSTROOT<K, V, comparison_fn, equality_fn>::size()
{

  size_t num_nodes = 0;
  if (!is_empty())
    num_nodes = r_size(root);
  return num_nodes;
}

// --- r_size --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
size_t BSTROOT<K, V, comparison_fn, equality_fn>::r_size(Node *rt)
{
  size_t num_nodes = 1;
  if (rt->l)
    num_nodes += r_size(rt->l);
  if (rt->r)
    num_nodes += r_size(rt->r);
  return num_nodes;
}


// --- contents --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
V* BSTROOT<K, V, comparison_fn, equality_fn>::contents()
{
  size_t size_contents = size();
  V *arr = new V[size_contents];
  size_t j = 0;
  r_contents(root, arr, j);

  return arr;
}

// --- r_contents --- //
template <typename K, typename V, bool (*comparison_fn)( K key1,  K key2 ), bool (*equality_fn)( K key1 ,  K key2)>
void BSTROOT<K, V, comparison_fn, equality_fn>::r_contents(Node *rt, V* arr, size_t &i)
{

  if (!rt)
    return;
 // first do left node
  // if (rt->l)
  r_contents(rt->l, arr, i);

  arr[i] = rt->val;
  ++i;

  // if(rt->r)
  r_contents(rt->r, arr, i);
}


}
#endif
