#include<stdio.h> //for scanf(),printf()
#include<stdlib.h> //for malloc()
#include<ctype.h> //for toupper()

//linked list as stack

struct node	//node
{
	char symbol;
	struct node *next;
};

struct node *top=NULL; //here, stack top z0 is recognized by NULL

struct node* new_node()	//node creator
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	return p;
}

int isempty()	//stack status checker
{
	if(top==NULL)	//empty stack
		return 1;
	else
		return 0;
}

void push(char stackin)	//push operation
{
	struct node *p=new_node();
	if(p==NULL)	//overflow
		printf("\nPush not possible\n");
	if(isempty())	//empty stack
		{
			p->symbol=stackin;
			top=p;
		}
 	else	//stack has atleast one element
		{
			p->symbol=stackin;
			p->next=top;
			top=p;
		}
	printf("%c pushed to stack\n",stackin);
}

int pop()	//pop operation
{
	if(isempty())	//stack has no element
		{
			printf("\n**Stack already empty but string not fully read**\n");
			return 0;	//underflow
		}
	struct node *p= top;
    top = top->next;
    printf("%c popped from stack\n",p->symbol);
	free(p);
	p=NULL;
	return 1;	//successful pop
}

//Pushdown acceptor

int pda(char s[])
{
	int i;	//iterator
	for(i=0;s[i]!='\0';i++)
	{
		printf("\n%c is scanned\n",s[i]);
		if(s[i]!='0' && s[i]!='1')  //character not 0/1
			{
				printf("\n**Unknown character %c read**\n",s[i]);
				return 0;
			}
		if(s[i]=='0')   //0 scanned, push
			push(s[i]);
		else if(!pop()) //1 scanned, pop
				break;  //unsuccessful pop
	}
	if(s[i]=='\0' && isempty()) //string read, stack empty
		{
			printf("\n**String fully read**\n\n**Stack is empty**\n");
			return 1;
		}
	else						//any other case
		return 0;
}

void main()
{
	char word[255];
	char ch;	//user choice
	printf("***Pushdown Automaton***\n");
	printf("Which accepts input string of form 0^n1^n(n>=1)\n");
	printf("by empty stack method of acceptance\n\n");
	do
	{
		printf("Enter string: ");
 		scanf("%s",&word);
		if(pda(word))	//automaton called
			printf("\nString %s is ACCEPTED by pda\n",word);
		else
			printf("\nString %s is NOT ACCEPTED by pda\n",word);
		printf("\nExit? (y/N): ");
		scanf(" %c",&ch);
		printf("\n");
	}while(toupper(ch)!='Y');	//exit condition
}
