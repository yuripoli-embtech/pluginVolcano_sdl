#include "arc_humidity.h"
#include "main/ui.h"

static lv_style_t style_title;
static lv_style_t style_bullet;

static lv_obj_t * scale1;

static lv_obj_t * create_scale_box(lv_obj_t * parent, const char * title, const char * text1);
static void scale1_indic1_anim_cb(void * var, int32_t v);

lv_obj_t * arc_humidity(lv_obj_t * tile){
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_title);
        lv_style_set_text_font(&style_title, font_large);

        lv_style_init(&style_bullet);
        lv_style_set_border_width(&style_bullet, 0);
        lv_style_set_radius(&style_bullet, LV_RADIUS_CIRCLE);

        style_inited = true;
    }

    scale1 = create_scale_box(tile, "Umidade", "Atual: -");
    lv_obj_add_flag(lv_obj_get_parent(scale1), LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

    lv_obj_set_size(scale1, 200, 200);

    static const char * scale_texts[] = {"0", "50%", "100%", NULL};
    lv_scale_set_text_src(scale1, scale_texts); 
    lv_obj_set_style_pad_all(scale1, 15, 0);

    lv_obj_t * arc;
    arc = lv_arc_create(scale1);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
    lv_obj_remove_style(arc, NULL, LV_PART_MAIN);
    lv_obj_set_size(arc, lv_pct(100), lv_pct(100));
    lv_obj_set_style_arc_opa(arc, 0, 0);
    lv_obj_set_style_arc_width(arc, 15, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
    lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_values(&a, 20, 100);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    lv_anim_set_exec_cb(&a, scale1_indic1_anim_cb);
    lv_anim_set_var(&a, arc);
    lv_anim_set_duration(&a, 4100);
    lv_anim_set_reverse_duration(&a, 2700);
    lv_anim_start(&a);
}

static lv_obj_t * create_scale_box(lv_obj_t * parent, const char * title, const char * text1)
{
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_set_height(cont, 380);
    lv_obj_set_width(cont, 245);
    lv_obj_set_flex_grow(cont, 1);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_set_x(cont, 245);
    lv_obj_set_y(cont, 100);

    lv_obj_t * title_label = lv_label_create(cont);
    lv_label_set_text_static(title_label, title);
    lv_obj_add_style(title_label, &style_title, 0);

    lv_obj_t * scale = lv_scale_create(cont);
    lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_post_draw(scale, true);
    lv_obj_set_width(scale, LV_PCT(100));

    lv_obj_t * bullet1 = lv_obj_create(cont);
    lv_obj_set_size(bullet1, 13, 13);
    lv_obj_remove_style(bullet1, NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet1, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet1, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_t * label1 = lv_label_create(cont);
    lv_label_set_text_static(label1, text1);

    lv_obj_t * bullet2 = lv_obj_create(cont);
    lv_obj_set_size(bullet2, 13, 13);
    lv_obj_remove_style(bullet2, NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet2, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet2, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_t * label2 = lv_label_create(cont);

    lv_obj_t * bullet3 = lv_obj_create(cont);
    lv_obj_set_size(bullet3, 13, 13);
    lv_obj_remove_style(bullet3,  NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet3, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet3, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_obj_t * label3 = lv_label_create(cont);

    static int32_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    
    lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);
    lv_obj_set_grid_cell(title_label, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 0, 1);
    lv_obj_set_grid_cell(scale, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 1, 1);
    lv_obj_set_grid_cell(bullet1, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 2, 1);
    lv_obj_set_grid_cell(bullet2, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 3, 1);
    lv_obj_set_grid_cell(bullet3, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 4, 1);
    lv_obj_set_grid_cell(label1, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 2, 1);
    lv_obj_set_grid_cell(label2, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 3, 1);
    lv_obj_set_grid_cell(label3, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 4, 1);

    return scale;
}

static void scale1_indic1_anim_cb(void * var, int32_t v)
{
    lv_arc_set_value(var, v);

    lv_obj_t * card = lv_obj_get_parent(scale1);
    lv_obj_t * label = lv_obj_get_child(card, -5);
    lv_label_set_text_fmt(label, "Atual: %"LV_PRId32" %%", v);
}