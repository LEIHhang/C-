////���demo����ѧϰ���ģʽ�ھ�������������
////�����˽����ģʽ�Ļ�������
////���ģʽ����϶�������γ����νṹ�Ա�ʾ���С�����-���֡���ϵ�Ĳ�νṹ
////���ģʽ�Ե����������϶����ʹ�þ���һ���ԣ�Ҳ����ʹ����ͬ�Ľӿڡ�
////�ٸ�������˵�����ļ�ϵͳ��һ��Ŀ¼�ļ��¿��ܻ���һ��Ŀ¼�ļ�����ͨ�ļ���
////����ļ�ϵͳ�Ͳ������ģʽ����ͨ�ļ���Ŀ¼�ļ�����ͬһ�����࣬�����ͬ�Ľӿڡ�
//
////���ģʽ����Ʒ�����
////1.component(���󹹼�)���ӿ��������࣬ΪҶ�ӹ������������������ӿڡ�
////�ڸ��������һЩ���๲�еĽӿڡ��ٴ˹�����Ҫ��ƶ��ӹ�������ɾ��Ľӿڡ�
////2.leaf(Ҷ�ӹ���)��������Ϲ����б�ʾΪ��������Ĺ�����Ҷ�ӽڵ�û���ӽڵ㡣
////3.composite(��������)
////������Ͻṹ�б�ʾ�����ڵ���������ڵ��������ӽڵ�������ӽڵ���������Ҷ�ӽ��Ҳ�����������ڵ㡣
////���ṩ��һ�����������洢�ӽڵ㡣ʵ�����ڳ��󹹼��ж������Ϊ���������ӽڵ�ĸ��ֲ�����
////�������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Component
//{
//public:
//	Component(int ino)
//	{
//		cout << "Component construct..\n";
//		_inode = ino;
//	}
//	~Component()
//	{
//		cout << "Component destruct..\n";
//	}
//	virtual void add(Component* elem)
//	{
//
//	}
//private:
//	int _inode;
//};
//
//
//class Primitive:public Component
//{
//public:
//	//��ʾ���ø��๹�캯��
//	Primitive(int ino) :Component(ino){}
//	~Primitive()
//	{
//		cout << "~Primitive()\n";
//	}
//
//private:
//
//};
//
//class Composite :public Component
//{
//public:
//	Composite(int ino) :Component(ino){}
//	void add(Component* elem)
//	{
//		c.push_back(elem);
//	}
//private:
//	//��������а�����������󹹼������ڶ�̬��ʹ�Բ�ͬ����ĵĲ���Ҳ��һ����
//	vector<Component*> c;
//};
//
//int main()
//{
//	Composite c(1);
//	Primitive p(2);
//	Composite c_2(2);
//	c.add(&p);
//	c.add(&c_2);
//	return 0;
//}