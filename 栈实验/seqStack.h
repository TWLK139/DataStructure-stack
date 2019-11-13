//**********************//
//������ʵ��ͷ�ļ�		//
//������1������ͷ�ļ�	//
//		2��ջ����		//
//		3����������		//
//		4����������		//
//**********************//


#ifndef STACK_H

#define STACK_H

#include<iostream>

#define elementType char
#define elementTypeL int

using namespace std;

#endif // !STACK_H

//*********************˳��ջ�ṹ����***********************//
#define MAXLEN 100											//
															//
typedef struct sStack										//
{															//
	elementType data[MAXLEN];			//���ջԪ��		//
	int top;							//ջ��ָʾ��		//
}seqStack;													//
//**********************************************************//

//**********************��ջ�ṹ����************************//
typedef struct lsNode										//
{															//
	elementType data;					//��ջ���������	//
	struct lsNode* next;				//��ջ���ָ����	//
}sNode, * LinkedStack;										//
//**********************************************************//

//********************��չʵ��ṹ����**********************//
//����������кϷ��Է�������󳤶�							//
#define MAXLEN_1 5											//
															//
//����������кϷ��Է�����ջ�����							//
//ʹ���������й�ͬģ��һ��ջ����ջ��ջ�����ڽ�����		//
typedef struct sQueue_lagel									//
{															//
	elementTypeL data[MAXLEN_1];							//
	int front;												//
	int rear;												//
} seqQueue_lagel;											//
															//
//ʹ��һ���м�ջ����ģ��ʱ����ջ����δ��ջ��Ԫ��			//
typedef struct sStack_lagel									//
{															//
	elementTypeL data[MAXLEN_1];							//
	int top;												//
} seqStack_lagel;											//
//**********************************************************//


//******************************************************��������************************************************************//
//˳��ջ��������																											//
void initialSeqStack(seqStack& S);														//��ʼ��˳��ջ						//
bool pushSeqStack(seqStack& S, elementType x);											//˳��ջ��ջ						//
bool popSeqStack(seqStack& S);															//˳��ջ��ջ						//
bool showSeqStack(seqStack& S);															//��ӡ˳��ջ��Ԫ��					//
bool hexadecimal(seqStack& res, int num);												//˳��ջ��10������ת��Ϊ16������	//
bool expressionLagel(char ex[]);														//˳��ջ�жϱ��ʽ�����Ƿ�Ϸ�		//
//��ջ��������																												//
bool initialLinkStack(LinkedStack& top);												//��ʼ����ջ						//
bool pushLinkStack(LinkedStack& top, elementType x);									//��ջ��ջ							//
LinkedStack popLinkStack(LinkedStack& top);												//��ջ��ջ							//
bool destroyLinkStack(LinkedStack& top);												//������ջ							//
bool showLinkStack(LinkedStack& top);													//��ӡ��ջ��Ԫ��					//
bool hexadecimalLinkStack(LinkedStack& res, int num);									//��ջ��10������ת��Ϊ16������		//
bool expressionLagelLinkStack(char ex[]);												//��ջ�жϱ��ʽ�����Ƿ�Ϸ�		//
//��չʵ�麯��������������кϷ����ж�																						//
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output);	//���ָ���������е����кϷ��������//
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output);						//�ж���������Ƿ�Ϸ�				//
bool creatQueneArr(seqQueue_lagel* Q, int num);											//ָ�����鴴������					//
void printQuene(seqQueue_lagel* Q);														//��ӡ����							//
//**************************************************************************************************************************//


//******************************��������********************************

//***************************˳��ջ��������*****************************
//****************������������ʼ��˳��ջ****************
//������������ʼ��˳��ջ
//���룺��Ҫ��ʼ����˳��ջָ��
void initialSeqStack(seqStack& S)
{
	S.top = -1;
}


//****************����������˳��ջ��ջ****************
//������������ջ
//���룺ջ������Ԫ��
//���أ�ջ������false������ɹ�����true
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


//****************����������˳��ջ��ջ****************
//������������ջ
//���룺ջ
//���أ�ջ�շ���false���ɹ���ջ����true
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


//****************������������ӡ˳��ջ****************
//������������ӡջ
//���룺��Ҫ��ӡ��˳��ջָ��
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
		cout << "��ǰջδ��ʼ����" << endl;

		return false;
	}
}


//****************˳��ջ��10������ת��Ϊ16������****************
//ʵ����.˳��ջ.1����10������ת��Ϊ16������
//���룺��Ž����ջָ�롢Ҫ���н���ת����ʮ������
//�����ʮ�����ƽ������ڴ����ջ��
//���أ����гɹ�����true������ʧ�ܷ���false
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
			cout << "ջ�������" << endl;

			return false;
		}
	}

	return true;
}


//****************˳��ջ�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ���****************
//ʵ����.˳��ջ.2���жϱ��ʽ�����Ƿ�Ϸ�
//���룺���ʽ�ַ����׵�ַ
//���أ����ʽ���źϷ�����true�����ʽ���Ų��Ϸ�����false
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

//****************************��ջ��������******************************
//****************������������ʼ����ջ****************
//���룺��Ҫ��ʼ������ջָ��
//���أ�����ͷ���ɹ�����true������ʧ�ܷ���false
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
		cout << "��ǰջ�Ѵ����������ٺ��ٴ���" << endl;

		return false;
	}
}


//****************������������ջ��ջ****************
//������������ջ��ջ
//���룺ջ������Ԫ��
//���أ�����ɹ�����true������ʧ�ܷ���false
bool pushLinkStack(LinkedStack& top, elementType x)
{
	LinkedStack newNode;

	if (top == nullptr)
	{
		cout << "��ǰջδ������" << endl;

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


//****************������������ջ��ջ****************
//������������ջ��ջ
//���룺ջ��ָ��
//���أ�ջ�շ���nullptr���ɹ���ջ����ջ��ָ��
LinkedStack popLinkStack(LinkedStack& top)
{
	LinkedStack endNode;

	if (top == nullptr)
	{
		cout << "��ǰջδ������" << endl;

		return nullptr;
	}
	else if (top->next == nullptr)
	{
		cout << "��ǰջ�ѿգ�" << endl;

		return nullptr;
	}
	else
	{
		endNode = top->next;
		top->next = endNode->next;

		return endNode;
	}
}


//****************����������������ջ****************
//������������������
//���룺��Ҫ���ٵ���ջָ��
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
			delete(top);				//ָ��delete֮��Ϊnull
			top = nullptr;
		}
	}

	if (!top) return true;
	else return false;
}


//****************������������ӡ��ջ****************
//������������ӡ��ջ
//���룺��Ҫ��ӡ����ջָ��
bool showLinkStack(LinkedStack& top)
{
	LinkedStack nowNode = top;

	if (top == nullptr)
	{
		cout << "��ǰջδ������" << endl;

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


//****************˳��ջ��10������ת��Ϊ16������****************
//ʵ����.��ջ.1����10������ת��Ϊ16������
//���룺��Ž����ջָ�롢Ҫ���н���ת����ʮ������
//�����ʮ�����ƽ������ڴ����ջ��
//���أ����гɹ�����true������ʧ�ܷ���false
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
				cout << "��ջʧ�ܣ�" << endl;

				return false;
			}
		}

		return true;
	}
	else
	{
		cout << "��ǰָ���ѱ�ռ�ã�������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************��ջ�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ���****************
//ʵ����.��ջ.2���жϱ��ʽ�����Ƿ�Ϸ�
//���룺���ʽ�ַ����׵�ַ
//���أ����ʽ���źϷ�����true�����ʽ���Ų��Ϸ�����false
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
		cout << "δ֪����" << endl;

		return false;
	}
}


//****************************��չ�⺯������******************************
//****************��ȡ���кϷ��������****************
//ʵ����.��չ.1����ȡ���кϷ��������
//���룺�������У��м�ջ�洢λ�ã�������д洢λ��
//����������ڴ�ӡ�Ϸ��������
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output)
{
	seqQueue_lagel newInput, newOutput;		//�½��������ڿ����µݹ�ʱ����ԭʼ���ݣ��Կ�����һ�ֿ��ܵĵݹ�
	seqStack_lagel newMid;

	if (input->front > input->rear)		//��ģ������ջ�Ķ���Ϊ��ʱ����������Ԫ�ض�����ջ���ջ
	{
		if (mid->top == -1)				//������ջΪ�յ������£����м�ջҲΪ��ʱ��˵������Ԫ�ض��ѳ�ջ���������ģ���ջ�Ķ���
		{								//ѭ�����ģ���ջ����
			while (output->front <= output->rear)
			{
				cout << output->data[output->front] << ",";
				output->front++;
			}
			cout << "\t";
		}
		else							//������ջΪ�յ������£����м�ջ��Ϊ��ʱ��˵����Щ����ջԪ�ػ�δ��ջ��Ҫ���г�ջ����
		{
			output->data[output->rear + 1] = mid->data[mid->top];
			mid->top--;
			output->rear++;
			getAllOutput(input, mid, output);
		}
	}
	else								//��ģ������ջ�Ķ��зǿ�ʱ����������Ԫ����δ��ջ�����������������������ִ��
	{
		if (mid->top != -1)				//������ջ�ǿյ������£���һ��������м�ջ��Ϊ��ʱ�����Խ����м�ջ��ջ����
		{
			newInput = *input;			//��Ϊ���еڶ�������������ڽ��г�ջǰ����Ҫ����ԭʼ����
			newMid = *mid;				//����һ��ԭʼ���ݣ����г�ջ����
			newOutput = *output;
			newOutput.data[newOutput.rear + 1] = newMid.data[newMid.top];
			newMid.top--;
			newOutput.rear++;
			getAllOutput(&newInput, &newMid, &newOutput);
		}
		//������ջ�ǿյ������£��ڶ�������������м�ջ�Ƿ�Ϊ�գ������Խ����м�ջ��ջ����
		//��һ������Ѿ�������һ�����ݽ��в���������������ֱ����ԭʼ���ݽ����м�ջ��ջ����
		mid->data[mid->top + 1] = input->data[input->front];
		mid->top++;
		input->front++;
		getAllOutput(input, mid, output);
	}
}



//****************�жϸ�����������Ƿ��Ǹ����������еĺϷ��������****************
//ʵ����.��չ.2���жϸ�����������Ƿ��Ǹ����������еĺϷ��������
//���룺�����������У������������
//���أ��Ϸ�����true���Ƿ�����false
//ע�⣺ֻ�����ڵ���������������
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output)
{
	sStack_lagel mid = {					//�½��м�ջ
		{},
		-1
	};

	while (input->front <= input->rear)
	{									//���������Ԫ����ͬ����ʾ��Ԫ��һ��ջ�ͳ�ջ
		if (input->data[input->front] == output->data[output->front])
		{
			input->front++;
			output->front++;
		}								//����Ԫ��С�����Ԫ�أ���ʾ������Ԫ����ջ����δ��ջ
		else if (input->data[input->front] < output->data[output->front])
		{
			mid.top++;
			mid.data[mid.top] = input->data[input->front];
			input->front++;
		}								//����Ԫ�ش������Ԫ�أ���ʾ�ڸ�����Ԫ����ջ֮ǰ�����Ԫ�س�ջ
		else
		{								//�м�ջ��Ԫ�����ڸ����Ԫ����ȣ������ȷʵ�Ǹ�Ԫ�س�ջ
			if (mid.data[mid.top] == output->data[output->front])
			{
				mid.top--;
				output->front++;
			}							//��֮�����������в��Ϸ�
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



//****************����������ָ�����鴴������****************
//���룺��Ҫ�����Ķ���ָ��
//���أ�����ͷ���ɹ�����true������ʧ�ܷ���false
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


//****************������������ӡ����****************
//���룺��Ҫ��ӡ�Ķ���ָ��
void printQuene(seqQueue_lagel* Q)
{
	int i = 0;

	for (; i < MAXLEN_1; i++)
	{
		cout << Q->data[i];
	}

	cout << endl;
}