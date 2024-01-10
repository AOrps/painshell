#ifndef LOCKSHELL_H
#define LOCKSHELL_H
#include <stdio.h>
#include <signal.h>

// Build Options

// TIMEOUT in seconds
#define LOSH_TIMEOUT 10

// Logging File
#define LOSH_LOG "./losh.log"

// Log Format (to put onto %s)
#define LOG_FORMAT "%s-%ld-%ld"

// Playback on the Shell
#define LOSH_PLAYBACK "./playback-%s.log"

extern volatile sig_atomic_t running;
extern struct identifier globalID;

// Signal Handlers

extern volatile sig_atomic_t sigint_flag;
extern volatile sig_atomic_t sigtstp_flag;
extern volatile sig_atomic_t sigquit_flag;
extern volatile sig_atomic_t sigabrt_flag;
extern volatile sig_atomic_t sigterm_flag;
extern volatile sig_atomic_t sigalarm_flag;

void sigint_handler();
void sigtstp_handler();
void sigquit_handler();
void sigalarm_handler(int);
void sigabort_handler();
void sigterm_handler();
void flag_reset();
void sigwriter(int);


// Log Writing
struct identifier {
    long Epoch;
    long Nanosec;
    char Unique[20];
};
void new_id(struct identifier*);
void sess_id(char[], struct identifier*);
void f_log(char*, struct identifier*, const char*);
void p_log(struct identifier*, char[]);
void stdout_logger(const char* tag, const char* message);
void file_logger(const char* tag, const char* message, const char* filename);
void file_logger2(const char* tag, const char* message);




// Testing




#endif // LOCKSHELL_H


