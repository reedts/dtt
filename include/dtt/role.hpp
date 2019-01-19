#pragma once

#include <string>

namespace dtt {

	class Role {
	public:
		virtual ~Role() = default;

		virtual const std::string& name() const = 0;
		virtual std::uint32_t gid() const = 0;

		//TODO: Figure out how to handle permissions (if at all)
	};
}