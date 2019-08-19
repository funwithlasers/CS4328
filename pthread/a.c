#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define TIMES 10
#define CAPACITY 3
#define ITEMSIZE 20
#define MAX_STUDENTS 50

struct Buffer
{
  int item[ITEMSIZE];
  int size;
};


struct Student
{
  char thread_id;
  int amount;
};


void *producer();
void *consumer();

pthread_mutex_t mutex;
pthread_cond_t  full_cond;
pthread_cond_t  empty_cond;
struct Buffer buffer;
struct Student students[MAX_STUDENTS];
int fund = 4000;
int numstud = 0;

void *student_thread(char id)
{
	while(fund > 0)
	{
		students[numstud].thread_id = id;
		students[numstud].amount = (int) ceil((double)fund/4);
		usleep(500);
		fund -= students[numstud].amount;
		numstud++;
	}
}

void print_results()
{
	struct Student *p = students;
	for(int i = 0; i < numstud; i++)
	{
		printf("%d. thread %c - $%d\n", i, p->thread_id, p->amount);
		p++;
	} 
}

int get_total()
{
	int total = 0;
	struct Student *p = students;
	for(int i = 0; i < MAX_STUDENTS; i++)
	{
		total += p->amount;
		p++;
	} 
	return total;
}

int
main()
{
  pthread_t tid;
  pthread_t threads[3];

  pthread_setconcurrency(2);
  pthread_create(&tid, NULL, (void *(*)(void *))student_thread, 'A' );
  threads[0] = tid;
  pthread_create(&tid, NULL, (void *(*)(void *))student_thread, 'B' );
  threads[1] = tid;
  pthread_create(&tid, NULL, (void *(*)(void *))student_thread, 'C' );
  threads[2] = tid;
  
  //print_results();
  //pthread_exit(0);
  
  for(int i = 0; i < 3; i++)
   	pthread_join(threads[i], NULL);

  print_results();
  printf("TOTAL = $%d\n\n", get_total());

}
