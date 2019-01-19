#pragma once

#include <map>
#include <memory>
#include "role.hpp"

namespace dtt {

	class Role_manager {
	public:
		using role_ptr          = std::unique_ptr<Role>;
		using container_type    = std::map<std::uint32_t, role_ptr>;
		using const_iterator    = typename container_type::const_iterator;

		Role_manager();

		void add_role(const std::string& name);

		const_iterator begin() const;
		const_iterator end() const;
		const_iterator cbegin() const;
		const_iterator cend() const;

	private:
		std::uint32_t _ngid {0};
		container_type _roles;
	};
}