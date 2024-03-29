// Copyright 2018 Hanpil Kang

#include <cstdio>
#include <cstring>

#include "node.h"
#include "typing_machine.h"
#include "getch.h"

#include "node_test.h"
#include "typing_machine_test.h"

const char full_board[5][34] = {
  "+-------+   +-------+   +-------+",
  "|       |   |       |   |       |",
  "|  ' '  |<--+  ' '  +-->|  ' '  |",
  "|       |   |       |   |       |",
  "+-------+   +-------+   +-------+"
};

const char empty_board[5][34] = {
  "            +-------+            ",
  "            |       |            ",
  "            |  ' '  |            ",
  "            |       |            ",
  "            +-------+            "
};


void printNode(Node* node) {
  if (!node) {
    return;
  }
  char print_board[5][34];
  memcpy(print_board, full_board, sizeof print_board);
  Node* prev = node->GetPreviousNode();
  Node* next = node->GetNextNode();

  if (!prev) {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 13; ++j)
        print_board[i][j] = empty_board[i][j];
  } else {
    print_board[2][4] = prev->GetData();
  }
  if (!next) {
    for (int i = 0; i < 5; ++i)
      for (int j = 20; j < 33; ++j)
        print_board[i][j] = empty_board[i][j];
  } else {
    print_board[2][28] = next->GetData();
  }
  print_board[2][16] = node->GetData();

  for (int i = 0; i < 5; ++i)
    puts(print_board[i]);
  return;
}

void TestNode() {
  Node* node = new Node(' ');
  while (true) {
    printNode(node);
    puts("Usage: ");
    puts("Browse with left and right Arrow.");
    puts("Insert with [ and ] key.");
    puts("Erase with , and . key.");
    puts("");
    int user_key = GetKeyInput();
    switch (user_key) {
      case '1': {
        if (node->GetPreviousNode()) {
          node = node->GetPreviousNode();
        }
        break;
      }
      case '2': {
        if (node->GetNextNode()) {
          node = node->GetNextNode();
        }
        break;
      }
      case '[': {
        user_key = GetKeyInput();
        if (32 <= user_key && user_key <= 126) {
          node->InsertPreviousNode(user_key);
        }
        break;
      }
      case ']': {
        user_key = GetKeyInput();
        if (32 <= user_key && user_key <= 126) {
          node->InsertNextNode(user_key);
        }
        break;
      }
      case ',': {
        node->ErasePreviousNode();
        break;
      }
      case '.': {
        node->EraseNextNode();
        break;
      }
      default: {
        // ignore
        break;
      }
    }
  }
}

void TestTypingMachine() {
  TypingMachine tape;
  while (true) {
    puts(tape.Print('|').c_str());
    int user_key = GetKeyInput();
    switch (user_key) {
      case '1': { 
        tape.LeftKey();
        break;
      }
      case '2': {
        tape.RightKey(); 
        break;
      }
      case '3': {
        tape.HomeKey();
        break;
      }
      case '4': {
        tape.EndKey();
        break;
      }
      case '5': {
        tape.EraseKey();
        break;
      }
      default: {
        tape.TypeKey(user_key);
        break;
      }
    }
  }
}

int main() {
  puts("1: Test Node.");
  puts("2: Test Typing Machine.");
  puts("3: Run Unit Test Node.");
  puts("4: Run Unit Test Typing Machine.");

  while (true) {
    int user_key = GetKeyInput();
    if (user_key == '1') {
      TestNode();
      return 0;
    }
    if (user_key == '2') {
      TestTypingMachine();
      return 0;
    }
	if (user_key == '3') {
		NodeTest();
		return 0;
	}
	if (user_key == '4') {
		TypingMachineTest();
		return 0;
	}
  }
}









