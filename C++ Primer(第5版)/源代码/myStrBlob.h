#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;//为vector<string>::size_type定义别名size_type
	StrBlob();//默认构造函数
	StrBlob(initializer_list<string> i1);//含参数的构造函数
	size_type size() const { return data->size(); }//返回智能指针指向的vector的大小（计算vector中含有多少个string）
	bool empty() const { return data->empty(); }//判断该智能指针指向的vector是否为空
	void push_back(const string &t) { data->push_back(t); }//增加元素
	void pop_back();//删除元素

	//元素访问：目前未搞懂这几个函数的意义
	string& front();
	const string& front() const;//可以引用数据成员（常与非常都可以），返回常string
	string& back();
	const string& back() const;//可以引用数据成员（常与非常都可以），返回常string
private:
	shared_ptr<vector<string>> data;//智能指针data：类型为——类型为string的vector容器
	void check(size_type i, const string &msg) const;//如果data[i]不合法，跑出异常信息msg
};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}//使用make_shared初始化智能指针
StrBlob::StrBlob(initializer_list<string> i1):data(make_shared<vector<string>>(i1)){}//make_shared<数据类型>(初始化参数)

void StrBlob::check(size_type i, const string &msg) const//常成员函数，只能引用常数据成员和非常数据成员，而不能改变他们
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()//返回智能指针所指向vector<string>当前的前一个string数据
{
	check(0, "front on empty StrBlob");//如果vector为空，check会抛出一个异常 
	cout << this << endl;
	return data->front();
}

const string& StrBlob::front() const//返回智能指针所指向vector<string>当前的前一个string数据
{
	check(0, "front on empty StrBlob");//如果vector为空，check会抛出一个异常 
	cout << this << endl;
	return data->front();
}

string& StrBlob::back()//返回智能指针所指向vector<string>当前的后一个string数据
{
	check(0, "back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	cout << this << endl;
	return data->back();
}

const string& StrBlob::back() const//返回智能指针所指向vector<string>当前的后一个string数据
{
	check(0, "back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	cout << this << endl;
	return data->back();
}


void StrBlob::pop_back()//删除vector里面所有数据
{
	check(0, "pop_back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	data->pop_back();
}