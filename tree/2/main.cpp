#include "Global.h"
#include "encode.h"
#include "decode.h"
int main()
{
	int mode;
	string IN_file, OUT_file;
	const char* IN_FILE = IN_file.c_str();
	const char* OUT_FILE = OUT_file.c_str();
	cout << "Place choose the mode of program:" << endl;
	cout << "mode 1:encode\tmode 2:decode" << endl;
	cin >> mode;
	cout << "Place input the name of file:" << endl;
	cin >> IN_file;

	int name_long;
	
	if(mode==1)
	{
		IN = fopen(IN_FILE, "rb");
		OUT = fopen("OUT1", "wb");

		int name_long = IN_file.length();
		fwrite(&name_long, sizeof(int), 1, OUT);
		for (int i = 0; i < name_long; i++)
		{
			fwrite(&IN_FILE[i], sizeof(const char), 1, OUT);
		}
		Encoding solo1;
		solo1.encode();
		return 0;
	}
	if (mode == 2) 
	{
		char a;
		IN = fopen(IN_FILE, "rb");
		fread(&name_long, sizeof(int), 1, IN);
		for(int i=0;i<name_long;i++)
		{
			fread(&a, sizeof(a), 1, IN);
			OUT_file += a;
		}
		
		OUT_FILE = OUT_file.c_str();
		cout << OUT_FILE;
		OUT = fopen(OUT_FILE, "wb");
		Decoding solo2;
		solo2.decode();
		return 0;
	}
	cout << "Input error, the program is stop";
	return 0;
}
