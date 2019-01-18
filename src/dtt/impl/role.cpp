#include <impl/role.hpp>

namespace dtt {
	namespace impl {

		Role::Role(const std::string& name, std::uint32_t gid)
			: _name {name}, _gid {gid}
		{

		}

		const std::string& Role::name() const
		{
			return _name;
		}

		std::uint32_t Role::gid() const
		{
			return _gid;
		}


		Admin_role::Admin_role()
			: Role { "Admin", 0 }
		{
		}

		Officer_role::Officer_role()
			: Role { "Officer", 1 }
		{
		}

		Default_role::Default_role()
			: Role { "Default", 2 }
		{
		}
	}
}