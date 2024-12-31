#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed &other);
			Fixed& operator=(Fixed const &other);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
	private:
			int _num;
			static const int _bits = 8;
};

#endif