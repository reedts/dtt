#pragma once

#include <string>
#include "../role.hpp"

namespace dtt {

	class Role_manager;

	namespace impl {

		class Role : public virtual ::dtt::Role {
		public:
			friend class ::dtt::Role_manager;
			virtual ~Role() = default;

			virtual const std::string& name() const override;
			virtual std::uint32_t gid() const override;

			//TODO permission management

		protected:
			Role(const std::string& name, std::uint32_t gid);

		private:
			std::string _name;
			std::uint32_t _gid;

			//TODO permission management
		};


		class Admin_role : public virtual ::dtt::Role, public Role {
		public:
			Admin_role();
			virtual ~Admin_role() = default;
		};

		class Officer_role : public virtual ::dtt::Role, public Role {
		public:
			Officer_role();
			virtual ~Officer_role() = default;
		};

		class Default_role : public virtual ::dtt::Role, public Role {
		public:
			Default_role();
			virtual ~Default_role() = default;
		};


	}
}