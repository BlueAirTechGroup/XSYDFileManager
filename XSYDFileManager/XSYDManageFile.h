//形随意动软件工作室[www.xsyds.cn]版权所有
//Copyright BlueAir Tech Group(www.xsyds.cn), all rights reserved
//允许学习,交流,商业使用请联系形随意动工作室官方获得授权
//You are permitted to study and use it while for non commercial use, but you need to contact BlueAir Tech Group if need for commercial use.
#ifndef XSYDManageFile
	#define XSYDManageFile
	//#include <iostream>
	#ifdef linux
	
	#endif
	#ifdef _UNIX
		
	#endif
	#ifdef __WINDOWS_
		//#include <fstream>
	#endif
	#ifdef _WIN32
		//#include <fstream>
	#endif
	#include <stdio.h>
	#include <string.h>
	//#include <stdlib.h>
	//#include <iostream>
	#include <malloc.h>
	using namespace std;
	struct XSYDCharArray{
		long Length;
		char* StartAddr;
	};
	class clsXSYDManageFile{
		private:
		
		public:
			XSYDCharArray ReadPartFile(const char * Path,long StartPos, long ReadLength);
			XSYDCharArray ReadFile(const char * Path);
			int WriteFile(const char * Path, char * Content);
			int WriteFile_Append(const char * Path, char * Content);
			int WriteFile_ReplaceAt(long BytesMoved, const char * Path, char * Content);
			long GetFileLength(const char * Path);
			void ReleaseFileRead(XSYDCharArray MyRST);
	}; 
#endif
