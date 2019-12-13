#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template<typename I, typename T>
I myFind(I begin, I end, const T &word)
{
	while (begin != end && *begin != word)//没到容器末尾，也没有匹配到相应的word
		begin++;//迭代器++
	return begin;
}

int main()
{
	vector<int> vi = { 0,2,4,6,8,10 };
	list<string> ls = { "a","ab","abc","abcd","abcde" };
	auto iter = myFind(vi.begin(), vi.end(), 6);
	if (iter == vi.end())
		cout << "can not find 6" << endl;
	else
		cout << "find 6 at position " << iter - vi.begin() << endl;
	
	auto iter1 = myFind(ls.begin(), ls.end(), "abcdefg");
	if (iter1 == ls.end())
		cout << "can not find abcdefg" << endl;
	else
		//	cout << "find abcdefg at position " << iter1 - ls.begin() << endl;这行代码会报错，因为list不支持减号运算符
		cout << "found abcdef" << endl;
	system("pause");
	return 0;
}