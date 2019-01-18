#pragma once

#include <string>
#include "../role.hpp"

namespace dtt {
	namespace impl {

		class Role : virtual ::dtt::Role {
		public:
			explicit Role(const std::string& name);
			virtual ~Role() = default;

			virtual const std::string& name() const override;

			//TODO permission management

		private:
			std::string _name;

			//TODO permission management
		};
	}
}