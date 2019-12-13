#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

//����StrBlob�е���Ԫ������˵����ǰ�������Ǳ�Ҫ��
class StrBlobStr;
//-----------------------------StrBlob��---------------------------------------------------------------------------------------------------
class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;//Ϊvector<string>::size_type�������size_type
	StrBlob();//Ĭ�Ϲ��캯��
	StrBlob(initializer_list<string> i1);//�������Ĺ��캯��
	size_type size() const { return data->size(); }//��������ָ��ָ���vector�Ĵ�С������vector�к��ж��ٸ�string��
	bool empty() const { return data->empty(); }//�жϸ�����ָ��ָ���vector�Ƿ�Ϊ��
	void push_back(const string &t) { data->push_back(t); }//����Ԫ��
	void pop_back();//ɾ��Ԫ��

	//Ԫ�ط��ʣ�Ŀǰδ�㶮�⼸������������
	string& front();
	const string& front() const;//�����������ݳ�Ա������ǳ������ԣ������س�string
	string& back();
	const string& back() const;//�����������ݳ�Ա������ǳ������ԣ������س�string

	//����ָ����Ԫ�غ�β��Ԫ�ص�StrBlobPtr
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;//����ָ��data������Ϊ��������Ϊstring��vector����
	void check(size_type i, const string &msg) const;//���data[i]���Ϸ����ܳ��쳣��Ϣmsg
};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}//ʹ��make_shared��ʼ������ָ��
StrBlob::StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)) {}//make_shared<��������>(��ʼ������)

void StrBlob::check(size_type i, const string &msg) const//����Ա������ֻ�����ó����ݳ�Ա�ͷǳ����ݳ�Ա�������ܸı�����
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()//��������ָ����ָ��vector<string>��ǰ��ǰһ��string����
{
	check(0, "front on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	return data->front();
}

const string& StrBlob::front() const//��������ָ����ָ��vector<string>��ǰ��ǰһ��string����
{
	check(0, "front on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	return data->front();
}

string& StrBlob::back()//��������ָ����ָ��vector<string>��ǰ�ĺ�һ��string����
{
	check(0, "back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	return data->back();
}

const string& StrBlob::back() const//��������ָ����ָ��vector<string>��ǰ�ĺ�һ��string����
{
	check(0, "back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	return data->back();
}


void StrBlob::pop_back()//ɾ��vector������������
{
	check(0, "pop_back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	data->pop_back();
}
//---------------------------------------------------------------------------------------------------------------------

//----------------------------------StrBlobPtr��----------- -----------------------------------------------------------
class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//������Ԫ����
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {  }
	string& deref() const;//������
	StrBlobPtr& incr();//ǰ׺����
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;//�����ɹ���check����һ��ָ��vector��shared_ptr
	weak_ptr<vector<string>> wptr;//����һ��weak_ptr����ζ�ŵײ�vector���ܱ�����
	size_t curr;//���������еĵ�ǰλ��
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();//���vector������
	if (!ret)//vector�Ѿ�������
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())//���������ֵ��Ч
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];//*pΪvector��currΪ����ֵ
}

StrBlobPtr& StrBlobPtr::incr()//ǰ׺���������ص�����Ķ��������
{
	check(curr, "increment past end of StrBlobPtr");//���curr�Ѿ�ָ��������β��λ�ã��Ͳ��ܵ�����
	++curr;//�ƽ���ǰ��λ��
	return *this;
}

//�Ա�����StrBlobPtr�Ƿ����
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	std::shared_ptr<std::vector<std::string> >
		l = lhs.wptr.lock(), r = rhs.wptr.lock();

	if (l == r)
		return (!r || lhs.curr == rhs.curr);//�������StrBlobPtr��ȣ�Ҫô��Ϊ�գ�Ҫôָ����ͬ���ڴ��ַ
	else
		return false; //�������ָ��ͬ��vector����������false
}

//�Ա�����StrBlobPtr�Ƿ񲻵�
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}

StrBlobPtr StrBlob::begin()//StrBlob�Ķ���ĵ�һ��Ԫ��
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()//StrBlob�Ķ�������һ��Ԫ��
{
	StrBlobPtr ret = StrBlobPtr(*this, data->size());
	return ret;
}