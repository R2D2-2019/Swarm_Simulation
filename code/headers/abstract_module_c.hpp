//
// Created by rick on 22-5-19.
//

#pramga once

#include <base_module.hpp>
#include <hwlib.hpp>

namespace r2d2::robo_cop {
	template <r2d2::frame_type frame_type>
	class abstract_module_c : public base_module_c {
	private:
		uint8_t id;

	public:
		abstract_module_c(base_comm_c &comm uint8_t id);

		uint8_t get_id();

		virtual bool process(frame_type frame_to_process) = 0;
	};
}