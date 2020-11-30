#ifndef DECODE_H
#define DECODE_H

#include "Global.h"

class Decode
{
private:
	string table[365];
	long long a_long;
	node* root;
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

	void huff_tree1()
	{
		root = new node();
		for (int i = 0; i < 256; i++)
		{
			if(!table[i].empty())
			{
				huff_tree2(root, i, table[i]);
			}
		}
	}
	void huff_tree2(node* now,unsigned char var,string s_table)
	{
		if(s_table.empty())
		{
			now->is_child = true;
			now->var = var;
			return;
		}
		if(s_table[0]=='0')
		{
			if (now->left == NULL)
			{
				now->left = new node;
			}
			huff_tree2(now->left, var, &s_table[1]);
		}
		else
		{
			if (now->right == NULL)
			{
				now->right = new node;
			}
			huff_tree2(now->right, var, &s_table[1]);
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
	void input_data_write()
	{
		fread(&a_long, sizeof(a_long), 1, IN);
		unsigned char now;
		node* tree = root;
		string str;
		long long stand = 8;
		while(a_long>0)
		{
			tree = root;
			fread(&now, sizeof(now), 1, IN);
			str = two_string(now,8);
			
			for (int i = 0; i < stand; i++)
			{
				if (str[i] == '0')
				{
					tree = tree->left;
				}
				else
				{
					tree = tree->right;
				}
				if(tree->is_child==1)
				{
					fwrite(&tree->var, sizeof(unsigned char), 1, OUT);
					break;
				}
			}
			a_long -= 8;
		}
	}
	void decode()
	{
		input_table();
		huff_tree1();
		input_data_write();
		return;
	}
};




#endif


