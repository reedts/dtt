#pragma once

#include <ncurses.h>

#include "../window.hpp"

namespace ndtt {
	namespace impl {

		class Window : public virtual ::ndtt::Window {
		public:
			Window() = default;
			Window(int width, int height, int x, int y);
			virtual ~Window();

			void input(const std::string& in) override;
			void refresh() override;

			int width() const override;
			int height() const override;
			int x() const override;
			int y() const override;

		protected:
			void set_width(int width);
			void set_height(int height);
			void set_x(int x);
			void set_y(int y);

			WINDOW* _win {nullptr};

		private:
			void update_window();

			int _width {0};
			int _height {0};
			int _x {0};
			int _y {0};
		};


	}
}