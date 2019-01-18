#include <impl/role.hpp>

namespace dtt {
	namespace impl {

		Role::Role(const std::string& name)
			: _name {name}
		{

		}

		const std::string& Role::name() const
		{
			return _name;
		}
	}
}