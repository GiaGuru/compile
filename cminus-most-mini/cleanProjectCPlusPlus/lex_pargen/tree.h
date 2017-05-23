#ifndef __TREE__H__
#define __TREE__H__

#include <iostream>
#include <malloc.h>
using namespace std;

#define  MAX_CHILDREN 4


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
	COMP_STMT,
	EXPR_STMT,  //ֻ��һ����װ����
};

enum					// ���ʽ��������͡���kindkind
{
	TYPE_EXPR = 0,
	OP_EXPR,
	NOT_EXPR,
	UMINUS_EXPR,
	ARRAY_EXPR,
	CONST_EXPR,
	ID_EXPR,
};

enum					// ������������͡���kindkind
{
	VAR_DECL = 0,
	ARRAY_DECL
};
/*
enum					// ���㡪��op
{
	//�Ӽ��˳������������
	PLUS = 0,
	MINUS,
	TIMES,   
	OVER,
	//����߼������
	AND,
	OR,
	//�Ƚ������
	EQ,
	LT,
	GT,
	GE,
	LE,
	NE,
	ASSIGN,
};
*/
enum
{
	Integer = 0,
};

union NodeAttr {
	int op;				// ���ʽ��㣬����������������ʱ����op�����������
	double vali;				// ���ʽ��㣬�������ʽʱ����vali�������ͳ���ֵ
	char valc;			// �ַ�ֵ
	int symtbl_seq;     //���ű�λ��

	NodeAttr(void) { op = 0; }		// ���ֹ��캯��
	NodeAttr(int i)	{ op = i; }
	NodeAttr(double i)	{ vali = i; }
	NodeAttr(char c) { valc = c; }
};


struct Node
{
	struct Node *children[MAX_CHILDREN];	// ���ӽ��
	struct Node * sibling;
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

extern tree parser_tree;
Node* createOpExpr(tree& expr, Node* p, Node* q, int type);
Node* createId(tree& expr);
Node* createId(tree& expr, int seq); //���������ڵ㣬�����Դ洢����ű�����
Node* createConst(tree& expr, double value);
Node* createSTMT(tree& expr, int type, Node* p1, Node* p2=NULL, Node* p3 = NULL, Node* p4=NULL);
Node* createIfStmt(tree& expr,Node* p1, Node* p2, Node* p3 = NULL );
Node* createWhileStmt(tree& expr, Node* p1, Node* p2);
Node* createInputStmt(tree& expr, Node* p);
Node* createOutStmt(tree& expr, Node* p);
Node* createExprStmt(tree& expr, Node* p);
Node* createAssignStmt(tree& expr, Node* variable, int value);
Node* createAssignStmt(tree& expr, Node* variable, Node* q);
Node* createCompStmt(tree& expr, Node* p1, Node* p2=NULL, Node* p3 = NULL, Node* p4=NULL);
void executeTree(tree& expr, Node* root);
void executeTree(tree& expr);

#endif//__TREE__H__