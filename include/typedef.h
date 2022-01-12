typedef struct s_main_data t_main_data;

/* Graphs */
typedef enum e_object
{
    OBJ_NONE,
    OBJ_KEY_1,
    OBJ_KEY_2,
    OBJ_KEY_3,
    OBJ_KEY_4,
    OBJ_KEY_5,
    OBJ_KEY_6,
    OBJ_KEY_7,
    OBJ_KEY_8,
    OBJ_KEY_9
} t_object;

typedef enum e_state
{
    ACT_CLEAR,
    ACT_PLAYER,
    ACT_WAS_PLAYER
} t_state;

/**********enumeration pour les types de boutons**********/
typedef enum e_type
{
    circle,
    square,
    rectangle,
    ovale
} t_type;

/**********positionnement du texte**********/
typedef enum s_word_pos
{
    right,
    center,
    left
} t_word_pos;

/* Graphs */
typedef struct s_node
{
    struct s_node **nodes;
    double *time;
    void *data;
    char *key;
    int step;
    t_object obj;
} t_node;

typedef struct s_content
{
    t_bunny_position pos;
    t_bunny_position radius;
    t_state state;
    t_object obj;
    t_object condition;
    size_t scene;
} t_content;

typedef struct s_graph
{
    t_node **nodes;
    size_t node_nbr;
    size_t data_size;
} t_graph;

/**********Données sur l'objets**********/
typedef struct s_objpos
{
    t_bunny_position pos;
    t_bunny_position orad;
    int width;
    int height;
    int radius;
} t_objpos;

/**********Bouttons**********/
typedef struct s_button
{
    t_objpos data;
    t_type type;
    bool isClick;
    void *dlh;
    void (*fun)(t_main_data *data);
    bool visi;
    t_bunny_color color;
} t_button;

/**********paramètre du texte**********/
typedef struct s_word_data
{
    char mots[256];
    t_bunny_position pos;
    t_word_pos positionnement;
} t_word_data;

typedef struct s_scene
{
    t_graph *gr;
    t_bunny_pixelarray *background;
    const char *name;
} t_scene;

typedef struct s_inventory
{
    t_object *objs;
    size_t nbr_obj;
} t_inventory;

typedef struct s_player
{
    t_bunny_pixelarray *sprites;
    t_inventory inventory;
} t_player;

typedef enum e_game_state
{
    GAM_PROGRESS,
    GAM_PAUSE,
    GAM_END,
    GAM_SECRET
} t_game_state;

typedef struct s_game
{
    t_scene **scenes;
    size_t nbr_scene;
    size_t current_scene;
    t_player player;
    t_game_state state;
    bool pause_bool;
} t_game;

// Main package
typedef struct s_main_data
{
    t_bunny_window *win;
    t_bunny_pixelarray *px; // the normal pixelarray print it !
    t_bunny_pixelarray *font;
    t_bunny_size screen_size;
    t_button *b[2];
    int selec;
    double start_time;
    double total_time;
    t_game *game;
    bool debug;
} t_main_data;
