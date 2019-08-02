#ifndef 数据库_h_guard
#define 数据库_h_guard
#include<map>
#include<string>
#include<fstream>
#include<vector>

typedef struct {
	double min;
	double max;
}scale;
void reveal(const std::map< int, std::string >&, int pre, int curr);
void readdatabase(std::ifstream&, std::map<int , std::vector<std::string> >& ,std::map<int , scale>&);
#endif