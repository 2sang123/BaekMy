#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;

struct node
{
	char val;
	node* left;
	node* right;
	node(char x) : val(x), left(nullptr), right(nullptr){}

};

unordered_map<int, node*> nodes;

node* buildTree()
{
	char p, left, right;
	node* root = nullptr;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> left >> right;
		if (nodes[p] == nullptr) nodes[p] = new node(p);

		if (i == 0) root = nodes[p];

		if (left != '.') {
			if (nodes[left] == nullptr)
				nodes[left] = new node(left);
			nodes[p]->left = nodes[left];
		}

		if (right != '.') {
			if (nodes[right] == nullptr)
				nodes[right] = new node(right);
			nodes[p]->right = nodes[right];
		}
	}
	return root;
}
void preorder(node* nd) {
	if (nd == nullptr) return;
	cout << nd->val;
	preorder(nd->left);
	preorder(nd->right);
}

void inorder(node* nd)
{
	if (nd == nullptr) return;
	inorder(nd->left);
	cout << nd->val;
	inorder(nd->right);
}

void postorder(node* nd) {
	if (nd == nullptr) return;
	postorder(nd->left);
	postorder(nd->right);
	cout << nd->val;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;
	node* root = buildTree();
	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
	
}
