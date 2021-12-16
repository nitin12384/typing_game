#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

// 0 - No Test
// 1 - Testing configuration 1 : Small number of lines
// 2 - Testing configuration 2 : Just one text to type
#define TEST_MODE 0



// default sizes
#define MAIN_WIN_SIZEX 740
#define MAIN_WIN_SIZEY 580

#define OTHER_WIN_SIZEX 540
#define OTHER_WIN_SIZEY 380



// file names
#define HELP_FILE_NAME "./src/help_en.txt"
#define SENTENCES_FILE_1 "./src/1000lines.txt"
#define NUM_LINES_1 1000
#define MIN_CHAR_LINE_1 50

#define LOGS_FOLDER "./logs/"


// Icon File Names
#define MAIN_APP_ICON_FILE "./src/app.ico"
#define HELP_ICON_FILE "./src/help_transp.png"
#define SETTINGS_ICON_FILE "./src/settings_transp.png"
#define START_ICON_FILE "./src/start_transp.png"
#define BACK_ICON_FILE "./src/back_transp.png"



// Default Texts
#define ORGANISATION_NAME "nitin_kumar"
#define APPLICATION_NAME "typing_pro"
#define WON_TEXT "You won"
#define HELP_DEFAULT "Help file could not be loaded"
#define DEFAULT_LINE "He was just listening to pumped up kicks"

// User Data Keys
#define BEST_SCORE_KEY "best_score"
#define BEST_SPEED_KEY "best_speed"
#define AVG_SPEED_KEY "avg_speed"
#define NUM_WORDS_KEY "num_words"

// Scoring Configurations
#define WRONG_PENALTY 10
#define AVG_EXP_PRESS_TIME 100 // In msec
#define AVG_CORRECT_SCORE 10

#endif // CONFIGURATIONS_H
