// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
private:
	Node* keyNode;
	Node* headerNode;
	Node* tailNode;
	Node* cursorNode;
	int typedStringLength;
};

#endif  // TYPING_MACHINE_H_
