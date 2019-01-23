#pragma once

#include <map>
#include "member.hpp"

namespace dtt {

	class Member_manager {
	public:
		using container_type = std::map<std::uint32_t, Member>;

		using const_iterator = typename container_type::const_iterator;

		Member_manager() = default;
		~Member_manager() = default;

		Member_manager(const Member_manager&) = delete;
		Member_manager& operator=(const Member_manager&) = delete;

		void add_member(const std::string& name, const std::string& mail_address, std::uint32_t matnr);

		const Member& get_member(std::uint32_t uid) const;
		const Member& get_member(const std::string& name) const;
		const Member& get_member_by_matnr(std::uint32_t matnr) const;

		std::size_t size() const;

		const_iterator begin() const;
		const_iterator end() const;
		const_iterator cbegin() const;
		const_iterator cend() const;

	private:
		std::uint32_t _nid {0};
		container_type _members;
	};
}