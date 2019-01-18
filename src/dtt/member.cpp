#include <member.hpp>

namespace dtt {

	Member::Member(const std::string& name, const std::string& mail_address, std::uint32_t matnr)
		: _name {name}, _mail_address {mail_address}, _matnr {matnr}
	{

	}

	const std::string& Member::name() const
	{
		return _name;
	}

	const std::string& Member::mail_address() const
	{
		return _mail_address;
	}

	std::uint32_t Member::matnr() const
	{
		return _matnr;
	}
}