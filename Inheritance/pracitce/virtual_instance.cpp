#include<iostream>
//ģ��дһ�� temeplate method ģ�巽��
//ģ��Ӵ�һ���ļ��Ĺ���
using namespace std;

class CDocument
{
public:
	void OnFileOpen()
	{
		//����ʡ�Բ�����������沽��
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
		//ֻ��Ӧ�ó������֪����λ�ȡ���������
		cout << "CMyDoc::serialize()" << endl;
	}
};

int main()
{
	CMyDoc myDoc;//�����Ӧ���ļ�
	myDoc.OnFileOpen();
	//����������д��롣
	//CDocumnet::OnFileOpen(&myDoc)
	//���õ��Ǹ���ĺ��������ݵĲ�����ʵ��thisָ��
	//ͨ��thisָ����õ��Լ���Serialize()������
	//ͨ�������ķ�������д��һ�����Ҳ����template methond��
	//����ͨ���޸ĸ����ṩ�Ĺ��ܣ����ͬ���͵�������Щ��ͬ������
	//�����˱�̵Ĺ�������Ҳ���������ӡ�
	//ģ�巽��ģ����һ����Ϊ���ģ�͡�
	//ģ�巽����һ�������ڸ����ķ�����
	//��ģ�巽���л���ж�������ڸ���������������
	//����Щ�����п���ֻ�ǳ��󷽷���û��ʵ����
	//ģ�巽����������Щ���󷽷���ִ��˳��
	//��Щ���󷽷���ʵ����������𣬲������������дģ�巽����
}