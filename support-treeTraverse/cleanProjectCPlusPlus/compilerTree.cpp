#include <iostream>
#include <malloc.h>
using namespace std;

#define  MAX_CHILDREN 4
int my_mem[100];			// ���ڴ桱
int offset;

enum					// ������͡���kind
{
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE
};

enum					// ����������͡���kindkind
{
	IF_STMT = 0,
	WHILE_STMT,
	INPUT_STMT,
	PRINT_STMT,
	COMP_STMT
};

enum					// ���ʽ��������͡���kindkind
{
	TYPE_EXPR = 0,
	OP_EXPR,
	NOT_EXPR,
	ARRAY_EXPR,
	CONST_EXPR,
	ID_EXPR
};

enum					// ������������͡���kindkind
{
	VAR_DECL = 0,
	ARRAY_DECL
};

enum					// ���㡪��op
{
	PLUS = 0,
	MINUS
};
enum
{
	Integer = 0,
};

union NodeAttr {
	int op;				// ���ʽ��㣬����������������ʱ����op�����������
	int vali;				// ���ʽ��㣬�������ʽʱ����vali�������ͳ���ֵ
	char valc;			// �ַ�ֵ

	NodeAttr(void) { op = 0; }		// ���ֹ��캯��
	NodeAttr(int i)	{ op = i; }
	NodeAttr(char c) { valc = c; }
};


struct Node
{
	struct Node *children[MAX_CHILDREN];	// ���ӽ��
	int kind;					// �������
	int kind_kind;				// ������
	NodeAttr attr;				// �������
	int addr;					// ������ڴ�ռ䣨�����±꣩
};



class tree	// �﷨����
{
private:
	Node *root;			// �����

private:
	void recursive_get_addr(Node *t);	// Ϊ��ʱ����������ʽ������洢�ռ�
	void recursive_execute(Node *t);	// ��������ִ��Դ����

public:
	void setRoot(Node* p){root = p;}
	Node *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
		Node *child1 = NULL, Node *child2 = NULL, Node *child3 = NULL, Node *child4 = NULL);					// ����һ����㣬���������ԣ����Ӻ��ӽ��
	void get_addr(void);		// ����ռ��ִ�д���Ľӿ�
	void execute(void);
};

Node * tree::NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
			  Node *child1, Node *child2, Node *child3 , Node *child4)
{
	Node* node = new Node();
	node->kind = kind;
	node->kind_kind = kind_kind;
	node->attr = attr;
	node->children[0] = child1;
	node->children[1] = child2;
	node->children[2] = child3;
	node->children[3] = child4;

	return node;
}

void tree::get_addr(void)
{
	cout << "allocate memory..." << endl;
	offset = 0;
	recursive_get_addr(root);		// �ӿں���ֱ�ӵ���ʵ�ʷ���ռ�ĵݹ麯��
}



void tree::recursive_get_addr(Node *t)
{
	if (t) {		// ��ָ��ʲôҲ����
		if (t->kind == EXPR_NODE) {	// Ϊ���ʽ������洢�ռ�
			t->addr = offset++;
			//cout << t->addr << endl;
		}
		for (int i = 0; i < MAX_CHILDREN; i++)	// �ݹ鴦���������������������
			recursive_get_addr(t->children[i]);
	}
}

void tree::execute(void)
{
	cout << "execute..." << endl;
	recursive_execute(root);				// �ӿں������õݹ麯��
	cout << my_mem[root->addr] << endl;	// ���ڴ�ȡ��ִ�н�������
}

void tree::recursive_execute(Node *t)
{
	if (t) {
		for (int i = 0; i < MAX_CHILDREN; i++)	// �������
			recursive_execute(t->children[i]);
		if (t->kind == EXPR_NODE)			// ���ʽ���
			if (t->kind_kind == OP_EXPR) {		// �������ͱ��ʽ
				if (t->attr.op == PLUS)			// �ӷ����ʽ
					// ���ڴ棨my_mem����ȡ���������ӵ�ֵ�����мӷ������д���ڴ�
					my_mem[t->addr] = my_mem[t->children[0]->addr] + my_mem[t->children[1]->addr]; 
				else if (t->attr.op == MINUS)	// �����Ĵ������Ƽӷ�
					my_mem[t->addr] = my_mem[t->children[0]->addr] - my_mem[t->children[1]->addr];
			}
			else if (t->kind_kind == CONST_EXPR)	// �������ʽ����ֵ����vali�У�������������ڴ���
				my_mem[t->addr] = t->attr.vali;

	}
}

int main(int argc, char *argv[])
{
	tree expr;
	Node *p, *q, *r;

	// �������9
	p = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(9), Integer);
	// �������5
	q = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(5), Integer);
	// ����������㣬���ӽ��Ϊ9��5
	r = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(PLUS), Integer, p, q);
	//q = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(2), Integer);
    //p = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(PLUS), Integer, r, q);
	expr.setRoot(r);
	expr.get_addr();	// Ϊ���ӣ����ʽ���ǣ�����洢�ռ�
	expr.execute();	// ִ�д���
}

