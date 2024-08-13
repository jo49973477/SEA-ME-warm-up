#pragma once
#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include "Part.h"
#include <iostream>
using namespace std;

class Package : public Part
{
	int all_len;
	int all_width;
	int all_height;
	int wheel_base;
	int tread;

public:
	Package();
	~Package();
	Package(int, int, int, int, int);
	Package(const Package& p);
	Package& operator= (const Package& other);
	void spec();
};

#endif 
