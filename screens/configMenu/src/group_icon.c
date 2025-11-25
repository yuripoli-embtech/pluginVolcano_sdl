#include "../inc/configMenu.h"
#include "main/inc/ui.h"
#include "stdio.h"

static void icon_click_event_cb(lv_event_t * e)
{
    lv_obj_t * icon_clicked = lv_event_get_target(e);
    int index = (int)(intptr_t)lv_obj_get_user_data(icon_clicked);

    recipes_group[count_groups].icon_idx = index;

    count_groups++;
    lv_screen_load_anim(groups_screen(2), LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
}

lv_obj_t * group_icon_screen(void)
{   
    static lv_style_t main;
    static lv_style_t btn_style;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_pad_all(&main, 0);
        lv_style_set_border_width(&main, 0);
        lv_style_set_radius(&main, 0);
        lv_style_set_pad_row(&main, 0);
        lv_style_set_bg_color(&main, lv_color_black());
    }

    lv_obj_t * screen = lv_obj_create(NULL);
    lv_obj_add_style(screen, &main, 0);
    

    lv_obj_t * header = header_create(screen, "MENU");
    lv_obj_set_pos(header, 15, 15);

    lv_obj_t * principal = lv_obj_create(screen);
    lv_obj_set_size(principal, 800, 350);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_style_pad_all(principal, 10, 0);
    lv_obj_set_pos(principal, 0, 46); 
    lv_obj_set_scrollbar_mode(principal, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_layout(principal, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(principal, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(principal, 55, 0);

    lv_obj_t * row1 = lv_obj_create(principal);
    lv_obj_set_size(row1, LV_SIZE_CONTENT, LV_SIZE_CONTENT); 
    lv_obj_set_layout(row1, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(row1, LV_FLEX_FLOW_ROW); 
    lv_obj_set_style_pad_column(row1, 10, 0); 
    lv_obj_set_style_bg_opa(row1, LV_OPA_TRANSP, 0); 
    lv_obj_set_style_border_width(row1, 0, 0);
    lv_obj_set_style_margin_top(row1, 55, 0);
    lv_obj_set_style_pad_all(row1, 0, 0);

    for(int i = 0; i < 41; i++) {
        lv_obj_t * icon = lv_image_create(row1);
        lv_image_set_src(icon, groupIcons[0]); // Usando [0] por enquanto
        // lv_image_set_src(icon, groupIcons[i]); // <- Código final
        
        lv_obj_add_flag(icon, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_user_data(icon, (void*)(intptr_t)i); 
        lv_obj_add_event_cb(icon, icon_click_event_cb, LV_EVENT_CLICKED, NULL);
    }

    lv_obj_t * row2 = lv_obj_create(principal);
    lv_obj_set_size(row2, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_layout(row2, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(row2, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(row2, 10, 0);
    lv_obj_set_style_bg_opa(row2, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(row2, 0, 0);
    lv_obj_set_style_border_width(row2, 0, 0); 
    lv_obj_set_style_pad_all(row2, 0, 0);

    for(int i = 41; i < 81; i++) {
        lv_obj_t * icon = lv_image_create(row2);
        lv_image_set_src(icon, groupIcons[0]); // Usando [0] por enquanto
        // lv_image_set_src(icon, groupIcons[i]); // <- Código final

        lv_obj_add_flag(icon, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_user_data(icon, (void*)(intptr_t)i);
        lv_obj_add_event_cb(icon, icon_click_event_cb, LV_EVENT_CLICKED, NULL);
    }

    return screen;
}