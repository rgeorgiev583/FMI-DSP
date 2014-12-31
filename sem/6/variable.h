/*
 * variable.h
 *
 *  Created on: Nov 11, 2014
 *      Author: radoslav
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>

class Variable
{
public:
	virtual ~Variable();

	virtual std::string toString() const = 0;
	virtual void fromString(std::string) = 0;
};



#endif /* VARIABLE_H_ */
