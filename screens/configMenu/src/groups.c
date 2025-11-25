#include "../inc/configMenu.h"
#include "main/inc/ui.h"
#include "stdio.h"

static int mode_type;

static void group_clicked(lv_event_t * e)
{
    lv_obj_t * icon_clicked = lv_event_get_target(e);
    int index = (int)(intptr_t)lv_obj_get_user_data(icon_clicked);
    
    if(mode_type == 1){

    } else {
        lv_screen_load_anim(edit_groups(index), LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    }
}


lv_obj_t * groups_screen(int type)
{   
    mode_type = type;
    static lv_style_t main;
    static lv_style_t tilestyle;

    static bool style_inited = false;

    int pos_par = 0;
    int pos_impar = 120;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_pad_all(&main, 0);
        lv_style_set_border_width(&main, 0);
        lv_style_set_radius(&main, 0);
        lv_style_set_pad_row(&main, 0);
        lv_style_set_bg_color(&main, lv_color_black());

        lv_style_init(&tilestyle);
        lv_style_set_text_font(&tilestyle, font24);
        lv_style_set_text_color(&tilestyle, lv_color_white());
        lv_style_set_size(&tilestyle, 770, 350);
        lv_style_set_pad_all(&tilestyle, 0);
    }

    lv_obj_t * screen = lv_obj_create(NULL);
    lv_obj_add_style(screen, &main, 0);

    lv_obj_t * principal = lv_obj_create(screen);
    lv_obj_set_size(principal, 800, 350);
    lv_obj_set_style_margin_left(principal, 15, 0);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_style_pad_all(principal, 0, 0);
    lv_obj_set_pos(principal, 0, 46); 

    LV_IMAGE_DECLARE(new_icon);
    lv_obj_t * new = lv_image_create(principal);
    lv_image_set_src(new, &new_icon);
    lv_obj_add_flag(new, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_pos(new, 15, 10);
    lv_obj_t * label_new = lv_label_create(principal);
    lv_label_set_text(label_new, "CRIAR NOVO GRUPO");
    lv_obj_set_style_text_font(label_new, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label_new, lv_color_white(), 0);
    lv_obj_align_to(label_new, new, LV_ALIGN_OUT_BOTTOM_MID, 0, 6);
    if(count_groups == 64) {
        printf("%d, maximo", count_groups);
    } else {
        lv_obj_add_screen_create_event(new, LV_EVENT_CLICKED, group_name_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    }

    for(int i = 0; i < count_groups; i++){
        lv_obj_t * group = lv_image_create(principal);
        lv_image_set_src(group, &folder_groups_icon);
        lv_obj_t * group_name = lv_label_create(principal);
        lv_label_set_text(group_name, recipes_group[i].name);
        lv_obj_set_style_text_font(group_name, &lv_font_montserrat_16, 0);
        lv_obj_set_style_text_color(group_name, lv_color_white(), 0);

        lv_obj_t * icon = lv_image_create(group);
        lv_image_set_src(icon, groupIcons[recipes_group[i].icon_idx]);
        lv_image_set_scale(icon, 128);
        lv_obj_center(icon);

        lv_obj_add_flag(group, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_user_data(group, (void*)(intptr_t)i); 
        lv_obj_add_event_cb(group, group_clicked, LV_EVENT_CLICKED, NULL);

        if(i%2 == 0) {
            lv_obj_set_pos(group, 15 + pos_par, 180);
        } else {
            lv_obj_set_pos(group, 15 + pos_impar, 0);
        }

        lv_obj_align_to(group_name, group, LV_ALIGN_OUT_BOTTOM_MID, 0, 6);
        pos_par = pos_par + 120;
        pos_impar = pos_impar + 120;
    }


    return screen;
}