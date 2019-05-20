#include <iostream>
#include <state_storage_c.hpp>
#include <robo_cop_c.hpp>


int main( void ){
	using namespace r2d2;
	r2d2::robo_cop::robo_cop_c roboCop(4);
	roboCop.move(5);
}

