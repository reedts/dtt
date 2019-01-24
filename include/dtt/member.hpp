#pragma once

#include <string>

namespace dtt {

	class Member_manager;

	class Member {
	public:
		friend class Member_manager;

		std::uint32_t uid() const;
		const std::string& name() const;
		const std::string& uname() const;
		const std::string& mail_address() const;
		std::uint32_t matnr() const;

	private:
		/* private ctor; should only be accessible from Member_manager */
		Member(const std::string& name, const std::string& uname, const std::string& mail_address,
			   std::uint32_t matnr, std::uint32_t uid);

		std::uint32_t _uid;
		std::string _name;
		std::string _uname;
		std::string _mail_address;
		std::uint32_t _matnr;
		// TODO: Roles
	};

	inline bool operator==(const Member& l, const Member& r);
	inline bool operator!=(const Member& l, const Member& r);
}