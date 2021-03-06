#include<stdio.h>
#include<stdlib.h>


#define stack_init_size 100
#define stackincrement 10


typedef struct{
	int *base;
	int *top;
	int stacksize;
}sqstack;


int initstack(sqstack *s)  // 栈的初始化
{
	s->base=(int *)malloc(stack_init_size*sizeof(int));
	if(!s->base)	return 0;
	s->top=s->base;
	s->stacksize=stack_init_size;
	return 1;
}


void destroystack(sqstack *s)  //清空栈
{
	free(s->base);
}
void clearstack(sqstack *s)  //伪清空
{
	s->top=s->base;
}


int stackempty(sqstack *s)  //判断栈是否为空
{
	if(s->base==s->top)	 return 1;
	else
		return 0;
}


int stacklength(sqstack *s)   //栈的长度
{
	return(s->top-s->base);
}


int gettop(sqstack *s,int *e)   // 栈顶元素
{
	if(s->top!=s->base)
	{
		*e=*(s->top-1);
		return 1;
	}
	else
		return 0;
}


int pop(sqstack *s,int *e)  //  出栈
{
	if(s->top!=s->base)
	{
		*e=*(s->top-1);
		s->top--;
		return 1;
	}
	else
		return 0;
}
int push(sqstack *s,int e)  //进栈
{
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(int *)realloc(s->base,(s->stacksize+stackincrement)*sizeof(int));
		if(!s->base) return 0;
		s->stacksize+=stackincrement;
	}
	*(s->top)=e;
	s->top++;
	return 1;
}


void stacktraverse(sqstack *s)   // 遍历栈
{
	int *p;
	p=s->top-1;
	printf("scz:");
	while(p>=s->base)
	{
		printf(" %d ",*p);
		p--;
	}
	printf("\n");
}


void conversion(sqstack *sq,int n,int jz,char s[])    // 进制转换，16 进制不行
{
	int e,i=0;
	while(n)
	{
		push(sq,n%jz);
		n=n/jz;
	}
	while(!stackempty(sq))
	{
		pop(sq,&e);
		s[i]=e+'0';
		i++;            
	}
	s[i]='\0';
}

int main()
{
	sqstack sq;
	int i,e;
	initstack(&sq);

	scanf("%d",&i);
	while(i!=-1)
	{
		push(&sq,i);
		scanf("%d",&i);
	}
	stacktraverse(&sq);

	while(!stackempty(&sq))
	{
		pop(&sq,&e);
		printf("*%d*",e);
	}
	destroystack(&sq);
	return 0;
}
