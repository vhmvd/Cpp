#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char operand;
	unsigned long long varA;
	unsigned long long varB;
	unsigned long long result;
	bool flag = true;
	while(flag)
	{
		cout << "\nBitwise Operation Calculator - CS130 - 64 bits - Sample Solution\n\n";
		cout << "Enter one of the following choices:\n";
		cout << "& - AND\n| - OR\n^ - XOR\n~ - NOT\n- - Negate\n< - Left Shift  (Logical shift only)\n> - Right Shift (Logical shift only)\n# - Stop Execution\n";
		cin >> operand;
		switch (operand)
		{
		case '&':
			cout << "\nEnter first and second operand:\n";
		  cin >> varA >> varB;
			result = varA & varB;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '|':
		  cout << "\nEnter first and second operand:\n";
		  cin >> varA >> varB;
			result = varA | varB;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '^':
		  cout << "\nEnter first and second operand:\n";
		  cin >> varA >> varB;
			result = varA ^ varB;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '~':
		  cout << "\nEnter operand:\n";
		  cin >> varA;
			result = ~varA;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '-':
		  cout << "\nEnter operand:\n";
		  cin >> varA;
			result = -varA;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '<':
		  cout << "\nEnter first and second operand:\n";
		  cin >> varA >> varB;
			result = varA<<varB;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '>':
		  cout << "\nEnter first and second operand:\n";
		  cin >> varA >> varB;
			result = varA<<varB;
			cout << "Result: " << std::setbase(10) << result << " [Hexadecimal:" << std::setbase(16) << setw(8) << result << ']' << endl;  
			break;
		case '#':
		  cout << "\nCalculation ended";
			flag = false;
		  break;
		default:
			cout << "\nInput error, enter choice and values again.\n";
			break;
		}
	}
}
