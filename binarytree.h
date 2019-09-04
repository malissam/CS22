#ifndef BINARYTREE_H
#define BINARYTREE_H


template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
};

//def of class 
template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&)
	{
		if (this != &otherTree)
		{
			if (root != nullptr)

				destroy(root);

			if (otherTree.root == nullptr)
				root = nullptr;
			else
				copyTree(root, otherTree.root);
		}//end else

		return *this;
	}
	bool isEmpty() const
	{
		return (root == nullptr);
	}

	void inorderTraversal() const
	{
		inorder(root);
	}

	void preorderTraversal() const
	{
		preorder(root);
	}

	void postorderTraversal() const
	{
		postorder(root);
	}

	int treeHeight() const
	{
		return height(root);
	}

	int treeNodeCount() const
	{
		return nodeCount(root);
	}

	int treeLeavesCount() const
	{
		return leavesCount(root);
	}

	void destroyTree()
	{
		destroy(root);
	}
	int singleParent() 
	{
		return singlePar(root);
	}

	bool search(const elemType& searchItem) const
	{
		nodeType<elemType> *current;
		bool found = false;

		if (root == nullptr)
			cout << "Cannot search an empty tree." << endl;
		else
		{
			current = root;

			while (current != nullptr && !found)
			{
				if (current->info == searchItem)
					found = true;
				else if (current->info > searchItem)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while
		}//end else
		return found;
	}//end search



	void insert(const elemType& insertItem)
	{
		nodeType<elemType> *current; //traverse the tree
		nodeType<elemType> *trailCurrent; //behind current
		nodeType<elemType> *newNode;  //create the node

		trailCurrent = NULL;

		newNode = new nodeType<elemType>;
		newNode->info = insertItem;
		newNode->lLink = nullptr;
		newNode->rLink = nullptr;

		if (root == nullptr)
			root = newNode;
		else
		{
			current = root;

			while (current != nullptr)
			{
				trailCurrent = current;

				if (current->info == insertItem)
				{
					cout << "The item to be inserted is already ";
					cout << "in the tree -- duplicates are not allowed." << endl;
					return;
				}
				else if (current->info > insertItem)
				{
					current = current->lLink;
				}
				else
				{
					current = current->rLink;
				}
				
			}//end while

			if (trailCurrent->info > insertItem)
			{
				trailCurrent->lLink = newNode;
			}
			else
			{
				trailCurrent->rLink = newNode;
			}
		}
	}//end insert

	void deleteNode(const elemType& deleteItem)
	{
		nodeType<elemType> *current; //traverse the tree
		nodeType<elemType> *trailCurrent; //behind current
		bool found = false;

		if (root == nullptr)
		{
			cout << "Cannot delete from an empty tree." << endl;
		}
		else
		{
			current = root;
			trailCurrent = root;

			while (current != nullptr && !found)
			{
				if (current->info == deleteItem)
					found = true;
				else
				{
					trailCurrent = current;

					if (current->info > deleteItem)
					{
						current = current->lLink;
					}
					else
					{
						current = current->rLink;
					}
				}
			}//end while

			if (current == nullptr)
			{
				cout << "The item to be deleted is not in the tree." << endl;
			}
			else if (found)
			{
				if (current == root)
					deleteFromTree(root);
				else if (trailCurrent->info > deleteItem)
					deleteFromTree(trailCurrent->lLink);
				else
					deleteFromTree(trailCurrent->rLink);
			}
			else
			{
				cout << "The item to be deleted is not in the tree." << endl;
			}
		}
	} //end deleteNode

	binaryTreeType(const binaryTreeType<elemType>& otherTree)
	{
		if (otherTree.root == nullptr) //otherTree is empty
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}
	binaryTreeType()
	{
		root = nullptr;
	}

	~binaryTreeType()
	{
		destroy(root);
	}
	void displayRoot()
	{
		cout << "Root value is: " << root->info << endl;
	}

protected: nodeType<elemType> *root;
private :
		void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
		{
			if (otherTreeRoot == nullptr)
			{
				copiedTreeRoot = nullptr;
			}
			else
			{
				copiedTreeRoot = new nodeType<elemType>;
				copiedTreeRoot->info = otherTreeRoot->info;
				copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
				copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
			}
		} //end copyTree

		void destroy(nodeType<elemType>* &p)
		{
			if (p != nullptr)
			{
				destroy(p->lLink);
				destroy(p->rLink);
				delete p;
				p = nullptr;
			}
		}

			
	
		int singlePar(nodeType<elemType>*p)
		{
			if (p == NULL)
				return 0;
			else if (p->lLink == NULL && p->rLink != NULL)
				return 1 + singlePar(p -> rLink);
			else if (p->lLink != NULL && p->rLink == NULL)
			return (1 + singlePar(p -> lLink));
			else
				return (singlePar(p->lLink) + singlePar(p -> rLink));
		}
};

#endif
