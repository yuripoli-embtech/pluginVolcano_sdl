#include "charts.h"
#include "main/ui.h"
#include "main/components/thermometer.h"
#include "main/components/humidity.h"
#include "main/components/arc_humidity.h"
#include "main/components/arc_luminosidade.h"
#include "main/components/chart_temperatura.h"

lv_obj_t * chart_screen(lv_obj_t * tab)
{
    static lv_style_t main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_pad_all(&main, 0);
        lv_style_set_border_width(&main, 0);
        lv_style_set_radius(&main, 0);
        lv_style_set_layout(&main, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&main, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&main, 0);

        style_inited = true;
    }

    lv_obj_add_style(tab, &main, 0);

    lv_obj_t * tv = lv_tileview_create(tab);
    lv_obj_set_style_bg_color(tv, lv_color_white(), 0);

    
    /*Tile1*/
    lv_obj_t * tile1 = lv_tileview_add_tile(tv, 0, 0, LV_DIR_BOTTOM);
    
    /*Temperatura atual*/
    thermometer_comp(tile1);

    /*Grafico - TEMPERATURA*/
    chart_temperatura(tile1);

    /*EMBTECH FOOTER*/
    lv_obj_t * embtech_img = lv_image_create(tile1);
    lv_image_set_src(embtech_img, embtech);
    lv_obj_align(embtech_img, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    /*Tile2*/
    lv_obj_t * tile2 = lv_tileview_add_tile(tv, 0, 1, LV_DIR_TOP);

    /*ARC UMIDADE*/
    arc_humidity(tile2);
    arc_luminosidade(tile2);

    /*EMBTECH FOOTER*/
    lv_obj_t * embtech_img2 = lv_image_create(tile2);
    lv_image_set_src(embtech_img2, embtech);
    lv_obj_align(embtech_img2, LV_ALIGN_BOTTOM_LEFT, 0, 0);
}
