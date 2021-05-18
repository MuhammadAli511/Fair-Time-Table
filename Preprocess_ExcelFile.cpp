#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream m;
	ofstream m2;
	m.open("19I-0417_Facts.pl");
	string str;
	bool check = false;
	while (!m.eof())
	{
		check = false;
		string str2 = "";
		getline(m,str);
		int bracket_open = 0;
		int bracket_close = 0;
		bool bracket_closing = false;
		for (int i = 0 ; i < str.length() ; i++)
		{
			if (int(str[i]) >= 65 && int(str[i]) <= 90 || int(str[i]) >= 97 && int(str[i]) <= 122 || int(str[i]) == 40 || int(str[i]) == 41 || int(str[i]) == 44 || int(str[i]) >= 48 && int(str[i]) <= 57)
			{
				str2 += char(tolower(str[i]));
			}
			if (str[i] == '(')
			{
				bracket_open++;
			}
			if (str[i] == '(' && bracket_open == 1)
			{
				str2 += "\"";
			}
			if (str[i+1] == ',')
			{
				str2 += "\"";
			}
			if (str[i] == ',')
			{
				str2 += "\"";
			}
			if (str[i+1] == ')')
			{
				bracket_close++;
			}
			if (str[i+1] == ')' && bracket_close == 1 && str[i+2] != ')')
			{
				str2 += "\"";
			}
			if (str[i+1] == ')' && bracket_close == 2)
			{
				str2 += "\"";
			}
		}
		int size = str2.length();
		if (str2.length() > 5)
		{
			if (str2[size] != '.')
			{
				str2 += ".";
			}
			m2.open("19I-0417_Processed.pl",ios::app);
			m2 << str2 << endl;
			m2.close();
		}
	}
}
