#pragma once

#include <ncurses.h>
#include <memory>
#include <string>

#include "window.hpp"
#include "impl/window.hpp"
#include "titlebar.hpp"

namespace dtt {
	class Member_manager;
}

namespace ndtt {

	class Main_window : public virtual Window, public impl::Window {
	public:
		explicit Main_window(const std::string& title, dtt::Member_manager& manager);

		void input(int c) override;
		void input(const std::string& in) override;

		void refresh() override;

		bool is_exiting() const;

	private:
		std::unique_ptr<Titlebar> _titlebar;
		std::unique_ptr<Window> _awin;
		bool _is_exiting {false};
	};
}