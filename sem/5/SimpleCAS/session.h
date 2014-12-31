/*
 * session.h
 *
 *  Created on: Nov 4, 2014
 *      Author: radoslav
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <queue>

class Session
{
	queue<ComplexExpression>
	char vars[26];

public:
	Session();

	void appendExpression(const Expression&);


};



#endif /* SESSION_H_ */
