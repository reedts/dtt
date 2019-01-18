#pragma once

#include <string>
#include "../role.hpp"

namespace dtt {
	namespace impl {

		class Role : virtual ::dtt::Role {
		public:
			explicit Role(const std::string& name, std::uint32_t gid);
			virtual ~Role() = default;

			virtual const std::string& name() const override;
			virtual std::uint32_t gid() const override;

			//TODO permission management

		private:
			std::string _name;
			std::uint32_t _gid;

			//TODO permission management
		};


		class Admin_role : virtual ::dtt::Role, public Role {
		public:
			Admin_role();
			virtual ~Admin_role() = default;
		};

		class Officer_role : virtual ::dtt::Role, public Role {
			Officer_role();
			virtual ~Officer_role() = default;
		};

		class Default_role : virtual ::dtt::Role, public Role {
			Default_role();
			virtual ~Default_role() = default;
		};


	}
}