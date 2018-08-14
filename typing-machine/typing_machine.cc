// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	tailNode = new Node(0);
	keyNode = headerNode = cursorNode = tailNode;
	typedStringLength = 0;
	return;
}

void TypingMachine::HomeKey() {
	cursorNode = headerNode;
	return;
}

void TypingMachine::EndKey() {
	cursorNode = tailNode;
	return;
}

void TypingMachine::LeftKey() {
	if (cursorNode->GetPreviousNode()) {
		cursorNode = cursorNode->GetPreviousNode();
	}
  return;
}

void TypingMachine::RightKey() {
	if (cursorNode->GetNextNode()) {
		cursorNode = cursorNode->GetNextNode();
	}
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (typedStringLength >= 100) return false;

	if (key >= 32 && key <= 126) {
		cursorNode->InsertPreviousNode(key);
		Node* newlyAddedNode = cursorNode->GetPreviousNode();
		if (!newlyAddedNode->GetPreviousNode()) {
			headerNode = newlyAddedNode;
		}
		typedStringLength++;
		return true;
	}
	else {
		return false;
	}
}

bool TypingMachine::EraseKey() {
	if (cursorNode->GetPreviousNode()) {
		cursorNode->ErasePreviousNode();
		if (!cursorNode->GetPreviousNode()) {
			headerNode = cursorNode;
		}
		typedStringLength--;
		return true;
	}
	else {
		return false;
	}
}

std::string TypingMachine::Print(char separator) {
	std::string typedString("");

	if (separator != 0) {
		typedString += separator;
	}

	Node* iteratorNode = cursorNode;
	while ((iteratorNode = iteratorNode->GetPreviousNode())) {
		typedString = iteratorNode->GetData() + typedString;
	}

	iteratorNode = cursorNode;
	while (iteratorNode->GetData() != 0) {
		typedString = typedString + iteratorNode->GetData();
		iteratorNode = iteratorNode->GetNextNode();
	}

	return typedString; 
}
