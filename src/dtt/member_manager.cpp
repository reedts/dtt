#include <regex>
#include <stdexcept>
#include <member_manager.hpp>

namespace dtt {

	void Member_manager::add_member(const std::string& name, const std::string& mail_address, std::uint32_t matnr)
	{
		const std::regex mail_validation {"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"};

		if (!std::regex_match(mail_address, mail_validation)) {
			throw std::invalid_argument {"no valid mail address"};
		}

		auto it = std::find_if(_members.begin(), _members.end(), [&](const auto& p)
							{ return (p.second.name() == name || p.second.matnr() == matnr); });

		if (it != _members.end()) {
			throw std::invalid_argument {"user already exists"};
		}

		_members.emplace(_nid, Member {name, mail_address, matnr, _nid});
		++_nid;
	}

	const Member& Member_manager::get_member(std::uint32_t uid) const
	{
		auto it = _members.find(uid);

		if (it == _members.end()) {
			throw std::invalid_argument {"no member with that uid"};
		}

		return it->second;
	}

	const Member& Member_manager::get_member(const std::string& name) const
	{
		auto it = std::find_if(_members.begin(), _members.end(), [&](const auto& p) { return p.second.name() == name; });

		if (it == _members.end()) {
			throw std::invalid_argument {"no member with that name"};
		}

		return it->second;
	}

	const Member& Member_manager::get_member_by_matnr(std::uint32_t matnr) const
	{
		auto it = std::find_if(_members.begin(), _members.end(), [&](const auto& p) { return p.second.matnr() == matnr; });

		if (it == _members.end()) {
			throw std::invalid_argument {"no member with that name"};
		}

		return it->second;
	}

	Member_manager::const_iterator Member_manager::begin() const
	{
		return _members.begin();
	}

	Member_manager::const_iterator Member_manager::end() const
	{
		return _members.end();
	}

	Member_manager::const_iterator Member_manager::cbegin() const
	{
		return _members.cbegin();
	}

	Member_manager::const_iterator Member_manager::cend() const
	{
		return _members.cend();
	}
}
