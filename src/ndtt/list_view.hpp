#pragma once

#include "window.hpp"

namespace ndtt {

	class List_view : public virtual Window {
		virtual void select(int pos) = 0;
		virtual int get_selection() const = 0;
	};
}