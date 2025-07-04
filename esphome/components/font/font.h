#pragma once

#include "esphome/core/color.h"
#include "esphome/core/datatypes.h"
#include "esphome/core/defines.h"
#ifdef USE_DISPLAY
#include "esphome/components/display/display.h"
#endif

namespace esphome {
namespace font {

class Font;

struct GlyphData {
  const uint8_t *a_char;
  const uint8_t *data;
  int advance;
  int offset_x;
  int offset_y;
  int width;
  int height;
};

class Glyph {
 public:
  Glyph(const GlyphData *data) : glyph_data_(data) {}

  const uint8_t *get_char() const;

  bool compare_to(const uint8_t *str) const;

  int match_length(const uint8_t *str) const;

  void scan_area(int *x1, int *y1, int *width, int *height) const;

  const GlyphData *get_glyph_data() const { return this->glyph_data_; }

 protected:
  friend Font;

  const GlyphData *glyph_data_;
};

class Font
#ifdef USE_DISPLAY
    : public display::BaseFont
#endif
{
 public:
  /** Construct the font with the given glyphs.
   *
   * @param data A vector of glyphs, must be sorted lexicographically.
   * @param data_nr The number of glyphs in data.
   * @param baseline The y-offset from the top of the text to the baseline.
   * @param height The y-offset from the top of the text to the bottom.
   * @param descender The y-offset from the baseline to the lowest stroke in the font (e.g. from letters like g or p).
   * @param xheight The height of lowercase letters, usually measured at the "x" glyph.
   * @param capheight The height of capital letters, usually measured at the "X" glyph.
   * @param bpp The bits per pixel used for this font. Used to read data out of the glyph bitmaps.
   */
  Font(const GlyphData *data, int data_nr, int baseline, int height, int descender, int xheight, int capheight,
       uint8_t bpp = 1);

  int match_next_glyph(const uint8_t *str, int *match_length);

#ifdef USE_DISPLAY
  void print(int x_start, int y_start, display::Display *display, Color color, const char *text,
             Color background) override;
  void measure(const char *str, int *width, int *x_offset, int *baseline, int *height) override;
#endif
  inline int get_baseline() { return this->baseline_; }
  inline int get_height() { return this->height_; }
  inline int get_ascender() { return this->baseline_; }
  inline int get_descender() { return this->descender_; }
  inline int get_linegap() { return this->linegap_; }
  inline int get_xheight() { return this->xheight_; }
  inline int get_capheight() { return this->capheight_; }
  inline int get_bpp() { return this->bpp_; }

  const std::vector<Glyph, RAMAllocator<Glyph>> &get_glyphs() const { return glyphs_; }

 protected:
  std::vector<Glyph, RAMAllocator<Glyph>> glyphs_;
  int baseline_;
  int height_;
  int descender_;
  int linegap_;
  int xheight_;
  int capheight_;
  uint8_t bpp_;  // bits per pixel
};

}  // namespace font
}  // namespace esphome
