#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed(const int i);
	Fixed(const float f);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(Fixed const &other);
	friend std::ostream &operator<<(std::ostream &os, Fixed const &fix);
	bool operator>(Fixed const &other);
	bool operator<(Fixed const &other);
	bool operator>=(Fixed const &other);
	bool operator<=(Fixed const &other);
	bool operator==(Fixed const &other);
	bool operator!=(Fixed const &other);
	Fixed operator+(Fixed const &other);
	Fixed operator-(Fixed const &other);
	Fixed operator*(Fixed const &other);
	Fixed operator/(Fixed const &other);
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed& operator++();
	Fixed& operator--();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed&min(Fixed const &a, Fixed const &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(Fixed const &a, Fixed const &b);
  private:
	int _num;
	static const int _bits = 8;
};

#endif