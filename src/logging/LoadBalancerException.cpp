#include "LoadBalancerException.h"

const char* LoadBalancerException::what() const throw () {
	return error;
}

LoadBalancerException::LoadBalancerException(const char *error) {
	this->error = error;
}

LoadBalancerException::~LoadBalancerException() {

}
