//
// Created by rick on 13-5-19.
//
#pragma once

#include "robo_cop_c.hpp"

namespace r2d2::robo_cop {

	robo_cop_c::robo_cop_c(int x) {
		std::cout << x << std::endl;
	}

	void robo_cop_c::move(int x) {
		std::cout << "I moved to " << x << std::endl;
	}
}