//=================================================
// K M Asif
// Complex.cpp
// This file contains the class implementation for the 
// Complex number class.
//=================================================

#include "Complex.h"
#include <iomanip>
#include <math.h>

//=================================================
// default constructor
// PARAMETERS
// Creates a complex variable with value 0+0i
//=================================================
		Complex::Complex ( void )
{
	real = 0;
	imag = 0;
}


//=================================================
// to_string
// PARAMETERS:
// none
// RETURN VALUE:
// a string containing "a+bi" where a and b are 
// the real and complex parts of the number.  Both
// a and b will be with fixed decimal length up to 
// two places.  
//=================================================

string 	Complex::to_string ( void ) const
{
	stringstream stream;
	stream << fixed << setprecision(3) << real;
	if ( imag >= 0 )
		stream << "+" << fixed << setprecision(3) << imag << "i";
	else
		stream << "-" << fixed << setprecision(3) << fabs(imag) << "i";
	
	return stream.str();
}

//=================================================
//overloaded constructor
//PARAMETERS: float a and float b
//create a complex variable with value a+bi
//=================================================
Complex::Complex(float a, float b){
	real = a;
	imag = b;
}

//=================================================
//overloaded constructor
//PARAMETERS: reference of a Complex object c
//create a complex variable with value identical to
//object in parameter
//=================================================
Complex::Complex( const Complex &c ){
	real = c.real;
	imag = c.imag;
}

//=================================================
//add
//PARAMETERS: a Complex object c
//RETURN VALUE: a Complex object that is sum of 
//caller object and parameter object
//=================================================
Complex Complex::add( const Complex c ) const{
	return Complex(real + c.real, imag + c.imag);
}

//=================================================
//add
//PARAMETERS: float a
//RETURN VALUE: a Complex object whose real part is
//sum of real part of caller object and float a
//=================================================
Complex Complex::add(float a) const{
	return Complex(real + a, imag);
}

//=================================================
//abs
//PARAMETERS: none
//RETURN VALUE: square root of (real part
//squared + imaginary part squared)
//=================================================
float Complex::abs( void ) const{
	return sqrt(real*real + imag*imag);
}

//=================================================
//setReal: set object's real part to float a
//PARAMETERS: float a
//RETURN VALUE: none
//=================================================
void Complex::setReal( float a ){
	real = a;
}

//=================================================
//getReal
//PARAMETERS: none
//RETURN VALUE: Complex object's real part
//=================================================
float Complex::getReal( void ) const{
	return real;
}

//=================================================
//setImag: set object's imaginary part to float b
//PARAMETERS: float b
//RETURN VALUE: none
//=================================================
void Complex::setImag( float b ){
	imag = b;
}

//=================================================
//getImag
//PARAMETERS: none
//RETURN VALUE: Complex object's imaginary part
//=================================================
float Complex::getImag ( void ) const{
	return imag;
}

//=================================================
//makeCopy: set caller object to parameter object
//PARAMETER: Complex object c
//RETURN VALUE: none
//=================================================
void Complex::makeCopy( const Complex c ){
	real = c.real;
	imag = c.imag;
}