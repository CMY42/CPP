#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	/*std::cout << "Copy constructor called" << std::endl;
	*this = copy;*/
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_value = copy._value; // permet d'eviter la copie de l'objet sur lui-meme
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &copy) const
{
	return this->_value > copy._value;
}

bool Fixed::operator<(const Fixed &copy) const
{
	return this->_value < copy._value;
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return this->_value >= copy._value;
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return this->_value <= copy._value;
}

bool Fixed::operator==(const Fixed &copy) const
{
	return this->_value == copy._value;
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return this->_value != copy._value;
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	return Fixed(this->toFloat() / copy.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _bits); //static cast offre une meilleure  verification des types en C++
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
