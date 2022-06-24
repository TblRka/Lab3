#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3\BinSearchTree1.h"
#include "..\Lab3\Complex.h"
#include "..\Lab3\mapdef.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(Tree_test)
	{
	public:

		TEST_METHOD(CreateComplex)
		{
			Complex a(2.0, 3.0);
			Complex b(0.0, 0.0);
			Complex c(a);
			Assert::IsTrue(a.GetRe() == 2.0 && a.GetIm() == 3.0, L"CreateComplex method");
			Assert::IsTrue(b.GetRe() == 0.0 && b.GetIm() == 0.0, L"CreateComplex1 method");
			Assert::IsTrue(c == a, L"CreateComplex1 method");
		}

		TEST_METHOD(CreateTree)
		{
			int arr1[7] = { 1, 2, 3, 0, 0, 0, 0 };
			int arr2[13] = { 1, 2, 3, 0, 0, 4, 0, 0, 5, 6, 0, 0, 0 };
			Tree<int> tree1(arr1, 0);
			Tree<int> tree2(arr2, 0);
			Tree<int> tree3(tree1);
			Assert::IsTrue(tree1.Size() == 3, L"CreateTree method");
			Assert::IsTrue(tree2.Size() == 6, L"CreateTree method");
			Assert::IsTrue(tree3.Size() == 3, L"CreateTree method");

			Complex arr_complex[13] = { Complex(1.1, 1.4), Complex(3.5, 2.9), Complex(2.1, 5.4), Complex(0.0, 0.0),  Complex(0.0, 0.0), Complex(0.0, 0.0),  Complex(0.0, 0.0) };
			Tree<Complex> tree_complex(arr_complex, Complex(0.0, 0.0));
			Assert::IsTrue(tree_complex.Size() == 3, L"CreateTree method");

		}

		TEST_METHOD(MapTree)
		{
			int arr[13] = { 1, 2, 3, 0, 0, 4, 0, 0, 5, 6, 0, 0, 0 };
			int arr_mult[13] = { 2, 4, 6, 0, 0, 8, 0, 0, 10, 12, 0, 0, 0 };
			int arr_plus[13] = { 3, 5, 7, 0, 0, 9, 0, 0, 11, 13, 0, 0, 0 };
			Tree<int> tree(arr, 0);
			Tree<int> tree_mult(arr_mult, 0);
			Tree<int> tree_plus(arr_plus, 0);
			tree.Map(MultByTwo);
			Assert::IsTrue(tree == tree_mult, L"Map method");
			tree.Map(OnePlus);
			Assert::IsTrue(tree == tree_plus, L"Map method");
		}

		TEST_METHOD(GetStr)
		{
			int arr[13] = { 1, 2, 3, 0, 0, 4, 0, 0, 5, 6, 0, 0, 0 };
			Tree<int> tree(arr, 0);
			int* arr1 = tree.GetStr("NLR", 0);
			Tree<int> tree1(arr1, 0);
			Assert::IsTrue(tree == tree1, L"Map method");
		}
	};

	TEST_CLASS(SearchTree_test)
	{
	public:
		TEST_METHOD(CreateSearchTree)
		{
			int arr1[7] = { 1, 2, 3, 0, 0, 0, 0 };
			int arr2[13] = { 1, 2, 3, 0, 0, 4, 0, 0, 5, 6, 0, 0, 0 };
			SearchTree<int> tree1(arr1, 0);
			SearchTree<int> tree2(arr2, 0);
			SearchTree<int> tree3(tree1);
			Assert::IsTrue(tree1.Size() == 3, L"CreateSearchTree method");
			Assert::IsTrue(tree2.Size() == 6, L"CreateSearchTree method");
			Assert::IsTrue(tree3.Size() == 3, L"CreateSearchTree method");

			Complex arr_complex[13] = { Complex(1.1, 1.4), Complex(3.5, 2.9), Complex(2.1, 5.4), Complex(0.0, 0.0),  Complex(0.0, 0.0), Complex(0.0, 0.0),  Complex(0.0, 0.0) };
			SearchTree<Complex> tree_complex(arr_complex, Complex(0.0, 0.0));
			Assert::IsTrue(tree_complex.Size() == 3, L"CreateSearchTree method");
		}

		TEST_METHOD(AddNode)
		{
			int arr[] = { 12, 8, 1, 0, 0, 10, 9, 0, 0, 11, 0, 0, 16, 0, 17, 0, 0 };
			SearchTree<int> searchtree(arr, 0);
			searchtree.AddNode(15);
			Assert::IsTrue(searchtree.Size() == 9, L"AddNode method");
		}

		TEST_METHOD(FindItem)
		{
			int arr[] = { 12, 8, 1, 0, 0, 10, 9, 0, 0, 11, 0, 0, 16, 0, 17, 0, 0 };
			SearchTree<int> searchtree(arr, 0);
			Assert::IsTrue(searchtree.FindItemBool(1) == true, L"AddNode method");
			Assert::IsTrue(searchtree.FindItemBool(15) == false, L"AddNode method");
			Assert::IsTrue(searchtree.FindItemBool(8) == true, L"AddNode method");
		}
		TEST_METHOD(DeleteNode)
		{
			int arr[] = { 12, 8, 1, 0, 0, 10, 9, 0, 0, 11, 0, 0, 16, 0, 17, 0, 0 };
			SearchTree<int> searchtree(arr, 0);
			searchtree.DeleteNode(1);
			Assert::IsTrue(searchtree.FindItemBool(1) == false, L"DeleteNode method");
			Assert::IsTrue(searchtree.Size() == 7, L"DeleteNode method");

		}
	};
}
