#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#define MAXSIZE 52

//for scanning the expression
void scanexp(char *expr)
{
	printf("Enter the expression (Max length 50 no spaces) :) \n");
    gets(expr); //	scanf("%49s",expr);
	if(strlen(expr)>50)
	{
		printf("sorry can't perform calculations length is greater exiting");
		exit(-1);
	}
	else
	{
		if(strlen(expr)>1){
		
            char *ptr = strchr(expr,' ');
            if(ptr == NULL)
            {
            	printf("Calculating :)");
			}
			else
			{
				printf("string contains spaces :(");
				exit(-1);
			}
		}
		else
		{
			printf("expression must be greater than 1 character :(");
			exit(-1);
		}
	}
}


//new stack has been created
struct stack
{
	char Array[MAXSIZE];
	int top; 
};


//constructor type function for stack
void init(struct stack *(temp))
{
	temp->top = -1;
}

//top value of stack returned always
char ret_top(struct stack *(temp))
{
	if(!isempty(temp)){
	
        return temp->Array[temp->top]; 
	}
}


//checks whether empty or not
int isempty(struct stack *(temp))
{
	if(temp->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//checks if stack is not full
int isfull(struct stack *(temp))
{
	if(temp->top == MAXSIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}


//pushes element on to the stack
void push(char data,struct stack *(temp))
{
	if(!isfull(temp))
	{
		temp->top++;
		temp->Array[temp->top] = data;
	}
	
}


//deletes an element from the stack
void pop(struct stack *(temp))
{
	if(!isempty(temp))
	{
		temp->top--;
	}
}


//checks for balance paranthesis
int is_balance_paranthesis(char *expr)
{
	unsigned int len = strlen(expr);
	int i;
	struct stack balance;
	init(&balance);
	for(i=0;i<len;i++)
	{
		
		if(expr[i] == '[' || expr[i] == '{' || expr[i] == '(')
		{
			push(expr[i],&balance);
	    }
	    else if(expr[i] == ']' || expr[i] == '}' || expr[i] == ')')
	    {
	    	char check = ret_top(&balance);
	    	if(check == '[')
	    	{
	    		if(expr[i] != ']')
	    		{
	    			return -1;
				}
				else 
				{
					pop(&balance);
				}
	    		
			}
			else if(check == '(')
			{
	            if(expr[i] != ')')
	    		{
	    			return -1;
				}
				else 
				{
					pop(&balance);
				}				
			}
			else if(check == '{')
			{
	            if(expr[i] != '}')
	    		{
	    			return -1;
				}
				else 
				{
					pop(&balance);
				}				
			}	    	
 		}
 		
	}
	if(isempty(&balance))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


//gives priority to operators
int give_me_priority(char operat)
{
	switch(operat)
	{
		case '+': return 0;break;
		case '-': return 1;break;
		case '*': return 2;break;
		case '/': return 3;break;
		case '^': return 4;break;
		default : return -1;break;	
	}
}


//tells whether alphabets or braces or number
int if_operator_not(char ascii)
{
	int expr = ascii;
	if((expr >= 48 && expr <=57) || (expr >=65 && expr <=90) || (expr >=97 && expr <=122)) //if digit or alphabet
	{
		return 1;
	}
	else if(expr==42 || expr==43 || expr == 45 || expr == 47 || expr == 94) //if it is operator
	{
		return 2;
	}
	else if(expr==40 ||expr == 41 || expr==123 || expr == 125 || expr == 91 || expr ==93 )//if braces
	{
		return 3;
	}
	else
	{
		return 4;
	}
}


//main function to convert the final expression
void convert_infix_postfix(char *infix_exp,char *postfix_exp)		
{
	unsigned int length = strlen(infix_exp);
	if(length <= 50)
	{
	 	infix_exp[length] = '}';
		infix_exp[length+1] = '\0';
		struct stack convert;
		init(&convert);
		push('{',&convert);
		
		int index;//to use in loop
		int post_index=0;
		for(index=0;index<=length;index++)
		{
			int exp_check =if_operator_not(infix_exp[index]);
			if(exp_check >=1 && exp_check <=3)
			{
				if(exp_check == 1)
				{
					postfix_exp[post_index] = infix_exp[index];
					postfix_exp[++post_index] = '\0';
				}
				else if(exp_check == 2)
				{
					int priority_top = give_me_priority(ret_top(&convert));
					int priority = give_me_priority(infix_exp[index]);
					//now compare the priority of both operators
					if(priority_top > priority)
					{
						while(priority_top > priority && priority_top !=-1)
						{
							postfix_exp[post_index] = ret_top(&convert);
							postfix_exp[++post_index] = '\0';
							pop(&convert);
							priority_top = give_me_priority(ret_top(&convert));
						}
						
					}
					else
					{
						push(infix_exp[index],&convert);
					}
					
				}
				else
				{
					int x = infix_exp[index];
					if(x == 91 || x == 123 || x ==40)
					{
						//opening braces
						push(infix_exp[index],&convert);
					}
					else
					{
						//closing braces
						//pop while we encounter an opening paranthesis
						while(x != 91 || x !=123 || x !=40)
						{
							char y = ret_top(&convert);
							postfix_exp[post_index] = y;
							postfix_exp[++post_index] = '\0';
							pop(&convert);
							x = ret_top(&convert);
						}
						pop(&convert);
					}
				}
		    }
			else
			{
				printf("something went wrong in your expression ");
				exit(-1);
		    } 
		}
				
	}
	else
	{
		printf("string greater than specified length");
		exit(-1);
	}
}




int main()
{
	char infix_expression[MAXSIZE];
	scanexp(infix_expression);
	printf("your entered value is : %s \n",infix_expression);
	int checker = is_balance_paranthesis(infix_expression);
	printf('%d',checker);
	if(checker == 1)
	{
		//proceed
        char postfix_expr[MAXSIZE];
		convert_infix_postfix(infix_expression,postfix_expr);		
		printf("The converted postfix expression is : %s \n",postfix_expr);
	}
	else
	{
		printf("The paranthesis in the expression are not balanced :(");
		exit(-1);
	}
	
	
	return 0;
}
