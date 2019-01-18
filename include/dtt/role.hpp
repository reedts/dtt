#pragma once

#include <string>

namespace dtt {

	class Role {
	public:
		virtual const std::string& name() const = 0;

		//TODO: Figure out how to handle permissions (if at all)
	};
}