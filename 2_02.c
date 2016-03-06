#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int days [12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int dd=0, mm=0, yyyy=0, hh=0, mmin=0, allsec=0, tempdd=0;
	int vis=0, answ=0, i=0;
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	
	printf("Enter your age (dd.mm.yyyy hh:min): ");
	scanf("%d.%d.%d %d:%d",&dd, &mm, &yyyy, &hh, &mmin);

	for(i=0; i<mm-1; i++)
	{
		tempdd+=days[i];       //cколко дней прошло от начала года рождени€ до начала мес€ца рождени€
	}
	seconds = time(NULL);

	printf("Local time: %s", asctime(timeinfo));

	vis = (timeinfo->tm_year+1900-yyyy)/4;
	if(timeinfo->tm_year%4 == 0 && timeinfo->tm_mon>=2 && yyyy%4==0 && mm<3)
		vis++;
	else if(timeinfo->tm_year%4 == 0 && timeinfo->tm_mon<2 && yyyy%4==0 && mm>=3)
		vis--;



	allsec = (timeinfo->tm_year+1900-yyyy)*365*(24*60*60)
				+ timeinfo->tm_yday*(24*60*60) 
				+ timeinfo->tm_hour*60*60 
				+ timeinfo->tm_min*60 + timeinfo->tm_sec
				- tempdd*24*60*60 - (dd-1)*24*60*60 - hh*60*60 
				- mmin*60 + vis*24*60*60;

	printf("ALL SECONDS: %d", allsec);

	system("pause");
	return 0;
}
