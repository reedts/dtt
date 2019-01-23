#pragma once

namespace ndtt {

	/**
	 * Abstraction class for ncurses WINDOW*.
	 */
	class Window {
	public:
		virtual void input(int c) = 0;
		virtual void input(const std::string& in) = 0;
		virtual void refresh() = 0;

		virtual int width() const = 0;
		virtual int height() const = 0;
		virtual int x() const = 0;
		virtual int y() const = 0;
	};
}