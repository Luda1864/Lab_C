// �������(�).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;
struct node {
	int info;
	node* left, *right;
};
//�������� ������
void createtree(node** tree) {
	*tree = NULL;
}
//�������� �� �������
void isEmpty(node** tree) {
	if ((*tree) == NULL) cout << "������ ������ \n";
	else cout << "������ �� ������ \n";
}
//���������� ��
void push(int a, node** tree) {
	if ((*tree) == NULL) {
		(*tree) = new node;
		(*tree)->info = a;
		(*tree)->left = (*tree)->right = NULL;
		return;
	}
	if (a > (*tree)->info) push(a, &(*tree)->right);
	else push(a, &(*tree)->left);
}
//�������� ������
void delet(node *tree, node** trees) {
	if (tree != NULL) {
		delet(tree->left, trees);
		delet(tree->right, trees);
		delete tree;
		*trees = NULL;
	}

}
//������� �������
node* DeleteElem(node* tree, int val) {
	if (tree == NULL) return tree;
	if (val == tree->info) {
		node* tmp;
		if (tree->right == NULL)
			tmp = tree->left;
		else {
			node* ptr = tree->right;
			if (ptr->left == NULL) {
				ptr->left = tree->left;
				tmp = ptr;
			}
			else {
				node* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = tree->left;
				pmin->right = tree->right;
				tmp = pmin;
			}
		}
		delete tree;
		return tmp;
	}
	else if (val < tree->info) tree->left = DeleteElem(tree->left, val);
	else tree->right = DeleteElem(tree->right, val);
	return tree;
}
//����� �� �����
void print(node* tree, int u) {
	if (tree == NULL) return;
	else {
		print(tree->left, ++u);
		for (int i = 0; i < u; ++i) cout << "\t";
		cout << tree->info << endl;
		u--;
	}
	print(tree->right, ++u);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, s, u = 0, count = 0;
	node* tree = NULL;
	while (1) {
		cout << "1 - ������� ������\n";
	cout << "2 - �������� ������� � ������\n";
	cout << "3 - ������� �� ������\n";
	cout << "4 - ��������� ������ �� ������\n";
	cout << "5 - ������� ������ \n";
	cout << "6 - ������� ������� ������ \n";
	cout << "0 - ����� \n";
	cout << "\n������� ������ �����: ";
	cin >> n;
		switch (n) {
		case 1: {
			createtree(&tree);
			cout << "������ ������� \n";
			system("pause");
			system("cls"); //�������� ������ �������
			break;
		}
		case 2: {
			cout << "������� ����� ";
			cin >> s;
			push(s, &tree);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "���� ������:\n";
			print(tree, 0);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			isEmpty(&tree);
			system("pause");
			system("cls");
			break; 
		}
		
	
		case 5: {
			delet(tree, &tree);
			cout << "������ ������� \n";
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "������� ������� ������� ����� �������\n";
			cin >> s;
			DeleteElem(tree, s);
			system("pause");
			system("cls");
			break;
		}
		
		}
		}
	}
