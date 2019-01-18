#pragma once

#include <string>

namespace dtt {

	class Member {
	public:
		Member(const std::string& name, const std::string& mail_address, std::uint32_t matnr);

		const std::string& name() const;
		const std::string& mail_address() const;
		std::uint32_t matnr() const;

	private:
		std::string _name;
		std::string _mail_address;
		std::uint32_t _matnr;
		// TODO: Roles
	};
}