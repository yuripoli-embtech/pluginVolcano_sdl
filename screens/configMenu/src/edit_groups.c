#include "../inc/configMenu.h"
#include "main/inc/ui.h"
#include "stdio.h"

lv_obj_t * edit_groups(int pos)
{   
    static lv_style_t main;
    static lv_style_t btn_style;

    lv_style_init(&main);
    lv_style_set_pad_all(&main, 0);
    lv_style_set_border_width(&main, 0);
    lv_style_set_radius(&main, 0);
    lv_style_set_pad_row(&main, 0);
    lv_style_set_bg_color(&main, lv_color_black());

    lv_style_init(&btn_style);
    lv_style_set_shadow_width(&btn_style, 0);
    lv_style_set_size(&btn_style, 100, 100);
    lv_style_set_radius(&btn_style, 23);
    
    lv_obj_t * screen = lv_obj_create(NULL);
    lv_obj_add_style(screen, &main, 0);

    header_create(screen, ""); 

    lv_obj_t * principal = lv_obj_create(screen);
    lv_obj_set_size(principal, 770, 350);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_pos(principal, 15, 46);
    lv_obj_set_style_border_width(principal, 1, 0); 
    
    //edit name
    lv_obj_t * btn1 = lv_button_create(principal);
    lv_obj_add_style(btn1, &btn_style, 0);
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0x8DD7F7), 0);
    lv_obj_t * label1 = lv_label_create(principal);
    lv_label_set_text(label1, "edit");
    lv_obj_align_to(label1, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon = lv_image_create(btn1);
    lv_image_set_src(icon, sac_icon);
    lv_obj_center(icon);

    //edit img
    lv_obj_t * btn2 = lv_button_create(principal);
    lv_obj_add_style(btn2, &btn_style, 0);
    lv_obj_set_style_bg_color(btn2, lv_color_hex(0x9AD2AE), 0);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_RIGHT_MID, 80, 0);
    lv_obj_t * label2 = lv_label_create(principal);
    lv_label_set_text(label2, "edit");
    lv_obj_align_to(label2, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon2 = lv_image_create(btn2);
    lv_image_set_src(icon2, sac_icon);
    lv_obj_center(icon2);

    //delete recipes
    lv_obj_t * btn3 = lv_button_create(principal);
    lv_obj_add_style(btn3, &btn_style, 0);
    lv_obj_set_style_bg_color(btn3, lv_color_hex(0xFF9C53), 0);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_RIGHT_MID, 80, 0);
    lv_obj_t * label3 = lv_label_create(principal);
    lv_label_set_text(label3, "edit");
    lv_obj_align_to(label3, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label3, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon3 = lv_image_create(btn3);
    lv_image_set_src(icon3, sac_icon);
    lv_obj_center(icon3);

    //delete group
    lv_obj_t * btn4 = lv_button_create(principal);
    lv_obj_add_style(btn4, &btn_style, 0);
    lv_obj_set_style_bg_color(btn4, lv_color_hex(0xF2C94C), 0);
    lv_obj_align_to(btn4, btn3, LV_ALIGN_OUT_RIGHT_MID, 80, 0);
    lv_obj_t * label4 = lv_label_create(principal);
    lv_label_set_text(label4, "edit");
    lv_obj_align_to(label4, btn4, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label4, LV_TEXT_ALIGN_CENTER, 0); 
    lv_obj_t * icon4 = lv_image_create(btn4);
    lv_image_set_src(icon4, sac_icon);
    lv_obj_center(icon4);

    //ordenar
    lv_obj_t * btn5 = lv_button_create(principal);
    lv_obj_add_style(btn5, &btn_style, 0);
    lv_obj_set_style_bg_color(btn5, lv_color_hex(0x62BC5A), 0);
    lv_obj_set_y(btn5, 180);
    lv_obj_t * label5 = lv_label_create(principal);
    lv_label_set_text(label5, "edit");
    lv_obj_align_to(label5, btn5, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label5, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon5 = lv_image_create(btn5);
    lv_image_set_src(icon5, sac_icon);
    lv_obj_center(icon5);

    //change temp
    lv_obj_t * btn6 = lv_button_create(principal);
    lv_obj_add_style(btn6, &btn_style, 0);
    lv_obj_set_style_bg_color(btn6, lv_color_hex(0x6791D8), 0);
    lv_obj_align_to(btn6, btn5, LV_ALIGN_OUT_RIGHT_MID, 80, 0);
    lv_obj_t * label6 = lv_label_create(principal);
    lv_label_set_text(label6, "edit");
    lv_obj_align_to(label6, btn6, LV_ALIGN_OUT_BOTTOM_MID, 0, 3);
    lv_obj_set_style_text_align(label6, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * icon6 = lv_image_create(btn6);
    lv_image_set_src(icon6, usb_icon);
    lv_obj_center(icon6);


    return screen;
}