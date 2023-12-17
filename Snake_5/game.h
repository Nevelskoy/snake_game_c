extern int timeout;
extern bool game_on;

void init_game();
void set_snake();
void check_eating();
void check_game();
void set_food();
void handle_cmd(bool handle);