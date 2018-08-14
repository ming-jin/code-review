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
	
	if (previousNode != nullptr) {
		previousNode->nextNode = newNode;
		newNode->previousNode = previousNode;
	}

	previousNode = newNode;
	newNode->nextNode = this;

	return newNode;
}

Node* Node::InsertNextNode(char data) {
	Node* newNode = new Node(data);

	if (nextNode != nullptr) {
		nextNode->previousNode = newNode;
		newNode->nextNode = nextNode;
	}

	nextNode = newNode;
	newNode->previousNode = this;

	return newNode;
}

bool Node::ErasePreviousNode() {
	if (previousNode != nullptr) {
		Node* originalPreviousNode = previousNode;
		Node* prePreviousNode = previousNode->previousNode;
		if (prePreviousNode != nullptr) {
			prePreviousNode->nextNode = this;
		}
		previousNode = prePreviousNode;
		delete originalPreviousNode;
		return true;
	}
	else {
		return false;
	}
}

bool Node::EraseNextNode() {
	if (nextNode != nullptr) {
		Node* originalNextNode = nextNode;
		Node* nexNextNode = nextNode->nextNode;
		if (nexNextNode != nullptr) {
			nexNextNode->previousNode = this;
		}
		nextNode = nexNextNode;
		delete originalNextNode;
		return true;
	}
	else {
		return false;
	}
}
