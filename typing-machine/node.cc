// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	nodeData = data;
	previousNode = nullptr;
	nextNode = nullptr;
  return;
}

char Node::GetData() {
  return nodeData;
}

Node* Node::GetPreviousNode() {
  return previousNode;
}

Node* Node::GetNextNode() {
  return nextNode;
}

Node* Node::InsertPreviousNode(char data) {
	Node* newNode = new Node(data);
	
	if (previousNode == nullptr) {
		previousNode = newNode;
		newNode->nextNode = this;
	}
	else {
		previousNode->nextNode = newNode;
		newNode->previousNode = previousNode;

		previousNode = newNode;
		newNode->nextNode = this;
	}

  return newNode;
}

Node* Node::InsertNextNode(char data) {
	Node* newNode = new Node(data);

	if (nextNode == nullptr) {
		nextNode = newNode;
		newNode->previousNode = this;
	}
	else {
		nextNode->previousNode = newNode;
		newNode->nextNode = nextNode;

		nextNode = newNode;
		newNode->previousNode = this;
	}

  return newNode;
}

bool Node::ErasePreviousNode() {
	if (previousNode != nullptr) {
		Node* tempNode = previousNode;
		if (previousNode->previousNode != nullptr) {
			previousNode->previousNode->nextNode = this;
			previousNode = previousNode->previousNode;
		}
		else {
			previousNode = nullptr;
		}
		delete tempNode;
		return true;
	}
	else {
		return false;
	}
}

bool Node::EraseNextNode() {
	if (nextNode != nullptr) {
		Node* tempNode = nextNode;
		if (nextNode->nextNode != nullptr) {
			nextNode->nextNode->previousNode = this;
			nextNode = nextNode->nextNode;
		}
		else {
			nextNode = nullptr;
		}
		delete tempNode;
		return true;
	}
	else {
		return false;
	}
}
