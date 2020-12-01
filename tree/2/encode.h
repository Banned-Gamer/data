#ifndef ENCODE_H
#define ENCODE_h

#include "Global.h"
class Encoding
{
private:
	node* root;
	long long all_long;
	map<char, int>often;
	int llsize;
	string table[365];
	string en_string;
	priority_queue<node*, vector<node*>, cmp>huff;
public:
	void count(unsigned char* str,int x)
	{
		for (int i = 0; i < x; i++)
		{
			if (often.find(str[i]) != often.end())
			{
				often[str[i]]++;
			}
			else
			{
				often[str[i]] = 1;
			}
		}
		return;
	}
	
	void input()
	{
		fseek(IN, 0, SEEK_END);
		int l_size = ftell(IN);
		llsize = l_size;
		rewind(IN);

		unsigned char* buffer;
		buffer = (unsigned char*)malloc(128);
		while (l_size >= 128)
		{
			fread(buffer, 1, 128, IN);
			l_size -= 128;
			count(buffer,128);
		}
		fread(buffer, 1, l_size, IN);
		count(buffer, l_size);
	}

	void pre_huff()
	{
		map<char, int>::iterator iter;
		for (iter = often.begin(); iter != often.end(); iter++)
		{
			pair <const char, int> temp = *iter;
			node* now = new node(1, temp.first, temp.second);
			huff.push(now);
		}
	}
	
	void huffman1()
	{
		node* now1, * now2;
		while (huff.size() > 1)
		{
			now1 = huff.top();
			huff.pop();
			now2 = huff.top();
			huff.pop();
			node* new_tree;
			new_tree = new node(true, now1->fre + now2->fre);
			new_tree->left = now1;
			new_tree->right = now2;
			huff.push(new_tree);
		}
		root = huff.top();
		string temp = "";
		huffman2(root,temp);
		return;
	}
	
	void huffman2(node* now,string str)
	{
		if (now->is_child)
		{
			table[now->var] = str;
			all_long += str.size() * now->fre;
		}
		if (now->left != NULL)
		{
			node* left = now->left;
			huffman2(left,str+'0');
		}
		if (now->right != NULL)
		{
			node* right = now->right;
			huffman2(right,str+'1');
		}
		return;
	}

	void out_table()
	{
		int var_long=0;
		char a;
		for (int i = 0; i < 256; i++)
		{
			if(!table[i].empty())
			{
				var_long++;
			}
		}

		fwrite(&var_long, sizeof(int), 1, OUT);

		for (int i = 0; i < 256; i++)
		{
			if(!table[i].empty())
			{
				Out_table temp;
				temp.var = i;
				temp.size = table[i].size();
				fwrite(&temp, sizeof(temp), 1, OUT);

				for (int j = 0; j < table[i].length(); j++)
				{
					a = table[i][j];
					fwrite(&a, sizeof(a), 1, OUT);
				}
			}
		}
		return;
	}

	unsigned char string_two(string str, int s_long)
	{
		unsigned char temp = 0;
		for (int i = 0; i < s_long; i++)
		{
			temp = (temp << 1);
			if (str[i] == '1')
				temp |= 1;
		}
		temp <<= (8 - s_long);
		return temp;
	}
	
	void out_page(unsigned char* page,int s_long)
	{
		unsigned char temp;
		for(int i=0;i<s_long;i++)
		{
			en_string += table[page[i]];
			if (en_string.size() > 7)
			{
				temp = string_two(en_string, 8);
				fwrite(&temp, sizeof(temp),1,OUT);
				en_string = &en_string[8];
			}
		}
	}
	void encode()
	{
		input();
		pre_huff();
		huffman1();
		out_table();
		
		int l_size = llsize;
		rewind(IN);
		unsigned char* buffer;
		buffer = (unsigned char*)malloc(128);
		while (l_size >= 128)
		{
			fread(buffer, 1, 128, IN);
			l_size -= 128;
			out_page(buffer, 128);
		}
		fread(buffer, 1, l_size, IN);
		out_page(buffer, l_size);
		return;
	}
};
#endif