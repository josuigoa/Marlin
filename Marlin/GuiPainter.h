#ifndef GUI_IMPL_H
#define GUI_IMPL_H

#include <stdint.h>

// Painting library
#include "Singleton.h"
#include "ultralcd_st7920_u8glib_rrd.h"


// Specify the printer UI implementation
#include "GuiImpl_witbox_2.h"

namespace screen
{
	class GuiPainter
	{
		public:
			typedef common::Singleton<screen::GuiPainter> singleton;

		public:
			GuiPainter();
			~GuiPainter();

			void drawXBMP(uint8_t x, uint8_t y, uint8_t width, uint8_t height, const unsigned char* bitmap);

			void setColorIndex(uint8_t color);

			void setFont(const u8g_fntpgm_uint8_t* font);

			void setPrintPos(uint8_t x, uint8_t y);

			void print(const char * title);

			void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

			void drawBox(uint8_t x, uint8_t y, uint8_t width, uint8_t height);

			void firstPage();

			bool nextPage();

		private:
			U8GLIB_ST7920_128X64_RRD m_impl;
			uint8_t m_x_init;
			uint8_t m_y_init;
			uint8_t m_x_end;
			uint8_t m_y_end;


	};
}
#define painter screen::GuiPainter::singleton::getInstance()

#endif //GUI_IMPL_H