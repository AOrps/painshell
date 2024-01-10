#include "lockshell.h"
#include <time.h>

/* volatile sig_atomic_t sigint_flag = 0; */
/* volatile sig_atomic_t sigtstp_flag = 0; */
/* volatile sig_atomic_t sigquit_flag = 0; */
/* volatile sig_atomic_t sigabrt_flag = 0; */
/* volatile sig_atomic_t sigterm_flag = 0; */
/* volatile sig_atomic_t sigalarm_flag = 0; */


void sigint_handler() {
  printf("Caught SIGINT!\n");  
  running = 1;
  /* sigint_flag = 1; */

  file_logger2("tagger", "sigint");
}

void sigtstp_handler() {
  printf("Caught SIGTSTP\n");
  running = 1;
  /* sigtstp_flag = 1; */

  file_logger2("tagger", "sigtstp");  
}

void sigquit_handler() {
  printf("Caught SIGQUIT!\n");
  running = 1;
  /* sigquit_flag = 1; */

  file_logger2("tagger", "sigquit");    
}

void sigabort_handler() {
  printf("caught SIGABRT!\n");
  running = 1;
  /* sigabrt_flag = 1; */

  file_logger2("tagger", "sigabort");      
}

void sigtermsigabort_handler() {
  printf("caught SIGTERM!\n");
  running = 1;
  /* sigterm_flag = 1; */

  file_logger2("tagger", "sigterm");    
}

void sigalarm_handler(int sig) {
  running = 0;
  signal(sig, sigalarm_handler);
  /* sigalarm_flag = 1; */

  file_logger2("tagger", "sigalrm");      
}

/* void flag_reset() { */
/*     sigint_flag = 0; */
/*     sigtstp_flag = 0; */
/*     sigquit_flag = 0; */
/*     sigabrt_flag = 0; */
/*     sigterm_flag = 0; */
/*     sigalarm_flag = 0; */
/* } */
    


void sigwriter(int sig) {
  time_t now = 0xdeadbeef;
  time(&now);

  /* malloclog_msg =  */
  FILE *fp = NULL;
  
  fp = fopen("./losh.log","a");
  if(fp == NULL) {
    perror("error:");
  }
  fprintf(fp,"%ld [%d] \n", now, sig);

  // Using UNIX epoch time
  /* printf("%ld [%s]: %s\n",now, tag, msg); */

  fclose(fp);
  fp = NULL;

}
