#ifndef __TIMEBOXED_CUSTOMTEXT_
#define __TIMEBOXED_CUSTOMTEXT_

#if !defined PBL_PLATFORM_APLITE
#include <pebble.h>

bool is_customtext_enabled();
void update_customtext_a_text(char*);
void update_customtext_b_text(char*);
void toggle_customtext(uint8_t);
void store_customtext_a_text(char*);
void store_customtext_b_text(char*);
#endif
#endif
