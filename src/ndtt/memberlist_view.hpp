#pragma once

#include <string>
#include <vector>

#include "window.hpp"
#include "impl/window.hpp"

namespace dtt {
	class Member;
	class Member_manager;
}

namespace ndtt {

	class Memberlist_view : public virtual Window, public impl::Window {
	public:
		explicit Memberlist_view(dtt::Member_manager& manager);

		void input(int c) override;
		void input(const std::string& in) override;

		void refresh() override;

	private:
		void draw_labels();
		void draw_line(const dtt::Member& m, int pos);
		void highlight_line(int pos);
		void dehighlight_line(int pos);

		std::vector<std::string> _cols;
		int _sel_idx {0};
		dtt::Member_manager& _manager;
	};
}

