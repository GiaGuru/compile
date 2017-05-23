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
	COMP_STMT,
	EXPR_STMT,  //ֻ��һ����װ����
};

enum					// ���ʽ��������͡���kindkind
{
	TYPE_EXPR = 0,
	OP_EXPR,
	NOT_EXPR,
	ARRAY_EXPR,
	CONST_EXPR,
	ID_EXPR,
};

enum					// ������������͡���kindkind
{
	VAR_DECL = 0,
	ARRAY_DECL
};

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
enum
{
	Integer = 0,
};

union NodeAttr {
	int op;				// ���ʽ��㣬����������������ʱ����op�����������
	double vali;				// ���ʽ��㣬�������ʽʱ����vali�������ͳ���ֵ
	char valc;			// �ַ�ֵ

	NodeAttr(void) { op = 0; }		// ���ֹ��캯��
	NodeAttr(int i)	{ op = i; }
	NodeAttr(double i)	{ vali = i; }
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
	//cout << my_mem[root->addr] << endl;	// ���ڴ�ȡ��ִ�н�������
}
/*
���������ժҪ��
if�����жϹ��ܣ�
����if��condition�������Ƿ�ִ��statement���룬��˲������ȶ������еĺ��ӽ��к�����������Ҫ���ݵ�һ�����ӵ�ִ�н���������Ƿ�ִ�еڶ������ӡ�
whileѭ�����ܣ�
�˹��ܿ�ܴ�����if�������ƣ�ֻ�Ƕ���һ��whileѭ������
������ֵ��
��ȡ�û����룬����ֵ��������֧��input(a)�������û������븳ֵ������a��aΪ���һ�����ӡ�
��ֵ��䣺
֧��a=2�������������ӣ����Ϊ�������ұ�Ϊֵ����ǰֵΪ��ߵ�ֵ��
���빦�ܣ�
�ܹ������û����룬����ֵ�������У�ǰ����Ҫ���Ӹ�ֵ����
������ܣ�
���������䣬��ֻ��һ�����ӣ���Ҫ����ı�����
*/
void tree::recursive_execute(Node *t)
{
	if (t) {
		if(t->kind == STMT_NODE){
			if(t->kind_kind == IF_STMT){
				//if�����жϽ�����ڶ������Ӵ洢if�ɹ��Ĵ��룬���������Ӵ洢else�ɹ��Ĵ���
				recursive_execute(t->children[0]);
				if (my_mem[t->children[0]->addr] )
					recursive_execute(t->children[1]);
				else
					recursive_execute(t->children[2]);
			}else if(t->kind_kind == WHILE_STMT){
				//��һ�����Ӵ洢�����жϽ�����ڶ������Ӵ洢while�ɹ��Ĵ���
				recursive_execute(t->children[0]);
				while (my_mem[t->children[0]->addr])
				{
					recursive_execute(t->children[1]);
					recursive_execute(t->children[0]);
				}
			}else if(t->kind_kind == INPUT_STMT){//input statement has one expr child
				cout<<"please input data:";
				cin>>my_mem[t->children[0]->addr];
			}else if(t->kind_kind == PRINT_STMT){//print statement has one expr child to print.
				recursive_execute(t->children[0]);
				cout<<my_mem[t->children[0]->addr];
			}else if(t->kind_kind == COMP_STMT){//�����䣬������ִ�м��ɡ�
				for (int i = 0; i < MAX_CHILDREN; ++i)
					recursive_execute(t->children[i]);
			}else if(t->kind_kind == EXPR_STMT){
				recursive_execute(t->children[0]);
			}
		}
		if (t->kind == EXPR_NODE){			// ���ʽ���
			recursive_execute(t->children[0]);
			recursive_execute(t->children[1]);
				
			if (t->kind_kind == OP_EXPR) {		// �������ͱ��ʽ
				if (t->attr.op == PLUS)			// �ӷ����ʽ
					// ���ڴ棨my_mem����ȡ���������ӵ�ֵ�����мӷ������д���ڴ�
					my_mem[t->addr] = my_mem[t->children[0]->addr] + my_mem[t->children[1]->addr]; 
				else if (t->attr.op == MINUS)	// �����Ĵ������Ƽӷ�
					my_mem[t->addr] = my_mem[t->children[0]->addr] - my_mem[t->children[1]->addr];
				else if (t->attr.op == TIMES)
					my_mem[t->addr] = my_mem[t->children[0]->addr] * my_mem[t->children[1]->addr];
				else if (t->attr.op == OVER){
					if(my_mem[t->children[1]->addr] == 0){
						cout<<"error: divide by zero"<<endl;
						my_mem[t->addr] = 0;
					}else{
						my_mem[t->addr] = my_mem[t->children[0]->addr] / my_mem[t->children[1]->addr];
					}
				}
				else if (t->attr.op == AND)
					my_mem[t->addr] = my_mem[t->children[0]->addr] && my_mem[t->children[1]->addr];
				else if (t->attr.op == OR)
					my_mem[t->addr] = my_mem[t->children[0]->addr] || my_mem[t->children[1]->addr];
				else if (t->attr.op == EQ)
					my_mem[t->addr] = (my_mem[t->children[0]->addr] == my_mem[t->children[1]->addr]);
				else if (t->attr.op == GT)
					my_mem[t->addr] = my_mem[t->children[0]->addr] > my_mem[t->children[1]->addr];
				else if (t->attr.op == LT)
					my_mem[t->addr] = (my_mem[t->children[0]->addr] < my_mem[t->children[1]->addr]);
				else if (t->attr.op == NE)
					my_mem[t->addr] = !(my_mem[t->children[0]->addr] == my_mem[t->children[1]->addr]);
				else if (t->attr.op == GE)
					my_mem[t->addr] = (my_mem[t->children[0]->addr] > my_mem[t->children[1]->addr]) || (my_mem[t->children[0]->addr] == my_mem[t->children[1]->addr]);
				else if (t->attr.op == LE)
					my_mem[t->addr] = (my_mem[t->children[0]->addr] < my_mem[t->children[1]->addr]) || (my_mem[t->children[0]->addr] == my_mem[t->children[1]->addr]);
				else if(t->attr.op == ASSIGN){
					my_mem[t->addr] = my_mem[t->children[0]->addr] = my_mem[t->children[1]->addr];
				}
			}
			else if (t->kind_kind == CONST_EXPR)	// �������ʽ����ֵ����vali�У�������������ڴ���
				my_mem[t->addr] = t->attr.vali;
			else if(t->kind_kind == ID_EXPR){
				//do nothing
			}

		}//EXPR_NODE
	}
}

/*
if:  st_if -> (condition, action)
while: st_while->(condition, action)
*/
void basicTest()
{
	tree expr;
	Node *p, *q, *r;

	// �������a
	p = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(9), Integer);
	// �������5
	q = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(5), Integer);
	// ����������㣬���ӽ��Ϊ9��5
	r = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(MINUS), Integer, p, q);
	// q = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(2), Integer);
	// p = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(PLUS), Integer, r, q);
	expr.setRoot(r);
	expr.get_addr();	// Ϊ���ӣ����ʽ���ǣ�����洢�ռ�
	expr.execute();	// ִ�д���
}
void assignTest()
{
	/*
	a = 1
	output(a)

	�������
	*/

	tree expr;
	Node *p, *q, *r, *s, *o, *u, *t;

	//������ֵ���
	// �������a
	p = expr.NewRoot(EXPR_NODE, ID_EXPR, NodeAttr(0), Integer);
	// �������1
	q = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(5), Integer);
	//��ֵ
	r = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(ASSIGN), Integer, p, q);
	s = expr.NewRoot(STMT_NODE, EXPR_STMT, NodeAttr(0), Integer, r);//��ֵ��䣺���Ӹ�ֵ���ʽ


	//����������
	t = expr.NewRoot(STMT_NODE, PRINT_STMT, NodeAttr(), Integer, p);

	//����������
	o = expr.NewRoot(STMT_NODE, COMP_STMT, NodeAttr(), Integer, s, t);

	expr.setRoot(o);
	expr.get_addr();	// Ϊ���ӣ����ʽ���ǣ�����洢�ռ�
	expr.execute();	// ִ�д���
	cout<<endl;
}

Node* createOpExpr(tree& expr, Node* p, Node* q, int type)
{
	Node* p1;
	p1 = expr.NewRoot(EXPR_NODE, OP_EXPR, NodeAttr(type), Integer, p,q);
	return p1;
}
Node* createId(tree& expr)
{
	Node* p;
	p = expr.NewRoot(EXPR_NODE, ID_EXPR, NodeAttr(0), Integer);
	return p;
}
Node* createConst(tree& expr, double value)
{
	Node* q2;
	q2 = expr.NewRoot(EXPR_NODE, CONST_EXPR, NodeAttr(value), Integer);
	return q2;
}
Node* createSTMT(tree& expr, int type, Node* p1, Node* p2=NULL, Node* p3 = NULL, Node* p4=NULL)
{
	Node* r;
	r = expr.NewRoot(STMT_NODE, type, NodeAttr(), Integer, p1,p2,p3,p4);

	return r;
}
Node* createIfStmt(tree& expr,Node* p1, Node* p2, Node* p3 = NULL )
{
	return createSTMT(expr, IF_STMT,  p1, p2, p3);
}
Node* createWhileStmt(tree& expr, Node* p1, Node* p2)
{
	return createSTMT(expr, WHILE_STMT, p1, p2);
}
Node* createInputStmt(tree& expr, Node* p)
{
	return createSTMT(expr, INPUT_STMT, p);
}
Node* createOutStmt(tree& expr, Node* p)
{
	return createSTMT(expr, PRINT_STMT, p);
}
Node* createExprStmt(tree& expr, Node* p)
{
	return expr.NewRoot(STMT_NODE, EXPR_STMT, NodeAttr(0), Integer, p);//xxxx; xxxxΪ���ʽ����ϳ����
}
Node* createAssignStmt(tree& expr, Node* variable, int value)
{
	Node* p = variable;
	Node *q, *r, *s;
	q = createConst(expr, value);
	r = createOpExpr(expr, p,q, ASSIGN);

	return createExprStmt(expr, r);
}
Node* createAssignStmt(tree& expr, Node* variable, Node* q)
{
	Node* p = variable;
	Node *r, *s;
	r = createOpExpr(expr, p,q, ASSIGN);

	return createExprStmt(expr, r);
}
Node* createCompStmt(tree& expr, Node* p1, Node* p2=NULL, Node* p3 = NULL, Node* p4=NULL)
{
	return createSTMT(expr, COMP_STMT, p1,p2,p3,p4);
}
void executeTree(tree& expr, Node* root)
{
	expr.setRoot(root);
	expr.get_addr();	// Ϊ���ӣ����ʽ���ǣ�����洢�ռ�
	expr.execute();	// ִ�д���
	cout<<endl;
}
void inputOutTest()
{
	/*
	input(a)
	output(a)
	*/
	tree expr;
	Node *p, *q, *r, *s, *o, *u, *t;

	//�������
	// �������a
	p = expr.NewRoot(EXPR_NODE, ID_EXPR, NodeAttr(0), Integer);
	s = createInputStmt(expr, p);
	q = createOutStmt(expr, p);
	o = createCompStmt(expr, s, q);

	executeTree(expr, o);
}
void ifTest()
{
	/*
	a = 1
	if(a>10){
	  a = 11
	}else{
	  a = 7
	}
	print(a)
	*/
	tree expr;
	Node *p, *q, *r, *s, *o, *u, *t;

	//�������
	// �������a
	p = expr.NewRoot(EXPR_NODE, ID_EXPR, NodeAttr(0), Integer);
	s = createAssignStmt(expr, p, 1);//a=1


	//if���
	q = createOpExpr(expr, p, createConst(expr, 10), GT);//a>10
	r = createIfStmt(expr, q, createAssignStmt(expr, p, 11), createAssignStmt(expr, p, 7));//if(a>10) a=11 else a=7

	//����������
	t = createOutStmt(expr, p);//print(a)

	//����������
	o = createCompStmt(expr,s ,r, t );

	executeTree(expr , o);
}
void whileTest()
{
	/*
	a =1
	sum = 0
	while(a <= 10){
	   sum = sum + a
	   a = a+1;
	}
	print(sum)
	*/

	tree expr;
	Node *p, *q, *r, *s, *o, *u, *t,*p1,*q1;
	p = createId(expr);//a
	q = createId(expr);//sum
	p1 = createAssignStmt(expr,p, 1);//a=1
	q1 = createAssignStmt(expr, q, 0);//sum=0

	Node *a, *b, *c, *d, *e, *f, *g;
	a = createOpExpr(expr, p, createConst(expr, 10), LE);//a<=10
	b = createOpExpr(expr, p, q, PLUS);//sum+a
	c = createAssignStmt(expr, q, b);//sum = sum+a

	d = createOpExpr(expr, p, createConst(expr, 1), PLUS);
	e = createAssignStmt(expr, p, d);	//a=a+1
	f = createCompStmt(expr, c, e); //{sum = sum+a, a= a+1}
	r = createWhileStmt(expr, a,  f);//while

	t = createOutStmt(expr, q);//print sum

	o = createCompStmt(expr, p1, q1, r, t);

	executeTree(expr, o);
}

void whileInputTest()
{
	/*
	a = 1
	sum = 0
	input(x)
	while(a <= x){
	   sum = sum + a
	   a = a+1;
	}
	print(sum)
	*/

	tree expr;
	Node *p, *q, *r, *s, *o, *u, *t,*p1,*q1;
	p = createId(expr);//a
	q = createId(expr);//sum
	p1 = createAssignStmt(expr, p, 1);//a=1
	q1 = createAssignStmt(expr, q, 0);//sum=0

	Node *a, *b, *c, *d, *e, *f, *g;
	g = createId(expr);//x
	f = createInputStmt(expr,g);
	u = createCompStmt(expr, p1, q1, f);//first 3 sentences. because Comp not support more than 4 children.

	a = createOpExpr(expr, p, g, LE);//a<=x, x from input
	b = createOpExpr(expr, p, q, PLUS);//sum+a
	c = createAssignStmt(expr, q, b);//sum = sum+a

	d = createOpExpr(expr, p, createConst(expr, 1), PLUS);
	e = createAssignStmt(expr, p, d);	//a=a+1
	f = createCompStmt(expr, c, e); //{sum = sum+a, a= a+1}
	r = createWhileStmt(expr, a,  f);//while

	t = createOutStmt(expr, q);//print sum

	o = createCompStmt(expr, u, r, t);

	executeTree(expr, o);
}
int main(int argc, char *argv[])
{
	//assignTest();
	//inputOutTest();
	//ifTest();

	//whileTest();
	whileInputTest();
}

