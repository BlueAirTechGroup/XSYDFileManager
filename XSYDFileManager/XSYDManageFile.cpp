#include "XSYDManageFile.h"
using namespace std;
XSYDCharArray clsXSYDManageFile::ReadPartFile(const char * Path,long StartPos, long ReadLength){
	XSYDCharArray MyResult;
	FILE *myfile; 
	errno_t opennum = fopen_s(&myfile,Path,"r");
	if(opennum != 0){
		//说明文件不存在,或者没有权限获取
		MyResult.Length = 0;
		return MyResult; 
	}
	fseek(myfile,StartPos,SEEK_SET); //移动到用户指定的StartPos位置 
	char *MyTemp = (char*) malloc((ReadLength+1+1)*sizeof(char)); //因为fgets只会读取n-1个,并在被它减掉的位置加上一个\0结束符,我们手动+1抵消他的减即可
	//fgets(MyTemp,ReadLength+1,myfile);
	for (int i = 0;i <= ReadLength;i++) {
		MyTemp[i] = fgetc(myfile);
	}
	MyTemp[ReadLength + 1] = '\0';
	MyResult.Length = ReadLength + 1; //之前手动+了1
	MyResult.StartAddr = MyTemp;
	fclose(myfile);
	return MyResult;
}
XSYDCharArray clsXSYDManageFile::ReadFile(const char * Path){
	XSYDCharArray MyResult; 
	FILE *myfile;
	errno_t opennum = fopen_s(&myfile,Path,"r");
	if(opennum!=0){
		MyResult.Length = 0;
		return MyResult;
	}
	fseek(myfile,0,SEEK_END); //前往最后一个byte 
	MyResult.Length = (ftell(myfile)/sizeof(char)); 
	
	char *MyTemp = (char*)malloc((MyResult.Length+1+1)*sizeof(char));//因为读取的时候会读取n+1,然后后面加上一个终止符号,所以我们手动搭上+1 ,另一个+1是终止符\0
	rewind(myfile);//回到文件头 
	//fgets(MyTemp,MyResult.Length+1,myfile);
	for (int i = 0; i <= MyResult.Length;i++) {
		MyTemp[i] = fgetc(myfile);
	}
	MyTemp[MyResult.Length + 1] = '\0';
	MyResult.StartAddr=MyTemp;
	fclose(myfile);
	return MyResult; 
}
int clsXSYDManageFile::WriteFile(const char * Path, char * Content){
	FILE *myfile;
	errno_t opennum = fopen_s(&myfile,Path, "w+");
	if (opennum != 0) {
		return -1;
	}
	for (int i = 0;i <= strlen(Content);i++) {
		fputc(Content[i], myfile);
	}
	fclose(myfile);
	return 0;
}
int clsXSYDManageFile::WriteFile_Append(const char * Path, char * Content){
	FILE *myfile;
	errno_t opennum = fopen_s(&myfile,Path, "a");
	if (opennum != 0) {
		return -1;
	}
	for (int i = 0;i <= strlen(Content);i++) {
		fputc(Content[i], myfile);
	}
	fclose(myfile);
	return 0;
}
int clsXSYDManageFile::WriteFile_ReplaceAt(long BytesMoved, const char * Path, char * Content){
	FILE *myfile;
	errno_t opennum = fopen_s(&myfile,Path, "w");
	if (opennum != 0) {
		return -1;
	}
	fseek(myfile,BytesMoved,SEEK_SET); //SEEK_SET 文件开头 SEEK_CUR 当前位置 SEEK_END文件尾
	for (int i = 0;i < strlen(Content);i++) {
		fputc(Content[i], myfile);
	}
	fclose(myfile);
	return 0;
}
long clsXSYDManageFile::GetFileLength(const char * Path){
	FILE *myfile;
	errno_t opennum = fopen_s(&myfile,Path, "r");
	if(opennum != 0){
		return -1;
	}
	fseek(myfile,0,SEEK_END);
	long MyLength = ftell(myfile);
	rewind(myfile);
	fclose(myfile);
	return MyLength;
}
void clsXSYDManageFile::ReleaseFileRead(XSYDCharArray MyRST) {
	free(MyRST.StartAddr);
}