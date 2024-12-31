#include "Fixed.hpp"


Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_num = 0;
};

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed&	Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		_num = other.getRawBits();
	return(*this);
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_num);
};

void	Fixed::setRawBits(int const raw)
{
	this->_num = raw;
};
