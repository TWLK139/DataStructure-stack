//**********************//
//单链表实验头文件		//
//包含：1，依赖头文件	//
//		2，栈定义		//
//		3，函数声明		//
//		4，函数定义		//
//**********************//


#ifndef STACK_H

#define STACK_H

#include<iostream>

#define elementType char
#define elementTypeL int

using namespace std;

#endif // !STACK_H

//*********************顺序栈结构定义***********************//
#define MAXLEN 100											//
															//
typedef struct sStack										//
{															//
	elementType data[MAXLEN];			//存放栈元素		//
	int top;							//栈顶指示器		//
}seqStack;													//
//**********************************************************//

//**********************链栈结构定义************************//
typedef struct lsNode										//
{															//
	elementType data;					//链栈结点数据域	//
	struct lsNode* next;				//链栈结点指针域	//
}sNode, * LinkedStack;										//
//**********************************************************//

//********************拓展实验结构定义**********************//
//用于输出序列合法性分析的最大长度							//
#define MAXLEN_1 5											//
															//
//用于输出序列合法性分析的栈与队列							//
//使用两个队列共同模拟一个栈的入栈出栈，便于结果输出		//
typedef struct sQueue_lagel									//
{															//
	elementTypeL data[MAXLEN_1];							//
	int front;												//
	int rear;												//
} seqQueue_lagel;											//
															//
//使用一个中间栈保存模拟时，入栈后暂未出栈的元素			//
typedef struct sStack_lagel									//
{															//
	elementTypeL data[MAXLEN_1];							//
	int top;												//
} seqStack_lagel;											//
//**********************************************************//


//******************************************************函数声明************************************************************//
//顺序栈函数声明																											//
void initialSeqStack(seqStack& S);														//初始化顺序栈						//
bool pushSeqStack(seqStack& S, elementType x);											//顺序栈入栈						//
bool popSeqStack(seqStack& S);															//顺序栈出栈						//
bool showSeqStack(seqStack& S);															//打印顺序栈中元素					//
bool hexadecimal(seqStack& res, int num);												//顺序栈将10进制数转换为16进制数	//
bool expressionLagel(char ex[]);														//顺序栈判断表达式括号是否合法		//
//链栈函数声明																												//
bool initialLinkStack(LinkedStack& top);												//初始化链栈						//
bool pushLinkStack(LinkedStack& top, elementType x);									//链栈入栈							//
LinkedStack popLinkStack(LinkedStack& top);												//链栈出栈							//
bool destroyLinkStack(LinkedStack& top);												//销毁链栈							//
bool showLinkStack(LinkedStack& top);													//打印链栈中元素					//
bool hexadecimalLinkStack(LinkedStack& res, int num);									//链栈将10进制数转换为16进制数		//
bool expressionLagelLinkStack(char ex[]);												//链栈判断表达式括号是否合法		//
//拓展实验函数声明：输出序列合法性判断																						//
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output);	//输出指定输入序列的所有合法输出序列//
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output);						//判断输出序列是否合法				//
bool creatQueneArr(seqQueue_lagel* Q, int num);											//指定数组创建队列					//
void printQuene(seqQueue_lagel* Q);														//打印队列							//
//**************************************************************************************************************************//


//******************************函数定义********************************

//***************************顺序栈函数定义*****************************
//****************辅助函数：初始化顺序栈****************
//辅助函数：初始化顺序栈
//输入：需要初始化的顺序栈指针
void initialSeqStack(seqStack& S)
{
	S.top = -1;
}


//****************辅助函数：顺序栈入栈****************
//辅助函数：入栈
//输入：栈，插入元素
//返回：栈满返回false，插入成功返回true
bool pushSeqStack(seqStack& S, elementType x)
{
	if (S.top == MAXLEN - 1)
	{
		return false;
	}
	else
	{
		S.top++;
		S.data[S.top] = x;

		return true;
	}
}


//****************辅助函数：顺序栈出栈****************
//辅助函数：出栈
//输入：栈
//返回：栈空返回false，成功出栈返回true
bool popSeqStack(seqStack& S)
{
	if (S.top == -1)
	{
		return false;
	}
	else
	{
		S.top--;
		return true;
	}
}


//****************辅助函数：打印顺序栈****************
//辅助函数：打印栈
//输入：需要打印的顺序栈指针
bool showSeqStack(seqStack& S)
{
	int nowP = S.top;
	if (S.top > -1)
	{
		while (nowP >= 0)
		{
			cout << S.data[nowP];
			nowP--;
		}
		cout << endl;

		return true;
	}
	else
	{
		cout << "当前栈未初始化！" << endl;

		return false;
	}
}


//****************顺序栈将10进制数转换为16进制数****************
//实验三.顺序栈.1，将10进制数转换为16进制数
//输入：存放结果的栈指针、要进行进制转换的十进制数
//输出：十六进制结果存放在传入的栈中
//返回：运行成功返回true，运行失败返回false
bool hexadecimal(seqStack& res, int num)
{
	const char hexNum[17] = "0123456789ABCDEF";
	initialSeqStack(res);

	if (num == 0)
	{
		res.top++;
		res.data[res.top] = hexNum[0];
	}

	while (num != 0)
	{
		if (pushSeqStack(res, hexNum[num % 16])) num /= 16;
		else
		{
			cout << "栈满溢出！" << endl;

			return false;
		}
	}

	return true;
}


//****************顺序栈对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的****************
//实验三.顺序栈.2，判断表达式括号是否合法
//输入：表达式字符串首地址
//返回：表达式括号合法返回true，表达式括号不合法返回false
bool expressionLagel(char ex[])
{
	int i;
	seqStack exStack;
	initialSeqStack(exStack);

	for (i = 0; ex[i] != '\0'; i++)
	{
		if (ex[i] == '{' || ex[i] == '[' || ex[i] == '(')
		{
			pushSeqStack(exStack, ex[i]);
		}
		else if (ex[i] == ')' || ex[i] == ']' || ex[i] == '}')
		{
			switch (ex[i])
			{
			case ')':
				if (exStack.data[exStack.top] == '(')popSeqStack(exStack);
				else return false;
				break;
			case ']':
				if (exStack.data[exStack.top] == '[')popSeqStack(exStack);
				else return false;
				break;
			case '}':
				if (exStack.data[exStack.top] == '{')popSeqStack(exStack);
				else return false;
				break;
			default:
				return false;
				break;
			}
		}
	}
	if (exStack.top != -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//****************************链栈函数定义******************************
//****************辅助函数：初始化链栈****************
//输入：需要初始化的链栈指针
//返回：创建头结点成功返回true，创建失败返回false
bool initialLinkStack(LinkedStack& top)
{
	if (top == nullptr)
	{
		top = new lsNode;
		top->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前栈已创建！请销毁后再创建" << endl;

		return false;
	}
}


//****************辅助函数：链栈入栈****************
//辅助函数：链栈入栈
//输入：栈，插入元素
//返回：插入成功返回true，插入失败返回false
bool pushLinkStack(LinkedStack& top, elementType x)
{
	LinkedStack newNode;

	if (top == nullptr)
	{
		cout << "当前栈未创建！" << endl;

		return false;
	}
	else
	{
		newNode = new lsNode;
		newNode->data = x;
		newNode->next = top->next;
		top->next = newNode;

		return true;
	}
}


//****************辅助函数：链栈出栈****************
//辅助函数：链栈出栈
//输入：栈顶指针
//返回：栈空返回nullptr，成功出栈返回栈顶指针
LinkedStack popLinkStack(LinkedStack& top)
{
	LinkedStack endNode;

	if (top == nullptr)
	{
		cout << "当前栈未创建！" << endl;

		return nullptr;
	}
	else if (top->next == nullptr)
	{
		cout << "当前栈已空！" << endl;

		return nullptr;
	}
	else
	{
		endNode = top->next;
		top->next = endNode->next;

		return endNode;
	}
}


//****************辅助函数：销毁链栈****************
//辅助函数：销毁链表
//输入：需要销毁的链栈指针
bool destroyLinkStack(LinkedStack& top)
{
	LinkedStack nowNode;

	if (top != nullptr)
	{
		while (top && top->next)
		{
			delete(popLinkStack(top));
		}
		if (top->next == nullptr)
		{
			delete(top);				//指针delete之后不为null
			top = nullptr;
		}
	}

	if (!top) return true;
	else return false;
}


//****************辅助函数：打印链栈****************
//辅助函数：打印链栈
//输入：需要打印的链栈指针
bool showLinkStack(LinkedStack& top)
{
	LinkedStack nowNode = top;

	if (top == nullptr)
	{
		cout << "当前栈未创建！" << endl;

		return false;
	}
	else
	{
		while (nowNode->next)
		{
			cout << nowNode->next->data;
			nowNode = nowNode->next;
		}
		cout << endl;

		return true;
	}
}


//****************顺序栈将10进制数转换为16进制数****************
//实验三.链栈.1，将10进制数转换为16进制数
//输入：存放结果的栈指针、要进行进制转换的十进制数
//输出：十六进制结果存放在传入的栈中
//返回：运行成功返回true，运行失败返回false
bool hexadecimalLinkStack(LinkedStack& res, int num)
{
	const char hexNum[17] = "0123456789ABCDEF";

	if (initialLinkStack(res))
	{
		if (num == 0)
		{
			res->next = new lsNode;
			res->next->data = hexNum[0];
			res->next->next = nullptr;
		}

		while (num != 0)
		{
			if (pushLinkStack(res, hexNum[num % 16])) num /= 16;
			else
			{
				cout << "入栈失败！" << endl;

				return false;
			}
		}

		return true;
	}
	else
	{
		cout << "当前指针已被占用，结果输出失败！" << endl;

		return false;
	}
}


//****************链栈对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的****************
//实验三.链栈.2，判断表达式括号是否合法
//输入：表达式字符串首地址
//返回：表达式括号合法返回true，表达式括号不合法返回false
bool expressionLagelLinkStack(char ex[])
{
	int i;
	LinkedStack exStack = nullptr;
	if (initialLinkStack(exStack))
	{
		for (i = 0; ex[i] != '\0'; i++)
		{
			if (ex[i] == '{' || ex[i] == '[' || ex[i] == '(')
			{
				pushLinkStack(exStack, ex[i]);
			}
			else if (ex[i] == ')' || ex[i] == ']' || ex[i] == '}')
			{
				switch (ex[i])
				{
				case ')':
					if (exStack->next->data == '(')popLinkStack(exStack);
					else return false;
					break;
				case ']':
					if (exStack->next->data == '[')popLinkStack(exStack);
					else return false;
					break;
				case '}':
					if (exStack->next->data == '{')popLinkStack(exStack);
					else return false;
					break;
				default:
					return false;
					break;
				}
			}
		}
		if (exStack->next)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		cout << "未知错误！" << endl;

		return false;
	}
}


//****************************拓展题函数定义******************************
//****************获取所有合法输出序列****************
//实验三.拓展.1，获取所有合法输出序列
//输入：输入序列，中间栈存储位置，输出队列存储位置
//输出：函数内打印合法输出序列
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output)
{
	seqQueue_lagel newInput, newOutput;		//新建变量用于开启新递归时保留原始数据，以开启另一种可能的递归
	seqStack_lagel newMid;

	if (input->front > input->rear)		//当模拟输入栈的队列为空时，表明所有元素都已入栈或出栈
	{
		if (mid->top == -1)				//（输入栈为空的条件下）当中间栈也为空时，说明所有元素都已出栈，可以输出模拟出栈的队列
		{								//循环输出模拟出栈队列
			while (output->front <= output->rear)
			{
				cout << output->data[output->front] << ",";
				output->front++;
			}
			cout << "\t";
		}
		else							//（输入栈为空的条件下）当中间栈不为空时，说明有些已入栈元素还未出栈，要进行出栈操作
		{
			output->data[output->rear + 1] = mid->data[mid->top];
			mid->top--;
			output->rear++;
			getAllOutput(input, mid, output);
		}
	}
	else								//当模拟输入栈的队列非空时，表明还有元素尚未入栈，接下来将有两种情况可以执行
	{
		if (mid->top != -1)				//（输入栈非空的条件下）第一种情况：中间栈不为空时，可以进行中间栈出栈操作
		{
			newInput = *input;			//因为还有第二种情况，所以在进行出栈前还需要保留原始数据
			newMid = *mid;				//拷贝一份原始数据，进行出栈操作
			newOutput = *output;
			newOutput.data[newOutput.rear + 1] = newMid.data[newMid.top];
			newMid.top--;
			newOutput.rear++;
			getAllOutput(&newInput, &newMid, &newOutput);
		}
		//（输入栈非空的条件下）第二种情况：无论中间栈是否为空，都可以进行中间栈入栈操作
		//第一种情况已经拷贝了一份数据进行操作，因此这里可以直接用原始数据进行中间栈入栈操作
		mid->data[mid->top + 1] = input->data[input->front];
		mid->top++;
		input->front++;
		getAllOutput(input, mid, output);
	}
}



//****************判断给定输出序列是否是给定输入序列的合法输出序列****************
//实验三.拓展.2，判断给定输出序列是否是给定输入序列的合法输出序列
//输入：给定输入序列，给定输出序列
//返回：合法返回true，非法返回false
//注意：只适用于单调递增输入序列
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output)
{
	sStack_lagel mid = {					//新建中间栈
		{},
		-1
	};

	while (input->front <= input->rear)
	{									//输入与输出元素相同，表示该元素一入栈就出栈
		if (input->data[input->front] == output->data[output->front])
		{
			input->front++;
			output->front++;
		}								//输入元素小于输出元素，表示该输入元素入栈后尚未出栈
		else if (input->data[input->front] < output->data[output->front])
		{
			mid.top++;
			mid.data[mid.top] = input->data[input->front];
			input->front++;
		}								//输入元素大于输出元素，表示在该输入元素入栈之前有输出元素出栈
		else
		{								//中间栈顶元素若于该输出元素相等，则表明确实是该元素出栈
			if (mid.data[mid.top] == output->data[output->front])
			{
				mid.top--;
				output->front++;
			}							//反之则表明输出序列不合法
			else
			{
				return false;
			}
		}
	}
	while (mid.top != -1)
	{
		if (mid.data[mid.top] == output->data[output->front])
		{
			mid.top--;
			output->front++;
		}
		else
		{
			return false;
		}
	}
	return true;
}



//****************辅助函数：指定数组创建队列****************
//输入：需要创建的队列指针
//返回：创建头结点成功返回true，创建失败返回false
bool creatQueneArr(seqQueue_lagel* Q, int num)
{
	int i = 0;
	const int arr[4][MAXLEN_1] = {
		{1,2,3,4,5},
		{5,2,1,3,4},
		{3,4,2,1,5},
		{3,4,1,2,5}
	};

	Q->front = 0;
	Q->rear = -1;

	for (; i < MAXLEN_1; i++)
	{
		Q->data[i] = arr[num - 1][i];
		Q->rear++;
	}

	return true;
}


//****************辅助函数：打印队列****************
//输入：需要打印的队列指针
void printQuene(seqQueue_lagel* Q)
{
	int i = 0;

	for (; i < MAXLEN_1; i++)
	{
		cout << Q->data[i];
	}

	cout << endl;
}