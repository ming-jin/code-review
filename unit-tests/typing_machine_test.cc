// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	ASSERT_EQ(tm.Print(' '), std::string(" "));
	ASSERT_EQ(tm.Print(0), std::string(""));
  }
public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};

class TmKeyNavigationTestSuite
{
private:
	static void NormalStringNavigationTest() {
		TypingMachine tm;
		tm.TypeKey('A');
		tm.TypeKey('B');
		tm.TypeKey('C');
		ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("AB|C"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("A|BC"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("AB|C"));
	}
	static void EmptyStringNavigationTest() {
		TypingMachine tm;
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
	static void TypeKeyBoundaryTest() {
		TypingMachine tm;
		tm.TypeKey(' ');
		ASSERT_EQ(tm.Print('|'), std::string(" |"));
		tm.EraseKey();
		tm.TypeKey('~');
		ASSERT_EQ(tm.Print('|'), std::string("~|"));
		tm.EraseKey();
		tm.TypeKey('!');
		ASSERT_EQ(tm.Print('|'), std::string("!|"));
		tm.EraseKey();
		tm.TypeKey('}');
		ASSERT_EQ(tm.Print('|'), std::string("}|"));
		tm.EraseKey();
		char small_char = (char)31;
		char big_char = (char)127;
		ASSERT_FALSE(tm.TypeKey(small_char));
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		ASSERT_FALSE(tm.TypeKey(big_char));
		ASSERT_EQ(tm.Print('|'), std::string("|"));

		for (int i = 0; i < 100; i++) tm.TypeKey('0');
		ASSERT_EQ(tm.Print('|'), std::string("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000|"));
		for (int i = 0; i < 100; i++) tm.EraseKey();

		for (int i = 0; i < 99; i++) tm.TypeKey('0');
		ASSERT_EQ(tm.Print('|'), std::string("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000|"));
		for (int i = 0; i < 99; i++) tm.EraseKey();

		for (int i = 0; i < 101; i++) tm.TypeKey('0');
		ASSERT_EQ(tm.Print('|'), std::string("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000|"));
		for (int i = 0; i < 100; i++) tm.EraseKey();
	}
	static void EraseKeyTest() {
		TypingMachine tm;
		tm.TypeKey('A');
		tm.TypeKey('B');
		ASSERT_EQ(tm.Print('|'), std::string("AB|"));
		ASSERT_TRUE(tm.EraseKey());
		ASSERT_EQ(tm.Print('|'), std::string("A|"));
		ASSERT_TRUE(tm.EraseKey());
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		ASSERT_FALSE(tm.EraseKey());
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
public:
  static void RunTest() {
	  NormalStringNavigationTest();
	  EmptyStringNavigationTest();
	  TypeKeyBoundaryTest();
	  EraseKeyTest();
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmKeyNavigationTestSuite::RunTest();
  // add more..
}