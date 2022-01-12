/**********gestion des couleurs**********/
#define adv_to_red(V) (((V)&0xFF) << (0 * 8))
#define adv_to_green(V) (((V)&0xFF) << (1 * 8))
#define adv_to_blue(V) (((V)&0xFF) << (2 * 8))
#define adv_to_alpha(V) (((V)&0xFF) << (3 * 8))
#define adv_get_color(c) ((c) & ~adv_to_alpha(255))
#define adv_get_alpha(c) ((c) & (~adv_to_red(255) | ~adv_to_green(255) | ~adv_to_blue(255))) >> (24)
#define adv_color(A, R, G, B) \
	(adv_to_alpha(A) | adv_to_red(R) | adv_to_green(G) | adv_to_blue(B))

/**********opérateurs mathématiques**********/
#define abs(a) a > 0 ? a : -a
#define min(a, b) a > b ? b : a
#define max(a, b) a < b ? b : a
#define clamp(a, b, c) a<b ? b : a> c ? c : a
#define rclamp(a, b, c) a<b ? c : a> c ? b : a
#define diff(a, b) (a - b) > 0 ? (a - b) : (b - a)

/* Utils */
#define CHECK_EXT(FILE, EXT) (adv_strcmp(&FILE[adv_strlen(FILE) - 4], EXT) == 0)
