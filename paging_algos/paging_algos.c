#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define REF_SIZE 20

void print_frames(char frames[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%c, ", frames[i]);
	printf("\n");
}

int contains(const char frames[], int nframes, char target)
{
	for(int i = 0; i < nframes; i++)
		if(frames[i] == target) 
			return i;
	return -1;
}

int lru(char *ref, int nframes)
{
	
	printf("LRU results:\n");
	int size = 0;	//number of elements in frames
	int faults = 0;
	char frames[nframes];
	//print_frames(ref, REF_SIZE);
	char *p = ref;
	for(int i = 0; i < REF_SIZE; i++)
	{
		int index = contains(frames, nframes, *p);
		if(size == 0)
		{
			frames[0] = *p;
			size++;
			faults++;
		}
		//if contains element referenced by p
		else if(index >= 0)
		{
			for(int j = index; j > 0; j--)
				frames[j] = frames[j-1];
			frames[0] = *p;
		}
		//if does NOT contain element referenced by p
		else
		{
			//if frames is not full
			if(size < nframes)
			{
				for(int j = size; j > 0; j--)
					frames[j] = frames[j-1];
				frames[0] = *p;
				size++;
			}
			//if frames is full
			else
			{
				for(int j = size - 1; j > 0; j--)
					frames[j] = frames[j-1];
				frames[0] = *p;
			}
			faults++;
		}
		p++;
		print_frames(frames, size);
	}
	printf("FAULTS: %d\n\n", faults);
	return faults;
}

int optimal(char *ref, int nframes)
{
	
	printf("Optimal results:\n");
	int size = 0, faults = 0;
	char frames[nframes];
	char *p = ref;
	for(int i = 0; i < REF_SIZE; i++)
	{
		if(size < nframes)
		{
			if(contains(frames, nframes, *p) == -1)
			{
				frames[size++] = *p;
				faults++;
			}
		}
		else
		{
			bool replaced = false;
			int furthest = -1, temp = -1;
			if(contains(frames, nframes, *p) == -1)
			{
				for(int j = 0; j < nframes; j++)
				{
					temp = contains(p, REF_SIZE - size, frames[j]);
					if(temp == -1)
					{ 
						frames[j] = *p;
						replaced = true;
						faults++;
						break;
					}	
					if(temp > furthest) furthest = temp;
				}
				if(!replaced)
				{
					int index = contains(frames, nframes, p[furthest]);
					frames[index] = *p;
					faults++;
				}
			}
		}
		p++;
		print_frames(frames, size);
	}
	printf("FAULTS: %d\n\n", faults);
	return faults;
}

int fifo(char *ref, int nframes)
{
	printf("FIFO results:\n");
	int size = 0, faults = 0;
	char frames[nframes];
	char *p = ref;
	for(int i = 0; i < REF_SIZE; i++)
	{
		if(size < nframes)
		{
			if(contains(frames, nframes, *p) == -1)
			{
				frames[size++] = *p;
				faults++;
			}
		}
		else
		{
			if(contains(frames, nframes, *p) == -1)
			{
				for(int j = size - 1; j > 0; j--)
					frames[j] = frames[j-1];
				frames[0] = *p;
				faults++;
			}
		}
		p++;
		print_frames(frames, size);
	}
	printf("FAULTS: %d\n", faults);
}


char *gen_ref(int size)
{
	char *str = malloc(sizeof(char) * (size + 1));
	const char digits[] = "12345";
	srand(time(0));
	for(int i = 0; i < size; i++)
		str[i] = digits[rand() % 5];

	return str;
}

void main()
{	
	int nframes, faults_lru, faults_optimal;
	char *ref = gen_ref(REF_SIZE);
	printf("REFERENCE STRING: ");
	print_frames(ref, REF_SIZE);
	printf("enter number of frames: ");
	scanf("%d", &nframes);
	printf("\n");
	faults_lru = lru(ref, nframes);
	faults_optimal = optimal(ref, nframes);
	if(faults_lru == faults_optimal)
	{
		printf("\ntie detected - running tiebreaker\n\n");
		fifo(ref, nframes);
	}
}
