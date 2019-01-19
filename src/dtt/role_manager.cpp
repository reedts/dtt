#include <algorithm>
#include <impl/role.hpp>
#include <role_manager.hpp>
#include <stdexcept>

namespace dtt {

	Role_manager::Role_manager()
	{
		_roles.insert({_ngid, role_ptr {new impl::Admin_role {}}});
		++_ngid;
		_roles.insert({_ngid, role_ptr {new impl::Officer_role {}}});
		++_ngid;
		_roles.insert({_ngid, role_ptr {new impl::Default_role {}}});
		++_ngid;
	}

	void Role_manager::add_role(const std::string& name)
	{
		auto it = std::find_if(_roles.begin(), _roles.end(), [&](const auto& r) { return r.second->name() == name; });

		if (it != _roles.end()) {
			throw std::invalid_argument {"a role with that name exists already"};
		}

		_roles.insert({_ngid, role_ptr {new impl::Role {name, _ngid}}});
		++_ngid;
	}

	Role_manager::const_iterator Role_manager::begin() const
	{
		return _roles.begin();
	}

	Role_manager::const_iterator Role_manager::end() const
	{
		return _roles.end();
	}

	Role_manager::const_iterator Role_manager::cbegin() const
	{
		return _roles.cbegin();
	}

	Role_manager::const_iterator Role_manager::cend() const
	{
		return _roles.cend();
	}
}