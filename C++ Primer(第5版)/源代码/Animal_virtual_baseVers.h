/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#include <string>
#include <iostream>

class Endangered {
public:
	enum Status { critical, environment, improving };
	Endangered(Status stat = improving) : animal_status(stat) { }
	virtual ~Endangered()//虚析构函数(作为基类一般都需要定义虚析构函数)
	{
		std::cout << "Endangered::~Endangered" << std::endl;
	}
	virtual std::ostream& print(std::ostream&) const//虚常成员函数print
	{
		return std::cout << "Endangered::print" << std::endl;
	}
	virtual void highlight() const//虚常成员函数highlight
	{
		std::cout << "Endangered::highlighted" << std::endl;
	}
	// . . .
private:
	Status animal_status;
};

class ZooAnimal;
extern std::ostream& operator<<(std::ostream&, const ZooAnimal&);//声明函数或全局变量的作用范围(外部的：外部可以引用)

class ZooAnimal {
public:
	ZooAnimal() : exhibit_stat(false) { }
	ZooAnimal(std::string animal, bool exhibit, std::string family) : nm(animal), exhibit_stat(exhibit), fam_name(family) { }
	virtual ~ZooAnimal()//虚析构函数(作为基类一般都需要定义虚析构函数)
	{
		std::cout << "ZooAnimal::~ZooAnimal" << std::endl;
	}

	virtual std::ostream& print(std::ostream&) const//虚常成员函数print
	{
		return std::cout << "ZooAnimal::print" << std::endl;
	}
	virtual int population() const//虚常成员函数population
	{
		std::cout << "ZooAnimal::population" << std::endl;  return 0;
	}

	//常成员函数：返回数据成员
	std::string name() const { return nm; }
	std::string family_name() const { return fam_name; }
	bool onExhibit() const { return exhibit_stat; }
	// . . .
protected:
	std::string nm;
	bool exhibit_stat;
	std::string fam_name;
	// . . .
private:
};

//关键字public和virtual的顺序并不重要
class Raccoon : public virtual ZooAnimal {//虚继承ZooAnimal类
public:
	Raccoon() : pettable_flag(false) { }
	Raccoon(std::string name, bool onExhibit = true);

	virtual std::ostream& print(std::ostream&) const//虚常成员函数print
	{
		return  std::cout << "Raccoon::print" << std::endl;
	}

	bool pettable() const { return pettable_flag; }//返回受保护数据成员pettable_flag
	void pettable(bool petval) { pettable_flag = petval; }//修改受保护数据成员pettable_flag
	// . . .

protected:
	bool pettable_flag;
	// . . .
};

class Bear : virtual public ZooAnimal {//虚继承ZooAnimal类
public:
	Bear(std::string name, bool onExhibit = true);
protected:
	Bear() : dance_flag(two_left_feet) { }
public:
	enum DanceType { two_left_feet, macarena, fandango };

	virtual std::ostream &print(std::ostream&) const//虚常成员函数print
	{
		return  std::cout << "Bear::print" << std::endl;
	}
	virtual std::string isA() const//虚常成员函数isA
	{
		std::cout << "Bear::isA" << std::endl;
		return "Bear";
	}
	int mumble(int)
	{
		std::cout << "Bear::mumble" << std::endl; return 0;
	}
	void dance(DanceType) const
	{
		std::cout << "Bear::dance" << std::endl;
	}
	virtual ~Bear() { std::cout << "Bear::~Bear" << std::endl; }
private:
	std::string name;
	DanceType dance_flag;
};

class Panda : public Bear, public Raccoon, public Endangered {//直接继承于Bear类、Reccoon类、Endangered类
public:
	Panda() : sleeping_flag(false) { }
	Panda(std::string name, bool onExhibit = true);
	virtual std::ostream& print(std::ostream&) const//虚常成员函数print
	{
		return  std::cout << "Panda::print" << std::endl;
	}
	bool sleeping() const { return sleeping_flag; }
	void sleeping(bool newval) { sleeping_flag = newval; }
	// . . .
protected:
	bool sleeping_flag;
	// . . .
};
//Bear类、Reccoon类、Panda类的构造函数的定义
Bear::Bear(std::string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Bear") { }
Raccoon::Raccoon(std::string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Raccoon"), pettable_flag(false) { }
Panda::Panda(std::string name, bool onExhibit) : ZooAnimal(name, onExhibit, "Panda"), Bear(name, onExhibit), Raccoon(name, onExhibit), Endangered(Endangered::critical), sleeping_flag(false) { }//先构造虚基类ZooAnimal部分，在按照初始化列表分别构造Bear、Reccoon、Endangered部分，最后构造自身（Pander）部分
