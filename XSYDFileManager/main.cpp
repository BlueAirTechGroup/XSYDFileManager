#include <iostream>
#include "XSYDManageFile.h"
int main(int argc, char** argv){
	clsXSYDManageFile *MyFile = new clsXSYDManageFile(); //new 返回的是指针,我们可以在左边变量加*,调用时->或我们可以右边加*,调用时XXX.func 
	XSYDCharArray MyContent;
	//int MyResult = MyFile->WriteFile("D:\\CT.txt","A greet from VS OLD QIUFENG");
	XSYDCharArray MyRST = MyFile->ReadFile("D:\\CT.txt");
	std::cout << "读取结果:" << MyRST.StartAddr << std::endl;
	MyFile->ReleaseFileRead(MyRST);
	system("pause");
	//std::cout << MyResult << std::endl;
}