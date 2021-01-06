#include <pebble.h>
#include "configs.h"
#include "customtext.h"
#include "keys.h"
#include "text.h"

#if !defined PBL_PLATFORM_APLITE

static bool customtext_enabled;
static char custxt[22];
static char custxt_b[22];

static bool get_customtext_enabled() {
  return is_module_enabled(MODULE_CUSTOMTEXTA) ||
    is_module_enabled(MODULE_CUSTOMTEXTB);
}

void update_customtext_a_text(char* custxt) {
    if (is_module_enabled(MODULE_CUSTOMTEXTA)) {
        set_customtext_a_layer_text(custxt);
    } else {
        set_customtext_a_layer_text("");
    }
}

void update_customtext_b_text(char* custxt) {
    if (is_module_enabled(MODULE_CUSTOMTEXTB)) {
        set_customtext_b_layer_text(custxt);
    } else {
        set_customtext_b_layer_text("");
    }
}

static void update_customtext_from_storage() {
    if (persist_exists(KEY_CUSTOMTEXTATEXT)) {
        persist_read_string(KEY_CUSTOMTEXTATEXT, custxt, sizeof(custxt));
        update_customtext_a_text(custxt);
    }

    if (persist_exists(KEY_CUSTOMTEXTBTEXT)) {
        persist_read_string(KEY_CUSTOMTEXTBTEXT, custxt_b, sizeof(custxt_b));
        update_customtext_b_text(custxt_b);
    }    
}

void store_customtext_a_text(char* custxt) {
    persist_write_string(KEY_CUSTOMTEXTATEXT, custxt);
}

void store_customtext_b_text(char* custxt) {
    persist_write_string(KEY_CUSTOMTEXTBTEXT, custxt);
}

void toggle_customtext(uint8_t reload_origin) {
    customtext_enabled = get_customtext_enabled();
    if (customtext_enabled) {
        update_customtext_from_storage();
    } else {
        set_customtext_a_layer_text("");
        set_customtext_b_layer_text("");	
    }
}

bool is_customtext_enabled() {
    return customtext_enabled;
}
#endif
