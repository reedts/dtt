#pragma once

#include <memory>
#include <string>
#include <vector>

#include "list_view.hpp"
#include "impl/list_view.hpp"

namespace dtt {
	class Member;
	class Member_manager;
}

namespace ndtt {

	class Memberlist_view : public virtual List_view, public impl::List_view {
	public:
		explicit Memberlist_view(dtt::Member_manager& manager, int width = 0, int height = 0, int x = 0, int y = 0);

		void input(int c) override;
		void input(const std::string& in) override;

		void refresh() override;

	private:
		void draw_line(const dtt::Member& m, int pos);

		void open_add_dialog();

		std::unique_ptr<Window> _adialog {nullptr};
		dtt::Member_manager& _manager;
	};
}

