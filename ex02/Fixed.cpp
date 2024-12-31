#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_num = 0;
};

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	_num = i << _bits;
};

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	_num = (int)roundf(f * (1 << _bits));
};

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed &Fixed::operator=(Fixed const &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_num = other.getRawBits();
	return (*this);
};

float Fixed::toFloat(void) const
{
	return ((float)_num / (float)(1 << _bits));
};

int Fixed::toInt(void) const
{
	return ((int)(_num >> _bits));
};

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_num);
};

void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fix)
{
	os << fix.toFloat();
	return (os);
};

bool Fixed::operator>(Fixed const &other)
{
	return (getRawBits() > other.getRawBits());
};

bool Fixed::operator<(Fixed const &other)
{
	return (getRawBits() < other.getRawBits());
};

bool Fixed::operator>=(Fixed const &other)
{
	return (getRawBits() >= other.getRawBits());
};

bool Fixed::operator<=(Fixed const &other)
{
	return (getRawBits() <= other.getRawBits());
};

bool Fixed::operator==(Fixed const &other)
{
	return (getRawBits() == other.getRawBits());
};

bool Fixed::operator!=(Fixed const &other)
{
	return (getRawBits() != other.getRawBits());
};

Fixed	Fixed::operator+(Fixed const &other)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + other.getRawBits());
	return(res);
};

Fixed	Fixed::operator-(Fixed const &other)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - other.getRawBits());
	return(res);
};

Fixed	Fixed::operator*(Fixed const &other)
{
	Fixed	res;

	res.setRawBits((this->getRawBits() * other.getRawBits()) >> _bits);
	return(res);
};

Fixed	Fixed::operator/(Fixed const &other)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() << _bits / other.getRawBits());
	return(res);
};

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	_num++;
	return(tmp);
};

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	_num--;
	return(tmp);
};

Fixed &Fixed::operator++()
{
	_num++;
	return(*this);
};

Fixed &Fixed::operator--()
{
	_num--;
	return(*this);
};

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return(a.getRawBits() < b.getRawBits()) ? a : b;
};
const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	return(a.getRawBits() < b.getRawBits()) ? a : b;
};

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return(a.getRawBits() > b.getRawBits()) ? a : b;
};
const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	return(a.getRawBits() > b.getRawBits()) ? a : b;
};
