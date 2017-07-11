#include "XSYDManageFile.h"
using namespace std;
XSYDCharArray clsXSYDManageFile::ReadPartFile(const char * Path,long StartPos, long ReadLength){
	XSYDCharArray MyResult;
	FILE *myfile; 
	errno_t opennum = fopen_s(&myfile,Path,"r");
	if(opennum != 0){
		//˵���ļ�������,����û��Ȩ�޻�ȡ
		MyResult.Length = 0;
		return MyResult; 
	}
	fseek(myfile,StartPos,SEEK_SET); //�ƶ����û�ָ����StartPosλ�� 
	char *MyTemp = (char*) malloc((ReadLength+1+1)*sizeof(char)); //��Ϊfgetsֻ���ȡn-1��,���ڱ���������λ�ü���һ��\0������,�����ֶ�+1�������ļ�����
	//fgets(MyTemp,ReadLength+1,myfile);
	for (int i = 0;i <= ReadLength;i++) {
		MyTemp[i] = fgetc(myfile);
	}
	MyTemp[ReadLength + 1] = '\0';
	MyResult.Length = ReadLength + 1; //֮ǰ�ֶ�+��1
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
	fseek(myfile,0,SEEK_END); //ǰ�����һ��byte 
	MyResult.Length = (ftell(myfile)/sizeof(char)); 
	
	char *MyTemp = (char*)malloc((MyResult.Length+1+1)*sizeof(char));//��Ϊ��ȡ��ʱ����ȡn+1,Ȼ��������һ����ֹ����,���������ֶ�����+1 ,��һ��+1����ֹ��\0
	rewind(myfile);//�ص��ļ�ͷ 
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
	fseek(myfile,BytesMoved,SEEK_SET); //SEEK_SET �ļ���ͷ SEEK_CUR ��ǰλ�� SEEK_END�ļ�β
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