#include "../inc/configMenu.h"
#include "main/inc/ui.h"

static void groups_cb();

lv_obj_t * configMenu_screen(void){
    
    static lv_style_t main;
    static lv_style_t tilestyle;
    static lv_style_t btn_style;

    lv_style_init(&main);
    lv_style_set_pad_all(&main, 0);
    lv_style_set_border_width(&main, 0);
    lv_style_set_radius(&main, 0);
    lv_style_set_layout(&main, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(&main, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(&main, 0);
    lv_style_set_bg_color(&main, lv_color_black());

    lv_style_init(&tilestyle);
    lv_style_set_text_font(&tilestyle, font24);
    lv_style_set_text_color(&tilestyle, lv_color_white());
    lv_style_set_size(&tilestyle, 700, 350);
    lv_style_set_pad_top(&tilestyle, 10);
    lv_style_set_pad_left(&tilestyle, 65);
    lv_style_set_pad_right(&tilestyle, 65);
    lv_style_set_pad_bottom(&tilestyle, 0);

    lv_style_init(&btn_style);
    lv_style_set_shadow_width(&btn_style, 0);
    lv_style_set_size(&btn_style, 100, 100);
    lv_style_set_radius(&btn_style, 23);

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_0, &main, 0);

    /* HEADER */
    

    /* TILEVIEW */
    lv_obj_t * principal = lv_tileview_create(lv_obj_0);
    lv_obj_set_size(principal, 770, 350);
    lv_obj_set_style_margin_left(principal, 15, 0);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_scrollbar_mode(principal, LV_SCROLLBAR_MODE_OFF); 
    
    lv_obj_t * tile1 = lv_tileview_add_tile(principal, 0, 0, LV_DIR_RIGHT);
    lv_obj_add_style(tile1, &tilestyle, 0);
    lv_obj_set_flag(tile1, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_t * tile2 = lv_tileview_add_tile(principal, 1, 0, LV_DIR_LEFT);
    lv_obj_add_style(tile2, &tilestyle, 0);
    lv_obj_set_flag(tile2, LV_OBJ_FLAG_SCROLLABLE, false);

    /* BUTTONS TILE1 */
    //edit group
    lv_obj_t * btn1 = lv_button_create(tile1);
    lv_obj_add_style(btn1, &btn_style, 0);
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0xFFE72F), 0);
    lv_obj_t * label1 = lv_label_create(tile1);
    lv_label_set_text(label1, "EDITAR GRUPOS");
    lv_obj_set_width(label1, 110);
    lv_obj_align_to(label1, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon = lv_image_create(btn1);
    lv_image_set_src(icon, editGroup_icon);
    lv_obj_center(icon);
    lv_obj_add_event_cb(btn1, groups_cb, LV_EVENT_CLICKED, NULL);

    footer2_create(lv_obj_0);

    return lv_obj_0;
}

static void groups_cb()
{
    lv_screen_load_anim(groups_screen(2), LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
}