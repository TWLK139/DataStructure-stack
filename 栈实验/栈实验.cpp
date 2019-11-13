//**********************//
//栈实验主程序			//
//**********************//

#include"seqStack.h"

int main(void)
{
	int order = NULL;
	seqStack S;
	LinkedStack lS = nullptr;
	seqQueue_lagel input = { {1,2,3,4,5},0,4 }, output = { {},0,-1 };
	seqStack_lagel mid = { {},-1 };
	elementTypeL elementIn;
	char ex_1[32] = "(1+2)+{2-7/(34+3)^[(2+4)*4]}*90";
	char ex_2[32] = "(1+2]+{2-7/(34+3)^[(2+4)*4)}*90";

	while (1)
	{
		cout << "实验三：栈实验" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*\t*\t*\t*第一组：顺序栈*\t*\t*\t*" << endl;
		cout << "*1，将10进制数转换为16进制数。\t\t\t\t\t*" << endl;
		cout << "*2，判断表达式括号是否合法。\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t*\t*\t*第二组：链  栈*\t*\t*\t*" << endl;
		cout << "*3，将10进制数转换为16进制数。\t\t\t\t\t*" << endl;
		cout << "*4，判断表达式括号是否合法。\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t*\t*\t*第三组：栈拓展*\t*\t*\t*" << endl;
		cout << "*5，判定是否是合法输出序列。\t\t\t\t\t*" << endl;
		cout << "*6，求出所有可能的出栈序列。\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据（十进制数为：4）：" << endl;
			hexadecimal(S, 4);
			cout << "转换为十六进制数为：" << endl << "\t";
			showSeqStack(S);
			//第一组测试结束，重置顺序栈，便于下次测试****************************
			S.top = -1;
			cout << "测试结束，顺序栈已重置！" << endl;
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据（十进制数为：11）：" << endl;
			hexadecimal(S, 11);
			cout << "转换为十六进制数为：" << endl << "\t";
			showSeqStack(S);
			//第二组测试结束，重置顺序栈，便于下次测试****************************
			S.top = -1;
			cout << "测试结束，顺序栈已重置！" << endl;
			cout << endl;
			//********************************************************************
			//第三组测试**********************************************************
			cout << "第三组实验数据（十进制数为：254）：" << endl;
			hexadecimal(S, 254);
			cout << "转换为十六进制数为：" << endl << "\t";
			showSeqStack(S);
			//第三组测试结束，重置顺序栈，便于下次测试****************************
			S.top = -1;
			cout << "测试结束，顺序栈已重置！" << endl;
			cout << endl;
			//********************************************************************
			//第四组测试**********************************************************
			cout << "第四组实验数据（十进制数为：1357）：" << endl;
			hexadecimal(S, 1357);
			cout << "转换为十六进制数为：" << endl << "\t";
			showSeqStack(S);
			//第四组测试结束，重置顺序栈，便于下次测试****************************
			S.top = -1;
			cout << "测试结束，顺序栈已重置！" << endl;
			cout << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "当前表达式：" << ex_1 << endl;
			if (expressionLagel(ex_1)) cout << "当前表达式合法！" << endl;
			else cout << "当前表达式非法！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "当前表达式：" << ex_2 << endl;
			if (expressionLagel(ex_2)) cout << "当前表达式合法！" << endl;
			else cout << "当前表达式非法！" << endl;
			//********************************************************************
			break;
		case 3:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据（十进制数为：4）：" << endl;
			hexadecimalLinkStack(lS, 4);
			cout << "转换为十六进制数为：" << endl << "\t";
			showLinkStack(lS);
			//第一组测试结束，销毁链栈，便于下次测试******************************
			if (destroyLinkStack(lS)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据（十进制数为：11）：" << endl;
			hexadecimalLinkStack(lS, 11);
			cout << "转换为十六进制数为：" << endl << "\t";
			showLinkStack(lS);
			//第二组测试结束，销毁链栈，便于下次测试******************************
			if (destroyLinkStack(lS)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			cout << endl;
			//********************************************************************
			//第三组测试**********************************************************
			cout << "第三组实验数据（十进制数为：254）：" << endl;
			hexadecimalLinkStack(lS, 254);
			cout << "转换为十六进制数为：" << endl << "\t";
			showLinkStack(lS);
			//第三组测试结束，销毁链栈，便于下次测试******************************
			if (destroyLinkStack(lS)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			cout << endl;
			//********************************************************************
			//第四组测试**********************************************************
			cout << "第四组实验数据（十进制数为：1357）：" << endl;
			hexadecimalLinkStack(lS, 1357);
			cout << "转换为十六进制数为：" << endl << "\t";
			showLinkStack(lS);
			//第四组测试结束，销毁链栈，便于下次测试******************************
			if (destroyLinkStack(lS)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			cout << endl;
			//********************************************************************
			break;
		case 4:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "当前表达式：" << ex_1 << endl;
			if (expressionLagelLinkStack(ex_1)) cout << "当前表达式合法！" << endl;
			else cout << "当前表达式非法！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "当前表达式：" << ex_2 << endl;
			if (expressionLagelLinkStack(ex_2)) cout << "当前表达式合法！" << endl;
			else cout << "当前表达式非法！" << endl;
			//********************************************************************
			break;
		case 5:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "当前需要判断的输出序列为：" << endl;
			if (creatQueneArr(&output, 1))printQuene(&output);
			cout << "判断结果为：" << endl;
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			//第一组测试结束，恢复原始数据，便于下次测试**************************
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "当前需要判断的输出序列为：" << endl;
			if (creatQueneArr(&output, 2))printQuene(&output);
			cout << "判断结果为：" << endl;
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			//第二组测试结束，恢复原始数据，便于下次测试**************************
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			cout << endl;
			//********************************************************************
			//第三组测试**********************************************************
			cout << "第三组实验：" << endl;
			cout << "当前需要判断的输出序列为：" << endl;
			if (creatQueneArr(&output, 3))printQuene(&output);
			cout << "判断结果为：" << endl;
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			//第三组测试结束，恢复原始数据，便于下次测试**************************
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			cout << endl;
			//********************************************************************
			//第四组测试**********************************************************
			cout << "第四组实验：" << endl;
			cout << "当前需要判断的输出序列为：" << endl;
			if (creatQueneArr(&output, 4))printQuene(&output);
			cout << "判断结果为：" << endl;
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			//第四组测试结束，恢复原始数据，便于下次测试**************************
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			cout << endl;
			//********************************************************************
			break;
		case 6:
			system("cls");
			cout << "当前输入序列为：1，2，3，4，5" << endl;
			cout << "该输入序列所有输出序列如下：" << endl;
			getAllOutput(&input, &mid, &output);
			cout << endl;
			//恢复原始数据，便于连续测试
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			break;
		case 0:
			if (destroyLinkStack(lS)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}