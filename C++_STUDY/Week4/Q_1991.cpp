#include <stdio.h>
#include <vector>
using std::vector;

struct tree {
	char c;	// 해당 노드값
	tree* left = NULL;
	tree* right = NULL;
};

void makeNode(vector<tree>& node, int N) {
	char parent, left, right;

	for (int i = 0; i < N; i++) {

		scanf_s("%c %c %c", &parent, 1, &left, 1, &right, 1);
		rewind(stdin);
		node[parent - 'A'].c = parent;

		if (left != '.') {
			node[parent - 'A'].left = &node[left - 'A'];
		}
		if (right != '.') {
			node[parent - 'A'].right = &node[right - 'A'];
		}
	}
}

void preorder(tree* root) {
	printf("%c", root->c);

	if (root->left != NULL) {
		preorder(root->left);
	}
	if (root->right != NULL) {
		preorder(root->right);
	}
}

void inorder(tree* root) {
	if (root->left != NULL) {
		inorder(root->left);
	}
	printf("%c", root->c);
	if (root->right != NULL) {
		inorder(root->right);
	}
}

void postorder(tree* root) {
	if (root->left != NULL) {
		postorder(root->left);
	}
	if (root->right != NULL) {
		postorder(root->right);
	}
	printf("%c", root->c);
}

int main() {
	int N;
	tree* root;

	scanf_s("%d", &N);
	rewind(stdin);

	vector<tree> node(N + 2);	// 'A' = node[0], 'B' = node[1] ...
	makeNode(node, N);
	root = &node[0];

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

	return 0;
}