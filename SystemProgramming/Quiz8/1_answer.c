#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<pthread.h>
#include<unistd.h>
int counter=0;
#define NUM_THREAD 100
pthread_mutex_t lock;
void * thr_main(void* arg){
	pthread_mutex_lock(&lock);
	int c=counter;
	usleep(1);
	counter=c+1;
	pthread_mutex_unlock(&lock);
	return ((void*)1);
}
int main(void){
	int err,i;
	pthread_t tid[NUM_THREAD];
	void *ret;
	for(i=0;i<NUM_THREAD;i++){
		if(pthread_create(&tid[i],NULL,thr_main,NULL))
			exit(1);
	}
	for(i=0;i<NUM_THREAD;i++){
		if(pthread_join(tid[i],&ret))
			exit(2);
	}
	printf("done %d\n",counter);
	return 0;
}

