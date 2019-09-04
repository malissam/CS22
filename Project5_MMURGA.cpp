// Project5_MMURGA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "binarytree.h"
#include "binarySearchTree.h"
using namespace std;

int main()
{
	bSearchTreeType<int>  treeRoot;
	int num;

	cout << "Enter integers ending with -999" << endl;
	cin >> num;
	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << "Number of Single Parent nodes: " << 
	treeRoot.singleParent();
	cout << endl;

	
	

	system("pause");
    return 0;
}

