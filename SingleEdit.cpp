#include <iostream>
#include <string>
using namespace std;

bool EditCheck(string str1, string str2);
void PrintTF(string str1, string str2);

int main()
{
	string temp1 = "pale";
	string temp2 = "ple";
	string temp3 = "bale";
	string temp4 = "bake";
	string temp5 = "psale";
	string temp6 = "palese";

	string temp7 = "this is a test";
	string temp8 = "this is y test";

	PrintTF(temp1, temp1);
	PrintTF(temp1, temp2);
	PrintTF(temp1, temp3);
	PrintTF(temp1, temp4);
	PrintTF(temp1, temp5);
	PrintTF(temp1, temp6);
	PrintTF(temp7, temp8);

	return 0;
}

void PrintTF(string str1, string str2)
{
	bool truefalse = EditCheck(str1, str2);

	cout << str1 << " --> " << str2 << " || ";

	if(truefalse)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}

bool EditCheck(string str1, string str2)
{
	//return value (default to false)
	bool retval = false;

	//difference in length between the two strings
	int strlen_difference = (str1.length() - str2.length());

	//bool variable to tell if there's a change found between the strings
	bool edit_found = false;

	//bool for too many edits
	bool too_many = false;

	//
	switch(strlen_difference)
	{
	case -1:		//string2 is 1 char longer than string1 (check insert)

		for(int i = 0, j = 0; i < str1.length(); i++, j++)
		{
			if(!edit_found)
			{
				//if there's a change found from str1 to str2
				if((char)str1[i] != (char)str2[j])
				{
					edit_found = true;
					++j;
				}
			}
			else
			{
				//more than 1 edit
				if((char)str1[i] != (char)str2[j])
				{
					too_many = true;
				}
			}
		}

		//if too_many bool not true, set return variable to true
		if(!too_many)
			retval = true;

		break;
	case 0:			//strings are the same length (check replace)
		//check if the the strings are the same
		if(str1.compare(str2) != 0)
		{
			for(int i = 0; i < str1.length(); i++)
			{
				if(!edit_found)
				{
					//if there's a change found from str1 to str2
					if((char)str1[i] != (char)str2[i])
					{
						edit_found = true;
					}
				}
				else
				{
					//more than 1 edit
					if((char)str1[i] != (char)str2[i])
					{
						too_many = true;
					}
				}
			}

			//if too_many bool not true, set return variable to true
			if(!too_many)
				retval = true;
		}
		else
		{
			//the strings are the same; set return value to true
			retval = true;
		}
		break;
	case 1:			//string1 is 1 char longer than string2 (check remove)

		for(int i = 0, j = 0; i < str2.length(); i++, j++)
		{
			if(!edit_found)
			{
				//if there's a change found from str1 to str2
				if((char)str1[j] != (char)str2[i])
				{
					edit_found = true;
					++i;
				}
			}
			else
			{
				//more than 1 edit
				if((char)str1[j] != (char)str2[i])
				{
					too_many = true;
				}
			}
		}

		//if too_many bool not true, set return variable to true
		if(!too_many)
			retval = true;
		break;
	default:		//one of the strings is 2+ chars longer therefore an auto failure
		break;
	};

	return retval;
}