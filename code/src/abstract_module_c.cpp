//
// Created by rick on 22-5-19.
//

#include "abstract_module_c.hpp"

namespace r2d2::robo_cop {
	abstract_module_c::abstract_module_c(base_comm_c &comm):
		base_module_c(comm),
		id(id)
	{}

	uint8_t abstract_module_c::get_id() {
		return id;
	}
}