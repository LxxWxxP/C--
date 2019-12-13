#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
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
private:
	shared_ptr<vector<string>> data;//����ָ��data������Ϊ��������Ϊstring��vector����
	void check(size_type i, const string &msg) const;//���data[i]���Ϸ����ܳ��쳣��Ϣmsg
};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}//ʹ��make_shared��ʼ������ָ��
StrBlob::StrBlob(initializer_list<string> i1):data(make_shared<vector<string>>(i1)){}//make_shared<��������>(��ʼ������)

void StrBlob::check(size_type i, const string &msg) const//����Ա������ֻ�����ó����ݳ�Ա�ͷǳ����ݳ�Ա�������ܸı�����
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()//��������ָ����ָ��vector<string>��ǰ��ǰһ��string����
{
	check(0, "front on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	cout << this << endl;
	return data->front();
}

const string& StrBlob::front() const//��������ָ����ָ��vector<string>��ǰ��ǰһ��string����
{
	check(0, "front on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	cout << this << endl;
	return data->front();
}

string& StrBlob::back()//��������ָ����ָ��vector<string>��ǰ�ĺ�һ��string����
{
	check(0, "back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	cout << this << endl;
	return data->back();
}

const string& StrBlob::back() const//��������ָ����ָ��vector<string>��ǰ�ĺ�һ��string����
{
	check(0, "back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	cout << this << endl;
	return data->back();
}


void StrBlob::pop_back()//ɾ��vector������������
{
	check(0, "pop_back on empty StrBlob");//���vectorΪ�գ�check���׳�һ���쳣 
	data->pop_back();
}