#include "stdafx.h"
#include "CppUnitTest.h"
#include "../App2_lab/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ListPushBackTest)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_back(8);
			Assert::AreEqual(lst->at(4), 8);
			lst->clear();

		}
		TEST_METHOD(ListPushBackTestListZeroElements)
		{
			List *lst = new List();
			lst->push_back(1);
			Assert::AreEqual(lst->at(1), 1);
			lst->clear();

		}

		TEST_METHOD(ListPushFront)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			Assert::AreEqual(lst->at(1), 8);
			lst->clear();

		}
		TEST_METHOD(ListPushFrontTestListZeroElements)
		{
			List *lst = new List();
			lst->push_front(1);
			Assert::AreEqual(lst->at(1), 1);
			lst->clear();

		}

		TEST_METHOD(ListPopBack)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->pop_back();
			lst->pop_back();
			Assert::AreEqual(lst->at(2), 1);
			Assert::AreEqual(lst->at(1), 8);
			lst->clear();

		}
		TEST_METHOD(ListPopBackOneElement)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->pop_back();
			Assert::AreEqual(lst->get_size(), 0);
			lst->clear();

		}
		//на 1 элемент

		TEST_METHOD(ListPopBackTestNoElements)
		{
			List *lst = new List();
			try {
				lst->pop_back();
			}
			catch (out_of_range) {

			}
			lst->clear();


		}

		TEST_METHOD(ListPopFront)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->pop_front();
			lst->pop_front();
			Assert::AreEqual(lst->at(2), 1);
			Assert::AreEqual(lst->at(1), 3);
			lst->clear();

		}
		TEST_METHOD(ListPopFrontOneElement)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->pop_front();
			Assert::AreEqual(lst->get_size(), 0);
			lst->clear();

		}

		TEST_METHOD(ListPopFrontNoElements)
		{
			List *lst = new List();
			try {
				lst->pop_front();
			}
			catch (out_of_range) {

			}
			lst->clear();

		}

		TEST_METHOD(ListInsert)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->insert(77, 3);
			Assert::AreEqual(lst->at(3), 77);
			lst->clear();

		}
		TEST_METHOD(ListInsertInFirst)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->insert(77, 1);
			Assert::AreEqual(lst->at(1), 77);
			lst->clear();

		}
		TEST_METHOD(ListInsertInLast)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->insert(77, 4);
			Assert::AreEqual(lst->at(4), 77);
			lst->clear();

		}

		TEST_METHOD(ListInsertIncorrectIndexOne)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(1);
			lst->insert(101, 12);
			Assert::AreEqual(lst->at(3), 101);
			lst->clear();


		}

		TEST_METHOD(ListInsertIncorrectIndexTwo)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(1);
			lst->insert(101, -2);
			Assert::AreEqual(lst->at(1), 101);
			lst->clear();


		}

		TEST_METHOD(ListDeleteElem)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->delete_elem(2);
			lst->delete_elem(3);
			Assert::AreEqual(lst->at(1), 8);
			lst->clear();

		}
		TEST_METHOD(ListDeleteElemLast)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->delete_elem(2);
			Assert::AreEqual(lst->at(1), 3);
			lst->clear();

		}
		TEST_METHOD(ListDeleteElemFirst)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(4);
			lst->delete_elem(1);
			Assert::AreEqual(lst->at(1), 3);
			lst->clear();

		}

		TEST_METHOD(ListDeleteElemIncorrectIndexOne)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			try {
				lst->delete_elem(1000);
				lst->delete_elem(875);
			}
			catch (out_of_range) {

			}
			//Assert::AreEqual(lst->at(1), 8);
			lst->clear();

		}

		TEST_METHOD(ListDeleteElemIncorrectIndexTwo)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			try {
				lst->delete_elem(-3);
				lst->delete_elem(111);
			}
			catch (out_of_range) {

			}
			//Assert::AreEqual(lst->at(1), 8);
			lst->clear();

		}

		TEST_METHOD(ListInsert_2)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->push_back(2);
			lst->push_back(2);
			lst->insert(77, 3);
			Assert::AreEqual(lst->get_size(), 7);
			lst->clear();

		}

		TEST_METHOD(ListClear)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(3);
			lst->push_front(1);
			lst->push_front(8);
			lst->push_back(2);
			lst->push_back(2);
			lst->insert(77, 3);
			lst->clear();
			Assert::AreEqual(lst->get_size(), 0);



		}

		TEST_METHOD(ListSet)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(8);
			lst->push_front(11);
			lst->push_front(88);
			lst->insert(77, 3);
			lst->set(3, 9);
			Assert::AreEqual(lst->at(3), 9);
			lst->clear();


		}

		TEST_METHOD(ListSetOutOfRangeOne)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(8);
			lst->push_front(11);
			lst->push_front(88);
			lst->insert(77, 3);
			try {
				lst->set(11, 9);
			}
			catch (out_of_range) {

			}
			lst->clear();



		}

		TEST_METHOD(ListSetOutOfRangeTwo)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(8);
			lst->push_front(11);
			lst->push_front(88);
			lst->insert(77, 3);
			try {
				lst->set(-2, 9);
			}
			catch (out_of_range) {

			}
			lst->clear();



		}
		TEST_METHOD(ListSetLast)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(8);
			lst->push_front(11);
			lst->push_front(88);
			lst->set(4, 55);
			Assert::AreEqual(lst->at(4), 55);
			lst->clear();

		}
		TEST_METHOD(ListSetFirst)
		{
			List *lst = new List();
			lst->push_front(1);
			lst->push_front(8);
			lst->push_front(11);
			lst->push_front(88);
			lst->set(1, -3);
			Assert::AreEqual(lst->at(1), -3);
			lst->clear();

		}

		TEST_METHOD(ListIsEmpty)
		{
			List *lst = new List();


			Assert::AreEqual(int(lst->isEmpty()), 0);

			lst->clear();

		}


		TEST_METHOD(ListFindLastElementBorder)
		{
			List *lst = new List();
			List *lst2 = new List();
			lst->push_front(6);
			lst->push_front(4);
			lst->push_front(6);



			lst2->push_front(6);
			lst2->push_front(4);
			lst2->push_front(6);
			int  result = lst->find_last(lst2);
			Assert::AreEqual(result, 1);
			lst->clear();
			lst2->clear();



		}


	};
}