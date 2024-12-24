using namespace std;
#include <iostream>
struct Node {
	string data;
	Node* next;
	Node* prev;
	Node() :data("non fine "), next(nullptr), prev(nullptr) {}
	Node(string value, Node* next, Node* prev) : data(value), next(next), prev(prev) {}
	void show(Node*  sd) {
		Node* curent = sd;
		int n = 0;
		while (curent !=nullptr)
		{
			cout <<++n<<"." << curent->data << " ";
			curent = curent->next;
		}
	}
};
struct TreeNode
{
	int number;
	Node* fine;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data,string value) : number(data), left(nullptr), right(nullptr){
		
		fine = new Node(value, nullptr, nullptr);
	}
	void shows() {
		fine->show(fine);
	}

};
class Binar {
	TreeNode* root;
	Node* head;
	TreeNode* insertNode(TreeNode* node, int value ,string sd)
	{
		if (node == nullptr)
		{
			return new TreeNode(value,sd);
		}
		if (value < node->number)
		{
			node->left = insertNode(node->left, value,sd);
		}
		else if (value > node->number)
		{
			node->right = insertNode(node->right, value,sd);
		}
		return node;
	}
	void preorderShow(TreeNode* node)
	{
		if (node != nullptr)
		{
			cout <<"numer transporta:" << node->number << " ";
			cout << "shtrafi:"<< " ";
			node->fine->show(node->fine);
			cout << endl;
			preorderShow(node->left);
			preorderShow(node->right);
		}
	}
	bool search(TreeNode* node,int number)
	{
	
		if (node == nullptr)
		{
			return false;
		}
		if (node->number == number)
		{
			return true;
		}
		else if (number < node->number)
		{
			return search(node->left, number);
		}
		else {
			return search(node->right, number);
		}
	}
	int  replacement(TreeNode* node, int num,string zamina)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->number == num)
		{
			node->fine->prev = new Node(zamina, node->fine, nullptr);
			node->fine = node->fine->prev;
			
		}
		else if (num < node->number)
		{
			return replacement(node->left, num,  zamina);
		}
		else {
			return replacement(node->right, num, zamina);
		}
	}
	void clear(TreeNode* node)
	{

	}
	int drouk(TreeNode* node,int num)
	{
		if (node == nullptr)
		{
			cout << "not" << endl;
		}
		if (node->number == num)
		{
			cout << "numer transporta:" << node->number << " ";
			cout << "shtrafi:" << " ";
			node->fine->show(node->fine);
			cout << endl;

		}
		else if (num < node->number)
		{
			return drouk(node->left, num);
		}
		else {
			return drouk(node->right, num);
		}
	}
	void addd(TreeNode* node , int num,string shtraf)
	{
		if (search(node, num))
		{
			replacement(node, num, shtraf);
			

			
		}
		else
		{
			cout << "no number" << endl;
		}
	}
	void dia(TreeNode* node, int start, int end)
	{
		int count = 0;
		if (node == nullptr)
		{
		
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				if (node->number == i)
				{
					
					cout << "numer transporta:" << node->number << " ";
					cout << "shtrafi:" << " ";
					node->fine->show(node->fine);
					cout << endl;

				}

			}
			if (count == 0)
			{
				dia(node->left, start, end);
				dia(node->right, start, end);

			}
		}
		
	
	}
public:
	Binar() :root(nullptr) {}

	void preorder()
	{
		preorderShow(root);
		cout << endl;
	};

	void del()
	{

	}
	void diapason(int start,int end)
	{
		dia(root, start, end);
	}
	void sel(int num)
	{
		drouk(root, num);
	}
	void add(int number,string shtraf)
	{
		addd(root, number, shtraf);
	}
	void show() 
	{
		preorderShow(root);
	};
	void insert(int value,string fail)
	{
		root = insertNode(root, value, fail);
	};
};
int main()
{
	Binar sd;
	sd.insert(1222, "134uk vor v zakoni");
	sd.insert(2334, "154uk pianstvo");
	sd.add(2334, "grav v footboll");
	sd.show();
	sd.sel(1222);
	cout << endl;
	sd.diapason(0, 2400);
}

