#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stack>

//Напишете програма, която оценява прост аритметичен израз.Изразът представлява условен оператор, 
//който е записан в текстов файл по посочения по - долу начин.Ако бъде оценен до истина, 
//то на екрана трябва да бъде изведен съответният текст, намиращ се в тялото на IF, 
//а в противен случай – се извежда текста след ELSE.Изразът се състои от цифри, 
//които трябва да се сравнят с операторите >, >= , <, <= , == , != .
//Отделните сравнения са разделени с логическите оператори и / или,
//записани като AND / OR.За улеснение, приоритета на операциите е обозначен със скобите “(” “)”.
bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isLetter(char c)
{
	return c >= 'A' && c <= 'Z';
}

int convertCharToNum(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	int charToNum = 0;
	while (isDigit(expr[i]))
	{
		charToNum = (charToNum * 10) + (expr[i++] - '0');
	}
	return charToNum;
}

const std::string constructOperator(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	std::string strOperator = "";
	if (expr[i + 1] == '=')
	{
		if (expr[i] == '>')
		{
			strOperator = ">=";
		}
		else if (expr[i] == '<')
		{
			strOperator = "<=";
		}
		else if (expr[i] == '!')
		{
			strOperator = "!=";
		}
		i += 2;
		return strOperator;
	}
	strOperator += expr[i++];
	return strOperator;
}

bool checkNumbers(int num1, const std::string& op, int num2)
{
	if (op == ">")
	{
		return num1 > num2;
	}
	else if (op == ">=")
	{
		return num1 >= num2;
	}
	else if (op == "<")
	{
		return num1 < num2;
	}
	else if (op == "<=")
	{
		return num1 <= num2;
	}
	else if (op == "==")
	{
		return num1 == num2;
	}

	return num1 != num2;
}

const std::string constructKeyWord(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	std::string word = "";
	while (isLetter(expr[i]))
	{
		word += expr[i++];
	}

	return word;
}

void checkCommandsFromStack(std::stack<std::string>& stack)
{
	std::string rightResult = stack.top(); stack.pop();
	std::string stackCommand = stack.top(); stack.pop();
	std::string leftResult = stack.top(); stack.pop();

	if (stack.top() == "(")
	{
		stack.pop();
	}

	if (stackCommand == "AND")
	{
		(leftResult == "true" && rightResult == "true") ? stack.push("true") : stack.push("false");
	}
	else if (stackCommand == "OR")
	{
		(leftResult == "false" && rightResult == "false") ? stack.push("false") : stack.push("true");
	}
}
std::string evaluateExpression(std::string expression, std::string ifText, std::string elseText)
{
	std::stack<std::string> stack;

	int num1;
	int num2;
	std::string result;
	std::string op;

	size_t expressionSize = expression.size();
	for (size_t i = 0; i < expressionSize; i++)
	{
		if (expression[i] == ' ')
		{
			continue;
		}

		if (expression[i] == '(')
		{
			stack.push("(");
		}
		else if (isDigit(expression[i]))
		{
			num1 = convertCharToNum(expression, i);
			op = constructOperator(expression, i);
			num2 = convertCharToNum(expression, i);

			if (checkNumbers(num1, op, num2))
			{
				stack.push("true");
			}
			else
			{
				stack.push("false");
			}	
		}
		else if (expression[i] == ')')
		{
			checkCommandsFromStack(stack);
		}
		else
		{
			stack.push(constructKeyWord(expression, i));
		}
	}
	return stack.top();
}

void readFromFile(std::string fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Unable to open " << fileName << " file." << std::endl;
		return;
	}

	file.seekg(3, std::ios::beg);

	std::string expression;
	std::getline(file, expression);
	std::string ifText;
	std::getline(file, ifText);
	file.seekg(6, std::ios::cur);
	std::string elseText;
	std::getline(file, elseText);

	file.close();

	std::string result = evaluateExpression(expression, ifText, elseText);

	if (result == "true")
	{
		std::cout << ifText << std::endl;
	}
	else
	{
		std::cout << elseText << std::endl;
	}
}

int main()
{

//      Пример:
//	    IF(5 < 6 AND(9 > 10 OR 8 != 2))
//		Expression is evaluated to true.
//		ELSE
//		Expression is not true.
//		Резултат :
//		Expression is evaluated to true.

	readFromFile("expression.txt");

    return 0;
}

