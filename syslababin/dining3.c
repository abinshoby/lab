#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

void *func(int n)
   {
  // printf ("Philosopher %d is thinking\n",n+1);
	printf("Philosopher %d is hungry\n",n+1);
   pthread_mutex_lock(&chopstick[n]);
   pthread_mutex_lock(&chopstick[(n+1)%5]);
   printf ("Philosopher %d is eating with chopsticks %d and %d \n",n+1,n+1,(n+1)%5+1 );
   sleep(3);
    printf ("Philosopher %d is thinking\n",n+1);
   pthread_mutex_unlock(&chopstick[n]);
   pthread_mutex_unlock(&chopstick[(n+1)%5]);
// sleep(3);
  

   return(NULL);
   }

int main()
   {
   int i;
   for(i=0;i<5;i++)
      pthread_mutex_init(&chopstick[i],NULL);
   for(i=0;i<5;i++)
	printf ("Philosopher %d is thinking\n",i+1);
   for(i=0;i<5;i++)
      pthread_create(&philosopher[i],NULL,(void *)func,(void *)i);

   for(i=0;i<5;i++)
      pthread_join(philosopher[i],NULL);

   for(i=0;i<5;i++)
      pthread_mutex_destroy(&chopstick[i]);

   return 0;
   }
