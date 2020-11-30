#include "Global.h"
#include "encode.h"
#include "decode.h"
int main()
{
	int mode;
	char* IN_FILE, * OUT_FILE;
	string IN_file;
	cout << "Place choose the mode of program:" << endl;
	cout << "mode 1:encode\tmode 2:decode";
	cin >> mode;
	cout << "Place input the name of file:"<<endl;
	cin >> IN_file;
	
	if(mode==1)
	{
		IN_FILE = (char*)IN_file.data();
		IN_file += ".ban";
		OUT_FILE = (char*)IN_file.data();
		IN = fopen(IN_FILE, "rb");
		OUT = fopen(OUT_FILE, "wb");
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
