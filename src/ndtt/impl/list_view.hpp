#pragma once

#include <string>
#include <vector>

#include "../list_view.hpp"
#include "window.hpp"

namespace ndtt {
	namespace impl {

		class List_view : public virtual ::ndtt::List_view, public Window {
		public:
			static constexpr int padding_top = 1;
			static constexpr int padding_bottom = 1;
			static constexpr int padding_left = 1;
			static constexpr int padding_right = 1;

			explicit List_view(const std::vector<std::string>& cols, std::size_t size,
							   int width = 0, int height = 0, int x = 0, int y = 0);
			explicit List_view(std::vector<std::string>&& cols, std::size_t size,
							   int width = 0, int height = 0, int x = 0, int y = 0);
			~List_view() override = default;

			void input(int c) override;
			void refresh() override;

			void select(int pos) override;
			int get_selection() const override;

		protected:
			void set_size(std::size_t size);

			void highlight_line(int pos);
			void dehighlight_line(int pos);

			void draw_labels();
			/* Drawing the lines is content dependent */

			const int _y_start {1};
			int _sel_idx {0};
			int _num_cols;
			std::size_t _size {0};
			std::vector<std::string> _cols;
		};
	}
}