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

SCENARIO ("TEST 1") {
	GIVEN ("Map with just 3 elements in it. 1 parent with 2 children.") {

		cop3530::Map<int, char, comparison_fn, equality_fn> *tree  = new cop3530::BSTLEAF<int, char, comparison_fn, equality_fn>();

    REQUIRE(tree->size() == 0);

    tree->insert(10, 'a');
    REQUIRE(tree->size() == 1);
    tree->insert(7, 'b');
    REQUIRE(tree->size() == 2);
    tree->insert(13, 'c');
    REQUIRE(tree->size() == 3);

    WHEN("Making sure contents are as expected"){
      char *result = tree->contents();
      char *predicted = new char[3] {'b', 'a', 'c'};
      THEN("Indexes should match") {
        for (int i = 0; i < 3; ++i)
        {
          REQUIRE(result[i] == predicted[i]);
        }
      }
    }

    WHEN("Removing one of leaf nodes") {
      REQUIRE(tree->remove(7) == 'b');

      THEN("Size should be 2") {
        REQUIRE(tree->size() == 2);
      }

      THEN("Indexes should match") {
        char *result = tree->contents();
        char *predicted = new char[2] {'a', 'c'};
        for (int i = 0; i < 2; ++i)
        {
          REQUIRE(result[i] == predicted[i]);
        }
      }
    }

    WHEN("Add a child to tree") {
      tree->insert(12, 'e');

      THEN("size should be 4") {
        REQUIRE(tree->size() == 4);
      }

      THEN("Indexes should match") {
        char *result = tree->contents();
        char *predicted = new char[4] {'b', 'a', 'e', 'c'};
        for (int i = 0; i < 4; ++i)
        {
          REQUIRE(result[i] == predicted[i]);
        }
      }

      THEN("Remove c (has 1 child)") {
        REQUIRE(tree->remove(13) == 'c');

        THEN("Indexes should match") {
          char *result = tree->contents();
          char *predicted = new char[3] {'b', 'a', 'e'};
          for (int i = 0; i < 3; ++i)
          {
            REQUIRE(result[i] == predicted[i]);
          }
        }
      }
    }

    WHEN("A node that you want to remove has 2 children"){
      tree->insert(12, 'e');
      tree->insert(14, 'f');

      THEN("size should be 5") {
        REQUIRE(tree->size() == 5);
      }

      THEN("Indexes should match") {
        char *result = tree->contents();
        char *predicted = new char[5] {'b', 'a', 'e', 'c', 'f'};
        for (int i = 0; i < 5; ++i)
        {
          REQUIRE(result[i] == predicted[i]);
        }
      }

      THEN("Remove c") {
        REQUIRE(tree->remove(13) == 'c');


        THEN("Size should be 4"){
          REQUIRE(tree->size() == 4);
        }

        THEN("Indexes should match") {
          char *result = tree->contents();
          char *predicted = new char[4] {'b', 'a', 'e', 'f'};
          for (int i = 0; i < 4; ++i)
          {
            REQUIRE(result[i] == predicted[i]);
          }
        }
      }

    }



	}
}
