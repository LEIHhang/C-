#include<iostream>
//模拟写一个 temeplate method 模板方法
//模拟从打开一个文件的过程
using namespace std;

class CDocument
{
public:
	void OnFileOpen()
	{
		//这里省略步骤用输出代替步骤
		cout << "dialog..." << endl;
		cout << "check file status..." << endl;
		cout << "open file ..." << endl;
		Serialize();
		cout << "close file..." << endl;
		cout << "updata all views..." << endl;
	}
	virtual void Serialize() { }
};

class CMyDoc :public CDocument
{
public:
	virtual void Serialize()
	{
		//只有应用程序本身才知道如何获取自身的数据
		cout << "CMyDoc::serialize()" << endl;
	}
};

int main()
{
	CMyDoc myDoc;//假设对应打开文件
	myDoc.OnFileOpen();
	//理解上面这行代码。
	//CDocumnet::OnFileOpen(&myDoc)
	//调用的是父类的函数，传递的参数其实是this指针
	//通过this指针调用到自己的Serialize()函数。
	//通过这样的方法就是写出一个框架也就是template methond，
	//子类通过修改父类提供的功能，完成同类型但具体有些许不同的任务。
	//减少了编程的工作量，也就是造轮子。
	//模板方法模型是一种行为设计模型。
	//模板方法是一个定义在父类别的方法，
	//在模板方法中会呼叫多个定义在父类别的其他方法，
	//而这些方法有可能只是抽象方法并没有实作，
	//模板方法仅决定这些抽象方法的执行顺序，
	//这些抽象方法的实作由子类别负责，并且子类别不允许覆写模板方法。
}