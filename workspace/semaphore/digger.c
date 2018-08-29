#include <taskLib.h>
#include <stdio.h>
#include <kernelLib.h>
#include <semLib.h>

#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <semLib.h>
#include <fcntl.h>

 
#define WORK_TIME 100
#define BREAK_TIME 200
	SEM_ID semShovels;
	SEM_ID semSoilHeap;
	SEM_ID	lock;
	
	struct company {
	    char name[20];
	    int work_done;
	};

	struct company_registry {
	    struct company companies[50];
	};

	struct company_registry *ptr;
	int work_done;
	
	char workerName[20] = "tWorker\n";
	int lowerDiggers = -1;
	int upperDiggers = -1;
	int diggers =-1;
	char c = '\0';
	int i; 
	int lowerIDs[100];
	int upperIDs[100];
	
	
void digger_in_hole(int n)
{


  while (1) {
    semTake(semShovels, WAIT_FOREVER);
    printf("lower digger %d: working\n", n);
    taskDelay(WORK_TIME);
    semGive(semSoilHeap);
    semGive(semShovels);
    printf("lower digger %d: taking break\n", n);
    taskDelay(BREAK_TIME);
  }
}
;

void digger_on_top(int n) {
   	
	
	while (1) {
        
    	semTake(semSoilHeap, WAIT_FOREVER);
        printf("upper digger %d: waiting for shovel\n", n);
        semTake(semShovels, WAIT_FOREVER);
        printf("upper digger %d: taking shovel\n", n);
        taskDelay(WORK_TIME);
        printf("upper digger %d: returning shovel\n", n);
        /*semTake(lock, WAIT_FOREVER);
        ptr->companies[0].work_done++;
        semGive(lock);*/
        semGive(semShovels);
        printf("upper digger %d: taking break\n", n);
        taskDelay(BREAK_TIME);
    }
}

void init_shm(void)
{
    int fd,s=1;

    /* Lock to protect manipulations with shared memory - accessible from multiple processes */
    lock = semOpen("/complock", SEM_TYPE_MUTEX, SEM_FULL, SEM_Q_FIFO, OM_CREATE, NULL);
    /* use semTake() and semGive() to protect the relevant code below */
    semTake(lock, WAIT_FOREVER);
    //fd = shm_open("/company", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR);
    /* or consider using O_EXCL flag to find whether the memory
     * needs to be initialized (see memset below) or not */
    fd = shm_open("/company", O_RDWR | O_CREAT | O_EXCL, S_IRUSR|S_IWUSR);
    //fd = shm_open("/company", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR);
    /* set the size of shared memory block */
    if (ftruncate (fd, sizeof(struct company_registry)) == -1) {
        perror("ftruncate");
        exit (1);
    }

    /* Map shared memory object in the process address space */
    ptr = (struct company_registry *)mmap(0, sizeof(struct company_registry),
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED, fd, 0);

    if (ptr == (struct company_registry *)MAP_FAILED)
        exit (1);

    /* close the file descriptor; the mapping is not impacted by this */
    close (fd);

    

    /* the fist company should zero the memory this way: */
    memset(ptr, 0, sizeof(struct company_registry));

    /* ... register this company to the memory ... */
    semGive(lock);
    printf("Init shm done.\n");
}





int main(int argc,const char* argv[])
{
	
	
	
	init_shm();
	//*((int *)0) = 10;
    semShovels = semCCreate(SEM_Q_FIFO, 3);
    semSoilHeap = semCCreate(SEM_Q_FIFO, 0);
    lowerDiggers += 1;
    upperDiggers += 1;
    diggers +=1;
    lowerIDs[0] = taskSpawn("lWorker0", 210, 0, 4096, (FUNCPTR) digger_in_hole, lowerDiggers, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    diggers +=1;
    upperIDs[0] = taskSpawn("uWorker0", 210, 0, 4096, (FUNCPTR) digger_on_top, upperDiggers, 0, 0, 0, 0, 0, 0, 0, 0, 0);
 
    while (1) {
        c = getchar();
        switch (c) {
            case('i'):
            {
                printf("LowWorker in\n");
                diggers += 1;
                lowerDiggers += 1;
                sprintf(workerName, "lWorker%d", lowerDiggers);
                lowerIDs[lowerDiggers] = taskSpawn(workerName, 210, 0, 4096, (FUNCPTR) digger_in_hole, lowerDiggers, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                printf("Working workers %d  low:%d up:%d\n", diggers + 1, lowerDiggers + 1, upperDiggers + 1);
                break;
            }
            
                case('I'):
                {
                    printf("UpWorker in\n");
                    diggers += 1;
                    upperDiggers += 1;
                    
                    sprintf(workerName, "uWorker%d", upperDiggers);
                    upperIDs[upperDiggers] = taskSpawn(workerName, 210, 0, 4096, (FUNCPTR) digger_on_top, upperDiggers, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                    printf("Working workers %d  low:%d up:%d\n", diggers + 1, lowerDiggers + 1, upperDiggers + 1);
                    break;
                }
                case('o'):
                {
                    if (lowerDiggers >= 0) 
                    {
                    	printf("LowWorker out\n");
                    	taskDelete(lowerIDs[lowerDiggers]);
                    	diggers--;
                    	lowerDiggers--;
                    	printf("Working workers %d  low:%d up:%d\n", diggers + 1, lowerDiggers + 1, upperDiggers + 1);
                    } 
                    else {
                         printf("No worker left\n");
                    	}
                                break;
                            }
                  case('O'):
                   {
                      if (upperDiggers >= 0) 
                      {
                    	  printf("UpWorker out\n");
                    	  taskDelete(upperIDs[upperDiggers]);
                    	  diggers--;
                    	  upperDiggers--;
                    	  printf("Working workers %d  low:%d up:%d\n", diggers + 1, lowerDiggers + 1, upperDiggers + 1);
                      } 
                      else {
                                    printf("No worker left\n");
                      	  	  }
                                break;
                            }
            
                  case('E'):
                        	 {
                                  if (upperDiggers >= 0) {
                                      for (i = upperDiggers; i >= 0; --i) {
                                          taskDelete(upperIDs[i]);
                                          diggers--;
                                      }
                                      upperDiggers = -1;
                                  }
                                  if (lowerDiggers >= 0) {
                                      for (i = lowerDiggers; i >= 0; --i) {
                                          taskDelete(lowerIDs[i]);
                                          diggers--;
                                      }
                                      lowerDiggers = -1;
                                  }
                                  printf("Working workers:%d  low:%d up:%d\n", diggers + 1, lowerDiggers + 1, upperDiggers + 1);
                                  printf("Terminating...\n");
                                  taskDelay(250);
                                  printf("Done\n");
                                  return (0);
                              }
                              case('\n'):
                              {
                                  break;
                              }
                  
                  default:
                       {
                           printf("Wrong input!\n");
                           break;
                       }
        }
    }
}
