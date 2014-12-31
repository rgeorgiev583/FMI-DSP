/*
 * constant.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: radoslav
 */

#include <sstream>

Constant::Constant(const std::string& rpn)
{
	std::istringstream sin(rpn);
	sin >> value;
}


