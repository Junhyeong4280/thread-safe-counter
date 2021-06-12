#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


typedef struct __counter_t {
	int value;
	sem_t semapho;
}counter_s;

unsigned int loop_cnt;
counter_s counter;

void init(counter_s *c,int svalue){
	c->value=0;
	sem_init(&c->semapho,0,svalue);


}

void increment(counter_s *c){
	sem_wait(&c->semapho);
	c->value++;
	sem_post(&c->semapho);

}

void decrement(counter_s *c){
	sem_wait(&c->semapho);
        c->value--;
        sem_post(&c->semapho);
}

int get(counter_s *c){
	sem_wait(&c->semapho);
        int rc = c->value;
        sem_post(&c->semapho);	
	
	return rc;
}

void *mythread(void *arg)
{
	char *letter = arg;
	int i;

	printf("%s: begin\n",letter);
	for(i=0;i<loop_cnt;i++){
		increment(&counter);
	}

	printf("%s:done\n",letter);
	return NULL;
}

int main(int argc, char *argv[])
{

	loop_cnt=atoi(argv[1]);
	
	init(&counter,1);

	pthread_t p1,p2;
	printf("main:begin [counter=%d]\n",get(&counter));
	pthread_create(&p1,NULL,mythread,"A");
	pthread_create(&p2,NULL,mythread,"B");

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);

	printf("main : done [ counter:%d] [should be : %d]\n",get(&counter),loop_cnt*2);
return 0;
}
