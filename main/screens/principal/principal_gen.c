#include "principal_gen.h"
#include "lvgl_private.h"
#include "main/pages/charts.h"
#include "main/pages/plugin.h"
#include "main/pages/volcano.h"

static void hook_division_lines(lv_event_t * e);
static void add_faded_area(lv_event_t * e);
static void draw_event_cb(lv_event_t * e);

lv_obj_t * principal_create(void)
{
    /*Create a Tab view object*/
    lv_obj_t * tabview;
    tabview = lv_tabview_create(lv_screen_active());
    lv_obj_set_width(tabview, 1024);
    lv_obj_set_height(tabview, 600);

    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Grafico");
    lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Plugin Kilauea");
    lv_obj_t * tab3 = lv_tabview_add_tab(tabview, "Volcano");

    lv_obj_set_style_bg_color(tabview, lv_color_black(), 0);
    

    lv_obj_t * tab_buttons = lv_tabview_get_tab_bar(tabview);
    lv_obj_set_style_bg_color(tab_buttons, lv_color_hex(0x003D6E), 0);
    lv_obj_set_style_text_color(tab_buttons, lv_color_white(), 0);
    lv_obj_set_height(tab_buttons, 60);

    chart_screen(tab1);
    plugin_screen(tab2);
    volcano_screen(tab3);
}

