#include "Global.h"
#include "encode.h"
#include "decode.h"
int main()
{
	int mode;
	char* OUT_FILE;
	string IN_file;
	const char* IN_FILE = IN_file.c_str();
	cout << "Place choose the mode of program:" << endl;
	cout << "mode 1:encode\tmode 2:decode"<<endl;
	cin >> mode;
	cout << "Place input the name of file:"<<endl;
	cin >> IN_file;
	
	if(mode==1)
	{
		IN = fopen(IN_FILE, "rb");
		OUT = fopen("OUT", "wb");

		Encoding solo1;
		solo1.encode();
		return 0;
	}
	if (mode == 2) 
	{
		return 0;
	}
	cout << "Input error, the program is stop";
	return 0;
}
