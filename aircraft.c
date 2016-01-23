#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *takeoffFunc (void *ptr);    
void *landingFunc (void *ptr); 

#define Q1 0
#define Q2 1
#define Q3 2
#define Q4 3
#define Q5 4

#define	APP 0 /* Approach Airport*/
#define	HOV 1 /* Hover over airport until plane receives landing and takeoff information */
#define	PRE 2 /* Prepare for landing*/
#define RID 3 /* Ride down runway */
#define GAT 4 /* Gate begins to open or plane to load passegers */
#define PLA 5 /* Plane begins to load passengers */

#define STA 0 /* Start moving towards gate */
#define OPE 1 /* Open gate for the plane to pass through */
#define MOV 2 /* Moving down runway */
#define TAK 3 /* Takeoff from runway */
#define NAV 4 /* Navigation after takeoff */
#define CRU 5 /* Cruising into the sunset */

int ARRAY_landing [10], ARRAY_lane [10]; 

pthread_mutex_t lock;  

int main(int argc, char *argv[])
{
int question = 0;
  
int num = 0;
int plane_Cont = 0;
int x = 0;
int lane_Cont = 0; 
int ux = 0;
int vx = 0; 
int gx = 1; 
int run_S = 0;  
int rc = 0;
int rx = 0; 
long t; 

while (question != 4)
{	
	switch (question)
	{
	case Q1:
	{
		printf (" How many lanes will be used today? (USE INTEGER) \n"); 
		printf (" **The maximum number of lanes the airport can supports is 5 \n"); 
		scanf ("%ld", &num);
		if ( num <  0  || num > 5  ) question = Q2; 
		else question  = Q3;
		     lane_Cont = num ;} break;
 	
	case Q2:{
		num = 0; 
		printf (" You did not enter a valid integer. \n");
		printf (" Enter a new integer \n");
		scanf ("%ld", &num);  
		if ( num < 0 || num > 5) question = Q2; 
 		else question = Q3;  
		     lane_Cont = num ;
		
	} break;
 
	case Q3:{
		num = 0; 
		printf (" How many planes will be flying to this distination?\n "); 
		printf (" The maximum number of planes the airport can support is 10 \n "); 
		scanf ("%ld", &num); 
		if ( num < 0 || num > 10) question = Q4; 
		else question = Q5;
		     plane_Cont = num;
		
	} break;
 
	case Q4:{
		num = 0; 
		printf ("You did not enter a valid integer.\n");
		printf (" Enter a new integer \n"); 
		scanf ("%ld", &num); 		
		if ( num < 0 || num > 10) question = Q4; 
		else question = Q5 ;
		     plane_Cont = num;
		
	} break;
	}
	run_S = plane_Cont; 
	}
	printf(" You have designated %d Planes and %d Runways.\n\n", plane_Cont ,lane_Cont); 

	for (ux = 0  ; ux != plane_Cont ; ux++ )
	{
		ARRAY_landing [ux] = ux + 1;
  		ARRAY_lane [ux] = gx;
		gx = gx + 1 ;  
		if ( gx > lane_Cont) 
		{
			gx = 1; 
		}
	}
	
	pthread_t threads[run_S];
	
	for(t = 0; t< plane_Cont ; t++)
        {
	rx = pthread_create(&threads[t], NULL, landingFunc, (void *)t);
	sleep(1);
         }
	for(t = 0; t< plane_Cont ; t++)
        {
	rc = pthread_create(&threads[t], NULL, takeoffFunc, (void *)t);
	sleep(1);
         }

	pthread_exit(NULL); 
 
}
/*THIS IS THE BEGINNING OF THE LANDING FUNCTION OF THE FLIGHT*/
/*THIS PORTION OF CODE GOES THROUGH ALL THE STEPS IT TAKE FOR THE PLANES TO LAND*/

void *landingFunc(void *ptr)
{
	int landing = APP; 
	while(landing != 5)
	{
		switch(landing)
		{
		case APP:
			{
			landing = HOV;
			sleep(1);  
			}
			break; 
		pthread_mutex_lock(&lock);/* pthread mutex lock */ 	
		case HOV: 
			{
			long tid; 
			tid = (long)ptr;  
			printf(" Plane %d had been assigned to land on runway %d.\n\n",ARRAY_landing[tid],ARRAY_lane[tid]); 
			landing = PRE;  
			}
			break; 
		case PRE: 
			{
			long tid; 
			tid = (long)ptr; 
			printf(" Plane %d has touch down on runway %d.\n\n",ARRAY_landing[tid],ARRAY_lane[tid]); 
			landing = RID;
			}
			break;  
		case RID:
			{
			landing = GAT;
			sleep(1);  
			}
			break; 
		case GAT: 
			{
			long tid; 
			tid = (long)ptr;  
			printf(" Gate %d has opened for plane %d.\n\n",ARRAY_lane[tid],ARRAY_landing[tid]); 
			landing = PLA;
			pthread_exit(NULL);   
			}
			break; 
			pthread_mutex_unlock(&lock); /* pthread mutex unlock */
		}

	}
}

/* THIS PORTION OF CODE IS THE BEGINNING OF THE TAKEOFF */

void *takeoffFunc(void *ptr) 
{
	int takeoff = STA; /* The initialization of the planes progression through takeoff */
	
	while (takeoff != 5)
	{
		switch(takeoff)
		{
		case STA:
			{
			takeoff = OPE; 
			}
			break;
			
		pthread_mutex_lock(&lock);
		
		case OPE:
			{
			long tid; 
			tid = (long)ptr;
			printf(" Gate %d has opened for plane %d.\n\n ", ARRAY_lane[tid] ,ARRAY_landing[tid]); 
			takeoff = MOV;
			}
			break; 
		case MOV: 
			{
			takeoff = TAK; 
			}
			break; 	
		case TAK:
			{
			long tid; 
			tid = (long)ptr;
			printf(" Plane number %d has taken off from Runway %d.\n\n ", ARRAY_landing[tid] ,ARRAY_lane[tid]);   	
			int x = rand()%50;  
			if (x >= 40 ) printf(" Plane %d was almost in a collision!!!!!! Collision Avoided and flight is on track.\n\n",ARRAY_landing[tid]); 
			pthread_exit(NULL);  		
			takeoff = NAV;  
			}
			break; 
	
		case NAV:
		{
		takeoff = CRU; 
		}	
		break;
	} 	
	pthread_mutex_unlock(&lock);
	}
}
