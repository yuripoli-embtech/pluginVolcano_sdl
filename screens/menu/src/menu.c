#include "../inc/menu.h"
#include "main/inc/ui.h"

lv_obj_t * menu_create(void)
{
    static lv_style_t main;

    lv_style_init(&main);
    lv_style_set_pad_all(&main, 0);
    lv_style_set_border_width(&main, 0);
    lv_style_set_radius(&main, 0);
    lv_style_set_layout(&main, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(&main, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(&main, 0);
    lv_style_set_bg_color(&main, lv_color_black());

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_0, &main, 0);

    //header
    header_create(lv_obj_0, "");

    //Temperatures
    lv_obj_t * temperature = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(temperature, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_width(temperature, 776);
    lv_obj_set_height(temperature, 150);
    lv_obj_set_style_margin_left(temperature, 12, 0);
    lv_obj_set_style_bg_color(temperature, lv_color_black(), 0);
    lv_obj_set_style_border_width(temperature, 4, 0);
    lv_obj_set_style_pad_all(temperature, 0, 0);
    lv_obj_set_layout(temperature, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(temperature, LV_FLEX_COLUMN);
    lv_obj_set_style_pad_gap(temperature, 0, 0);

    lv_obj_t * temp_label = lv_label_create(temperature);
    lv_label_set_text(temp_label, "TEMPERATURA");
    lv_obj_set_style_text_color(temp_label, lv_color_white(), 0);
    lv_obj_set_style_text_font(temp_label, font30, 0);
    lv_obj_set_width(temp_label, 776);  
    lv_obj_set_style_text_align(temp_label, LV_TEXT_ALIGN_CENTER, 0);
 
    lv_obj_t * celsius = lv_obj_create(temperature);
    lv_obj_set_width(celsius, 776);
    lv_obj_set_style_bg_color(celsius, lv_color_black(), 0);
    lv_obj_set_style_border_width(celsius, 0, 0);
    lv_obj_set_layout(celsius, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(celsius, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(celsius, LV_FLEX_ALIGN_SPACE_AROUND, 0, 0);
    lv_obj_set_style_pad_top(celsius, 8, 0);

    //CAMARA
    lv_obj_t * camara = lv_obj_create(celsius);
    lv_obj_set_flag(camara, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(camara, lv_color_black(), 0);
    lv_obj_set_width(camara, 160);
    lv_obj_set_height(camara, 90);
    lv_obj_set_style_pad_all(camara, 0, 0);
    lv_obj_set_layout(camara, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(camara, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_border_width(camara, 0, 0);
    lv_obj_set_style_pad_gap(camara, 0, 0);
    
    lv_obj_t * camara_label = lv_label_create(camara);
    lv_label_set_text(camara_label, "CÂMARA");
    lv_obj_set_width(camara_label, 160);
    lv_obj_set_style_text_color(camara_label, lv_color_white(), 0);
    lv_obj_set_style_text_font(camara_label, font24, 0);
    lv_obj_set_style_text_align(camara_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * celsius_label = lv_label_create(camara);
    lv_label_set_text(celsius_label, "250°C");
    lv_obj_set_width(celsius_label, 160);
    lv_obj_set_style_text_color(celsius_label, lv_color_white(), 0);
    lv_obj_set_style_text_font(celsius_label, font50, 0);
    lv_obj_set_style_text_align(celsius_label, LV_TEXT_ALIGN_CENTER, 0);

    //Thermometer Icon
    lv_obj_t * thermometer = lv_obj_create(celsius);
    lv_obj_set_width(thermometer, 160);
    lv_obj_set_flag(thermometer, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(thermometer, lv_color_black(), 0);
    lv_obj_set_width(thermometer, 160);
    lv_obj_set_height(thermometer, 90);
    lv_obj_set_style_pad_all(thermometer, 0, 0);
    lv_obj_set_style_border_width(thermometer, 0, 0);
    
    lv_obj_t * therm_icon = lv_image_create(thermometer);
    lv_image_set_src(therm_icon, termometrob_icon);
    lv_obj_set_align(therm_icon, LV_ALIGN_CENTER);
    
    //IR
    lv_obj_t * ir = lv_obj_create(celsius);
    lv_obj_set_flag(ir, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(ir, lv_color_black(), 0);
    lv_obj_set_width(ir, 160);
    lv_obj_set_height(ir, 90);
    lv_obj_set_style_pad_all(ir, 0, 0);
    lv_obj_set_layout(ir, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(ir, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_border_width(ir, 0, 0);
    lv_obj_set_style_pad_gap(ir, 0, 0);
    
    lv_obj_t * ir_label = lv_label_create(ir);
    lv_label_set_text(ir_label, "IR");
    lv_obj_set_width(ir_label, 160);
    lv_obj_set_style_text_color(ir_label, lv_color_white(), 0);
    lv_obj_set_style_text_font(ir_label, font24, 0);
    lv_obj_set_style_text_align(ir_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_t * celsius_label2 = lv_label_create(ir);
    lv_label_set_text(celsius_label2, "250°C");
    lv_obj_set_width(celsius_label2, 160);
    lv_obj_set_style_text_color(celsius_label2, lv_color_white(), 0);
    lv_obj_set_style_text_font(celsius_label2, font50, 0);
    lv_obj_set_style_text_align(celsius_label2, LV_TEXT_ALIGN_CENTER, 0);

    //menu buttons
    lv_obj_t * btns = lv_obj_create(lv_obj_0);
    lv_obj_set_width(btns, 776);
    lv_obj_set_height(btns, 160);
    lv_obj_set_style_margin_left(btns, 12, 0);
    lv_obj_set_style_bg_color(btns, lv_color_black(), 0);
    lv_obj_set_style_border_width(btns, 0, 0);
    lv_obj_set_style_margin_top(btns, 20, 0);
    lv_obj_set_flex_flow(btns, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_all(btns, 0, 0);
    lv_obj_set_flag(btns, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_pad_gap(btns, 0, 0); 

    lv_obj_t * manualMode_btn = menuBtns_create(btns, "MODO MANUAL", ajustes_icon, 0x06A24A);
    lv_obj_add_screen_create_event(manualMode_btn, LV_EVENT_CLICKED, manualMode_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    lv_obj_t * fav_btn = menuBtns_create(btns, "FAVORITOS", favs_icon, 0xF2C94C);
    lv_obj_t * clean_btn = menuBtns_create(btns, "GUIA DE LIMPEZA DIÁRIA", limpeza_icon, 0x00A8E9);
    lv_obj_t * config_btn = menuBtns_create(btns, "CONFIGURAÇÕES", configs_icon, 0xF8A98E);
    lv_obj_add_screen_create_event(config_btn, LV_EVENT_CLICKED, configPass_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    lv_obj_set_style_margin_bottom(btns, 20, 0);

    //footer
    footer1_create(lv_obj_0);

    return lv_obj_0;
}


