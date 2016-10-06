#include <iostream>
#include <string>
using namespace std;

string StrCompress(string str);
void PrintStr(string x);

int main()
{
	PrintStr("Russia");
	PrintStr("aabcccccaaa");
	PrintStr("daaaaayyyyyyyuuuuummmm gurl");
	PrintStr("daaaaa yyy yyyyuu uuummmm gurl");
	PrintStr("     daa aaa yyy yyyyuu uuummmm gurl");
	PrintStr("  d aaaaa yy yyyyyuu uuum mmm gurl");
	return 0;
}

void PrintStr(string x)
{
	cout << x << " returns: " << StrCompress(x) << endl;
}

string StrCompress(string str)
{
	//return string
	string retstr = "";

	//length of string passed in
	int inputlength = str.length();

	//temp char for return string input and compare
	char temp = str[0];

	//insert the first char into return string
	retstr += temp;

	//set count to 1 unless initial input is a space
	int charcount = 1;
	if (temp == ' ')
		charcount = 0;

	for (int i = 1; i < inputlength; i++)
	{
		//if the input is a space
		if (str[i] == ' ')
		{
			//if the space is coming after a char
			if (charcount >= 1)
			{
				retstr += ('0' + charcount);
				charcount = 1;
			}
			//add spaces for as many as there are
			while (str[i] == ' ')
			{
				retstr += ' ';
				++i;
			}

			//set next char
			temp = str[i];
			//add char to return string
			retstr += temp;
			//reset count to 1
			charcount = 1;
		}
		//if the current char is the same as the previous
		else if (str[i] == temp)
		{
			//increase the count on number of times the same char happened in a row
			charcount++;
		}
		else
		{
			//insert the number of times char in a row into return string
			retstr += ('0' + charcount);
			
			//reset char count
			charcount = 1;

			//set temp tp new char
			temp = str[i];

			//insert new char into return string
			retstr += temp;

			//check string length
			if (retstr.length() >= inputlength)
			{
				//return original string if return string is larger or equal in length
				return str;
			}
		}
		
	}

	//input the last count to the return string
	retstr += ('0' + charcount);

	//check string length
	if (retstr.length() >= inputlength)
	{
		//return original string
		return str;
	}


	//return compressed string
	return retstr;
}