#ifndef LOGGING_LOADBALANCEREXCEPTION_H_
#define LOGGING_LOADBALANCEREXCEPTION_H_

#include <exception>

using namespace std;

class LoadBalancerException: public exception {

	const char *error;

public:

	const char* what() const throw ();
	LoadBalancerException(const char *error);
	virtual ~LoadBalancerException();
};

#endif
