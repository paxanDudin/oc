#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include "main.h" 
#include <iostream.h> 
#include <semaphore.h> 
#include <fstream.h> 
#include <stdio.h> 
#include <error.h> 
void* WriteToFile(void*); 
int errno; 
sem_t psem; 
ofstream qfwrite;  
int main(int argc, char **argv) { 
pthread_t tidA,tidB; 
int n; 
char filename[] = "./rezult.txt"; 
qfwrite.open(&filename[0]); 
sem_init(&psem,0,0); 
sem_post(&psem))  
	pthread_create(&tidA,NULL,&WriteToFile,(void*)100));  
	pthread_create(&tidB,NULL,&WriteToFile,(void*)100));  
	pthread_join(tidA,NULL));  
	pthread_join(tidB,NULL)); 
sem_destroy(&psem)); 
qfwrite.close(); 
} 
void* WriteToFile(void *f){ 
int max = (int)f; 
for (int i=0; i<=max; i++)  
{       
	sem_wait(&psem);       
	qfwrite<<pthread_self()<<"-writetofilecounter i="<<i<<endl;            
	qfwrite<<flush;       
	sem_post(&psem);  
} 
return NULL; 
}
