#define __USE_GNU
#define _GNU_SOURCE

// External Includes
#include <lapin.h>
#include <stdio.h>
#include <time.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>

// Project Includes
#include "typedef.h"
#include "macros.h"
#include "parameters.h"

// Response Function
t_bunny_response loop_function(void *d);
t_bunny_response key_event_response(t_bunny_event_state state, t_bunny_keysym keycode, void *data);
t_bunny_response display_function(void *d);
t_bunny_response mouse_click(t_bunny_event_state state, t_bunny_mouse_button button, void *d);

// Window Function
void create_main_data_window(t_main_data *data, char *name);

// Button Utils
t_button *adv_create_button(t_bunny_position pos, t_type type);
void adv_set_button_size(t_button *b, t_bunny_size s);
bool b_test(t_button *b, t_bunny_position pos);
void adv_set_button_pos(t_button *b, int x, int y);
void button_color(t_button *b, unsigned int color);
void adv_draw_button(t_bunny_pixelarray *px, t_button *b);

bool b_test(t_button *b, t_bunny_position pos);
void adv_set_button_pos(t_button *b, int x, int y);
void adv_set_button_size_rectangle(t_button *b, t_bunny_size s);
void adv_set_button_size_square(t_button *b, int s);
void adv_set_button_size_circle(t_button *b, int s);
void adv_set_button_size_ovale(t_button *b, int s, int sa);
void adv_set_button_fun(t_button *b, const char *sym);
void adv_remove_button(t_button *b);

// Drawing Functions
void adv_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);
unsigned int adv_get_pixel(t_bunny_pixelarray *px, t_bunny_position pos);
void adv_fill(t_bunny_pixelarray *px, unsigned int color);
void adv_fill_transp(t_bunny_pixelarray *px, unsigned int color);
void adv_set_line(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);
void adv_set_square(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);
void adv_set_circle(t_bunny_pixelarray *px, t_bunny_position pos, int radius, unsigned int *color);
void adv_set_ellipse(t_bunny_pixelarray *px, t_bunny_position pos, t_bunny_position radius, unsigned int color);
void show_node(t_bunny_pixelarray *px, t_graph *gr);
void show_link(t_bunny_pixelarray *px, t_graph *gr);
void adv_line_cpy(t_bunny_pixelarray *px, t_bunny_pixelarray *cpy, t_bunny_accurate_position *pos, t_bunny_accurate_position *tpos);
void adv_blit(t_bunny_pixelarray *target, t_bunny_pixelarray *src, const t_bunny_position *pos);
void adv_blit_img(t_bunny_pixelarray *target, t_bunny_pixelarray *src, const t_bunny_position *pos);
void adv_line_cpy_img(t_bunny_pixelarray *px, t_bunny_pixelarray *cpy, t_bunny_accurate_position *pos, t_bunny_accurate_position *tpos);

// Color Functions
unsigned char mix_pal(unsigned char a, unsigned char b, double t);
unsigned int mix_color(unsigned int a, unsigned int b);
unsigned int adv_gradient(t_bunny_position pos1, t_bunny_position pos2, t_bunny_position cpos, unsigned int c1, unsigned int c2);
unsigned int adv_circle_gradient(double dist, int radius, unsigned int color1, unsigned int color2);
void adv_set_ovale(t_bunny_pixelarray *px, t_bunny_position pos, int r, int rA, unsigned int color);

// Math Functions
double adv_pow(double a, double b);
void adv_coef_get(t_bunny_position pos1, t_bunny_position pos2, float *a, float *b);

// Utils Functions
int adv_strcmp(const char *s1, const char *s2);
void adv_memcpy(void *output, void *input, size_t size);
void *adv_realloc(void *ptr, size_t old_size, size_t new_size);
char *adv_strcpy(char *dest, const char *src);
char *adv_strdup(const char *str);
size_t adv_strlen(const char *str);
char *adv_strcat(const char *s1, const char *s2);
void adv_main_free(t_main_data data);

// Graph Functions
t_graph *graph_new(size_t elem_size);
t_node *graph_push(t_graph *gr, const char *key, void *data);
t_node *graph_get(t_graph *gr, const char *key);
bool graph_path_step(t_node *start, t_node *end, int nbr);
bool graph_path_conv(t_node *start, t_node *end, int nbr);
void graph_shortest_path(t_graph *gr, const char *start_node, const char *end_node);
void graph_link(t_graph *gr, const char *src_node, const char *target_node, double time);
void graph_unlink(t_graph *gr, const char *scr_node, const char *target_node);
void graph_delete(t_graph *gr);
void graph_pop(t_graph *gr, const char *key);
void graph_pop_linkclear(t_graph *gr, t_node *node);
size_t graph_pop_size(t_node *node);
size_t graph_size(t_graph *gr);
void graph_path_reset(t_graph *gr);
double graph_path_finder(t_main_data *data, t_graph *gr);
void graph_get_selectors(t_graph *gr, t_node **start, t_node **end);
t_bunny_position graph_get_player(t_graph *gr);
t_object graph_get_object(t_main_data *data);
size_t graph_get_scene(t_main_data *data);
t_object graph_get_condition(t_main_data *data);

t_node *adv_set_value(t_node *start);

// External Reading Functions
t_scene *adv_load_scene(const char *file);
t_game *adv_load_game(void);

// Game Functions
void adv_delete_game(t_game *game);
void adv_swap_scene(t_main_data *data);
void adv_get_object(t_main_data *data);
void adv_show_inventory(t_main_data *data);
void adv_dot(t_main_data *data, double index);

// Writing Functions
void adv_letter(t_bunny_pixelarray *px, t_bunny_pixelarray *font, t_bunny_position pos, char l);
void adv_phrase(t_bunny_pixelarray *px, t_bunny_pixelarray *font, t_bunny_position pos, char *l);
void adv_phrase_a(t_bunny_pixelarray *px, t_bunny_pixelarray *font, t_word_data wd);
void adv_text_color(t_bunny_pixelarray *font, unsigned int color);

// Player Function
t_player adv_new_player(const char *path);
void adv_player_clean(t_main_data *data);
void adv_move_player(t_bunny_pixelarray *fpx, t_bunny_pixelarray *px, t_bunny_position pos, int move);

// Extra
void adv_blit_img(t_bunny_pixelarray *target, t_bunny_pixelarray *src, const t_bunny_position *pos);
void adv_line_cpy_img(t_bunny_pixelarray *px, t_bunny_pixelarray *cpy, t_bunny_accurate_position *pos, t_bunny_accurate_position *tpos);
void adv_place_text(char *dest, char *src);
