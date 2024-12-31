#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed &other);
			Fixed(const int i);
			Fixed(const float f);
			float toFloat( void ) const;
			int toInt( void ) const;
			Fixed& operator=(Fixed const &other);
			friend std::ostream& operator<<(std::ostream& os, Fixed const &fix);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
	private:
			int _num;
			static const int _bits = 8;
};

#endif