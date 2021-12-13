#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char data;
	struct Node *next;
} node;
typedef struct Stack
{
 node *head;
}stack;


int isEmpty(stack q)
{
	return (q.head == NULL);
}
void Push( stack *q,char x)
{
    node *p = malloc(100*sizeof(node));
	p->data = x;
	p->next = NULL;
	if(isEmpty(*q)){
	(*q).head=p;}
	else
	{

		p->next = (*q).head;
		(*q).head = p;

	}
}
char Pop(stack *q)
{
char x;
x= (*q).head->data;
node *k;
k= (*q).head;
(*q).head = (*q).head->next;
free(k);

return x;
}
char top(stack q)
{
char x;
x= q.head->data;

return x;
}

int precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;

	return 3;
}

typedef struct Noden
{
	double data;
	struct Node *next;
} noden;
typedef struct Stackn
{
 noden *head;
}stackn;


int isEmptyn(stackn q)
{
	return (q.head == NULL);
}
void Pushn( stackn *q,float x)
{
    noden *p = malloc(100*sizeof(noden));
	p->data = x;
	p->next = NULL;
	if(isEmptyn(*q)){
	(*q).head=p;}
	else
	{

		p->next = (*q).head;
		(*q).head = p;

	}
}
float Popn(stackn *q)
{
float x;
x= (*q).head->data;
noden *k;
k= (*q).head;
(*q).head = (*q).head->next;
free(k);

return x;
}
float topn(stackn *q)
{
float x;
x= (*q).head->data;



return x;
}
float Evaluate(char *Postfix)
{
    stackn S;
    S.head=NULL;
	char *p;
	float op1, op2, result;
	p = Postfix[0];
	int i=0;
	while (p != '\0')
	{
		while (p == ' ' || p == '\t')
		{
			i++;
			p=Postfix[i];
		}
		if (isdigit(p))
		{
			int num = 0;

				num = num * 10 + p - 48;
            float nu = 1.0*num;
			Pushn(&S, nu);
		}
		else
		{
			op1 = Popn(&S);
			op2 = Popn(&S);
			if(p=='+')
				result = op2 + op1;

			else if(p=='-')
				result = op2 - op1;

			else if(p== '/')
				result = 1.0*op2 / op1;



			else
				result = op2 * op1;



			Pushn(&S, result);

		}
		i++;
		p=Postfix[i];
    }

	result = Popn(&S);
	return result;
}

int main()
{
	stack S;
    S.head=NULL;
	char infix[255];
	char postfix[255];
	scanf("%s",infix);

	char x, token;
	int i = 0, j = 0;    // i-index of infix,j-index of postfix

	for (i = 0; i<strlen(infix); i++)
	{
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else
			if (token == '(')
				Push(&S, '(');
			else
				if (token == ')')
				{
				do
				{
				 x = Pop(&S);
				}
					while (x  != '(');
						postfix[j++] = x;
                }
				else
				{
					while (!isEmpty(S))
					if(precedence(token) <= precedence(top(S)))
					{
						x = Pop(&S);
						postfix[j++] = x;
					}
					else break;
					Push(&S, token);
				}
	}

	while (!isEmpty(S))
	{

		x = Pop(&S);

		postfix[j++] = x;
	}

	postfix[j] = '\0';


    printf("%s\n", postfix);
   printf("%f\n",Evaluate(postfix));


	return 0;
}

