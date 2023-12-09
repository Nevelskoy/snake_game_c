extern int timeout;
extern bool game_on;

void init_game();
void clear_snake();
void set_snake();
void check_eating();
void check_game();
void set_food();
void handle_cmd(bool handle);