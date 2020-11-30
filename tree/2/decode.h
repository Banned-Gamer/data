#ifndef DECODE_H
#define DECODE_H

#include "Global.h"

class decode
{
private:
	string table[365];
	long long a_long;
public:
	void input_table()
	{
		int a;
		fread(&a, sizeof(a), 1, IN);

		for (int i = 1; i <= a; i++)
		{
			Out_table temp;
			fread(&temp, sizeof(temp), 1, IN);
			string b_table;
			char c_temp;

			for(int i=0;i<temp.size;i++)
			{
				fread(&c_temp, 1, 1, IN);
				b_table += c_temp;
			}
			table[temp.var] = b_table;
		}
		return;
	}
	string  two_string(unsigned char c,int s_long)
	{
		string str;
		for(int i=0;i<=s_long;i++)
		{
			if (c % 2 == 0)
			{
				str += '0';
			}
			else str += '1';
			c = (c >> 1);
		}
		return str;
	}
	void input_data()
	{
		fread(&a_long, sizeof(a_long), 1, IN);
		
	}
};




#endif


