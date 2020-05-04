
#ifndef __INVALIDEXCEPTION_H__
#define __INVALIDEXCEPTION_H__
#include <string>
#include <stdexcept>
class InvalideException : public std::exception
{
private:
	std::string message;
public:
	InvalideException(std::string valeur) {
		this->message = valeur;
	}
	const char* what() const noexcept {
		return this->message.c_str();
	}
};
#endif