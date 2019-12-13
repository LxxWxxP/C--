#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

//对于StrBlob中的友元声明来说，此前置声明是必要的
class StrBlobStr;
//-----------------------------StrBlob类---------------------------------------------------------------------------------------------------
class StrBlob
{
	friend class StrBlobPtr;
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

	//返回指向首元素和尾后元素的StrBlobPtr
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;//智能指针data：类型为——类型为string的vector容器
	void check(size_type i, const string &msg) const;//如果data[i]不合法，跑出异常信息msg
};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}//使用make_shared初始化智能指针
StrBlob::StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)) {}//make_shared<数据类型>(初始化参数)

void StrBlob::check(size_type i, const string &msg) const//常成员函数，只能引用常数据成员和非常数据成员，而不能改变他们
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()//返回智能指针所指向vector<string>当前的前一个string数据
{
	check(0, "front on empty StrBlob");//如果vector为空，check会抛出一个异常 
	return data->front();
}

const string& StrBlob::front() const//返回智能指针所指向vector<string>当前的前一个string数据
{
	check(0, "front on empty StrBlob");//如果vector为空，check会抛出一个异常 
	return data->front();
}

string& StrBlob::back()//返回智能指针所指向vector<string>当前的后一个string数据
{
	check(0, "back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	return data->back();
}

const string& StrBlob::back() const//返回智能指针所指向vector<string>当前的后一个string数据
{
	check(0, "back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	return data->back();
}


void StrBlob::pop_back()//删除vector里面所有数据
{
	check(0, "pop_back on empty StrBlob");//如果vector为空，check会抛出一个异常 
	data->pop_back();
}
//---------------------------------------------------------------------------------------------------------------------

//----------------------------------StrBlobPtr类----------- -----------------------------------------------------------
class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//声明友元函数
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {  }
	string& deref() const;//解引用
	StrBlobPtr& incr();//前缀递增
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;//所检查成功，check返回一个指向vector的shared_ptr
	weak_ptr<vector<string>> wptr;//保存一个weak_ptr，意味着底层vector可能被销毁
	size_t curr;//保存数组中的当前位置
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();//检查vector还在吗？
	if (!ret)//vector已经不存在
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())//传入的索引值无效
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];//*p为vector，curr为索引值
}

StrBlobPtr& StrBlobPtr::incr()//前缀递增：返回递增后的对象的引用
{
	check(curr, "increment past end of StrBlobPtr");//如果curr已经指向容器的尾后位置，就不能递增它
	++curr;//推进当前的位置
	return *this;
}

//对比两个StrBlobPtr是否相等
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	std::shared_ptr<std::vector<std::string> >
		l = lhs.wptr.lock(), r = rhs.wptr.lock();

	if (l == r)
		return (!r || lhs.curr == rhs.curr);//如果两个StrBlobPtr相等，要么都为空，要么指向相同的内存地址
	else
		return false; //如果他们指向不同的vector容器，返回false
}

//对比两个StrBlobPtr是否不等
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}

StrBlobPtr StrBlob::begin()//StrBlob的对象的第一个元素
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()//StrBlob的对象的最后一个元素
{
	StrBlobPtr ret = StrBlobPtr(*this, data->size());
	return ret;
}