#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool checkParentesi(const string& expressio)
{
	stack<char> pilaParentesi;

	bool correcte = true;
	int i = 0;
	while ((i < expressio.size()) and correcte)
	{
		if (expressio[i] == '(')
		{
			pilaParentesi.push(expressio[i]);
			i++;
		}
		else
			if (expressio[i] == ')')
				if (pilaParentesi.empty())
					correcte = false;
				else
				{
					pilaParentesi.pop();
					i++;
				}
			else
				i++;
	}
	if (!pilaParentesi.empty())
		correcte = false;
	return correcte;
}

int main()
{
	string expressio;
	bool correcte;

	expressio = "(((3+5)*(4+2)) + 5)*7)";
	correcte = checkParentesi(expressio);
	cout << "Expressio: " << expressio << endl;
	if (correcte)
		cout << "Expressio correcte" << endl;
	else
		cout << "Expressio NO valida" << endl;
	expressio = "(((3+5)*(4+2) + 5)*7";
	correcte = checkParentesi(expressio);
	cout << "Expressio: " << expressio << endl;
	if (correcte)
		cout << "Expressio correcte" << endl;
	else
		cout << "Expressio NO valida" << endl;
	expressio = "(3+5))*((4+2) + 5*7";
	correcte = checkParentesi(expressio);
	cout << "Expressio: " << expressio << endl;
	if (correcte)
		cout << "Expressio correcte" << endl;
	else
		cout << "Expressio NO valida" << endl;
	expressio = "(((3+5)*(4+2) + 5)*7)";
	correcte = checkParentesi(expressio);
	cout << "Expressio: " << expressio << endl;
	if (correcte)
		cout << "Expressio correcte" << endl;
	else
		cout << "Expressio NO valida" << endl;
	return 0;
}