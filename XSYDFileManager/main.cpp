#include <iostream>
#include "XSYDManageFile.h"
int main(int argc, char** argv){
	clsXSYDManageFile *MyFile = new clsXSYDManageFile(); //new ���ص���ָ��,���ǿ�������߱�����*,����ʱ->�����ǿ����ұ߼�*,����ʱXXX.func 
	XSYDCharArray MyContent;
	//int MyResult = MyFile->WriteFile("D:\\CT.txt","A greet from VS OLD QIUFENG");
	XSYDCharArray MyRST = MyFile->ReadFile("D:\\CT.txt");
	std::cout << "��ȡ���:" << MyRST.StartAddr << std::endl;
	MyFile->ReleaseFileRead(MyRST);
	system("pause");
	//std::cout << MyResult << std::endl;
}