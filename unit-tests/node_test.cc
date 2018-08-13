// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

  static void PreviousNodeTest() {
	  Node *node = new Node('A');
	  ASSERT_FALSE(node->GetPreviousNode());
	  delete node;
  }

  static void NextNodeTest() {
	  Node *node = new Node('A');
	  ASSERT_FALSE(node->GetNextNode());
	  delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
	PreviousNodeTest();
	NextNodeTest();
    // add more..
  }
};

class NodeInsertionTestSuite
{
private:
	static void InsertPreviousNodeAtHeadTest() {
		Node* node = new Node('A');
		node->InsertPreviousNode('B');
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'B');
		delete node->GetPreviousNode();
		delete node;
	}
	static void InsertPreviousNodeInTheMiddleTest() {
		Node* node = new Node('A');
		node->InsertPreviousNode('C');
		node->InsertPreviousNode('B');
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'B');
		ASSERT_EQ(node->GetPreviousNode()->GetPreviousNode()->GetData(), 'C');
		ASSERT_EQ(node->GetPreviousNode()->GetNextNode()->GetData(), 'A');
		ASSERT_EQ(node->GetPreviousNode()->GetPreviousNode()->GetNextNode()->GetData(), 'B');
		delete node->GetPreviousNode()->GetPreviousNode();
		delete node->GetPreviousNode();
		delete node;
	}
	static void InsertNextNodeAtTailTest() {
		Node* node = new Node('A');
		node->InsertNextNode('B');
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetNextNode()->GetData(), 'B');
		delete node->GetNextNode();
		delete node;
	}
	static void InsertNextNodeInTheMiddleTest() {
		Node* node = new Node('A');
		node->InsertNextNode('C');
		node->InsertNextNode('B');
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetNextNode()->GetData(), 'B');
		ASSERT_EQ(node->GetNextNode()->GetNextNode()->GetData(), 'C');
		ASSERT_EQ(node->GetNextNode()->GetPreviousNode()->GetData(), 'A');
		ASSERT_EQ(node->GetNextNode()->GetNextNode()->GetPreviousNode()->GetData(), 'B');
		delete node->GetNextNode()->GetNextNode();
		delete node->GetNextNode();
		delete node;
	}
public:
  static void RunTest() {
	  InsertPreviousNodeAtHeadTest();
	  InsertPreviousNodeInTheMiddleTest();
	  InsertNextNodeAtTailTest();
	  InsertNextNodeInTheMiddleTest();
    // add more..
  }
};

class NodeRemovalTestSuite
{
private:
	static void ErasePreviousNodeAtHeadTest() {
		Node* node = new Node('A');
		ASSERT_FALSE(node->ErasePreviousNode());
		delete node;
	}
	static void ErasePreviousNodeAtHeadNextTest() {
		Node* node = new Node('A');
		node->InsertPreviousNode('B');
		ASSERT_TRUE(node->ErasePreviousNode());
		ASSERT_FALSE(node->GetPreviousNode());
		ASSERT_EQ(node->GetData(), 'A');
		delete node;
	}
	static void ErasePreviousNodeInTheMiddleTest() {
		Node* node = new Node('A');
		node->InsertPreviousNode('C');
		node->InsertPreviousNode('B');
		ASSERT_TRUE(node->ErasePreviousNode());
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), 'C');
		ASSERT_EQ(node->GetPreviousNode()->GetNextNode()->GetData(), 'A');
		delete node->GetPreviousNode();
		delete node;
	}
	static void EraseNextNodeAtTailTest() {
		Node* node = new Node('A');
		ASSERT_FALSE(node->EraseNextNode());
		delete node;
	}
	static void EraseNextNodeAtTailPreviousTest() {
		Node* node = new Node('A');
		node->InsertNextNode('B');
		ASSERT_TRUE(node->EraseNextNode());
		ASSERT_FALSE(node->GetNextNode());
		ASSERT_EQ(node->GetData(), 'A');
		delete node;
	}
	static void EraseNextNodeInTheMiddleTest() {
		Node* node = new Node('A');
		node->InsertNextNode('C');
		node->InsertNextNode('B');
		ASSERT_TRUE(node->EraseNextNode());
		ASSERT_EQ(node->GetData(), 'A');
		ASSERT_EQ(node->GetNextNode()->GetData(), 'C');
		ASSERT_EQ(node->GetNextNode()->GetPreviousNode()->GetData(), 'A');
		delete node->GetNextNode();
		delete node;
	}
public:
	static void RunTest() {
		ErasePreviousNodeAtHeadTest();
		ErasePreviousNodeAtHeadNextTest();
		ErasePreviousNodeInTheMiddleTest();
		EraseNextNodeAtTailTest();
		EraseNextNodeAtTailPreviousTest();
		EraseNextNodeInTheMiddleTest();
		// add more..
	}
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  NodeInsertionTestSuite::RunTest();
  NodeRemovalTestSuite::RunTest();
  // add more..
}