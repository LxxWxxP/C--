#include "volume.h"
#include <iostream>
using namespace std;

void Volume::input_data()
{
	cout << "Please input the value of height, width, height in order:" << endl;
	cin >> length >> width >> height;
}

void Volume::output_volume()
{
	cout << "The volume of the rectangular column is: " << height * width * height << endl;
}