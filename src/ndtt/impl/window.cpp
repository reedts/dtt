#include <string>

#include "window.hpp"
#include <iostream>

namespace ndtt {
	namespace impl {

		Window::Window(int width, int height, int x, int y)
			: _width {width}, _height {height}, _x {x}, _y {y}
		{
			_win = newwin(_height, _width, _y, _x);
		}

		Window::~Window()
		{
			delwin(_win);
		}

		void Window::input(int c)
		{

		}

		void Window::input(const std::string& in)
		{

		}

		void Window::refresh()
		{
			wrefresh(_win);
		}

		int Window::width() const
		{
			return _width;
		}

		int Window::height() const
		{
			return _height;
		}

		int Window::x() const
		{
			return _x;
		}

		int Window::y() const
		{
			return _y;
		}

		void Window::set_width(int width)
		{
			_width = width;
			this->update_window();
		}

		void Window::set_height(int height)
		{
			_height = height;
			this->update_window();
		}

		void Window::set_x(int x)
		{
			_x = x;
			this->update_window();
		}

		void Window::set_y(int y)
		{
			_y = y;
			this->update_window();
		}

		void Window::update_window()
		{
			if (!_win && (_width != 0 && _height != 0)) {
				_win = newwin(_height, _width, _y, _x);
			} else if (_win){
				mvwin(_win, _y, _x);
				wresize(_win, _height, _width);
				wclear(_win);
			}
		}
	}
}
