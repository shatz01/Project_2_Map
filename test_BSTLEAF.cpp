#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "BSTLEAF.h"

#include <iostream>

bool comparison_fn(int a, int b) {
  return a < b;
}

bool equality_fn(int a, int b) {
  return a == b;
}

SCENARIO ("INTERFACE TEST") {
	GIVEN ("Map with just 3 elements in it. 1 parent with 2 children.") {

		cop3530::Map<int, char, comparison_fn, equality_fn> *tree  = new cop3530::BSTLEAF<int, char, comparison_fn, equality_fn>();

		// list->insert('A', 0);
		// list->insert('B', 1);
		// list->push_back('C');
		// list->push_front('D');
    //
		// WHEN ("Peek front is called") {
		// 	char front = list->peek_front();
		// 	THEN ("Item should be D") {
		// 		REQUIRE(front == 'D');
		// 	}
		// }
		// delete list;
	}
}
