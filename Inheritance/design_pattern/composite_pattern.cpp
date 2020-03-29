//这个demo用来学习组合模式在具体类中如何设计
//首先了解组合模式的基本概念
//组合模式：组合多个对象形成树形结构以表示具有“整体-部分”关系的层次结构
//组合模式对单个对象和组合对象的使用具有一致性，也就是使用相同的接口。
//举个例子来说明：文件系统。一个目录文件下可能还有一个目录文件或普通文件。
//设计文件系统就采用组合模式。普通文件和目录文件采用同一个父类，设计相同的接口。

//组合模式的设计方法。
//1.component(抽象构件)：接口类或抽象类，为叶子构件和容器构件声明接口。
//在该类中设计一些子类共有的接口。再此构件里要设计对子构建的增删查改接口。
//2.leaf(叶子构件)：他在组合构件中表示为单个对象的构件，叶子节点没有子节点。
//3.composite(容器构件)
//它在组合结构中表示容器节点对象，容器节点对象包含子节点对象，其子节点对象可以是叶子结点也可以是容器节点。
//它提供了一个集合用来存储子节点。实现了在抽象构件中定义的行为，包括对子节点的各种操作。
//具体设计
#include<iostream>
using namespace std;

class Component
{
public:
	Component(int k);
	~Component();

private:
	int _inode;
};

Component::Component(int k)
{
	cout << "Component construct..\n";
	_inode = k;
}

Component::~Component()
{
	cout << "Component destruct..\n";
}