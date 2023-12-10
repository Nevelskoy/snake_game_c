extern int timeout;
extern bool game_on;
extern STATUS status;

void init_game();
void status_bar();
void clear_snake();
void set_snake();
void check_eating();
void check_game();
void set_food();
void handle_cmd(bool handle);