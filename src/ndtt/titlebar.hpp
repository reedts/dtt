#pragma once

#include <string>

#include "window.hpp"
#include "impl/window.hpp"

namespace ndtt {

	class Titlebar : public virtual Window, public impl::Window {
	public:
		Titlebar(const std::string& title, int width, int height);

	private:
		std::string _title;
	};
}