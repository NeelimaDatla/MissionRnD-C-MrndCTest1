/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int days(char[], char[]);
int between_days(struct node *date1head, struct node *date2head){
	struct node *d1 = date1head;
	struct node *d2 = date2head;
	char str1[8];
	char str2[8];
	int i = 0;
	if (date1head == NULL || date2head == NULL)
		return -1;
	while (d1->next!= NULL){
		str1[i] = (d1->data + '0');
		i++;
		d1 = d1->next;
	}
	i = 0;
	while (d2->next != NULL){
		str2[i] = (d2->data + '0');
		i++;
		d2 = d2->next;
	}
	int d = days(str1, str2);
	return d - 1;
}

int days(char dob1[8], char dob2[8]) {
	int year1 = ((dob1[4] - 48) * 1000) + ((dob1[5] - 48) * 100) + ((dob1[6] - 48) * 10) + (dob1[7] - 48);
	int year2 = ((dob2[4] - 48) * 1000) + ((dob2[5] - 48) * 100) + ((dob2[6] - 48) * 10) + (dob2[7] - 48);
	int month1 = ((dob1[2] - 48) * 10) + (dob1[3] - 48);
	int month2 = ((dob2[2] - 48) * 10) + (dob2[3] - 48);
	int day1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	int day2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	int k = abs(year1 - year2);
	int days = k * 365;
	for (int j = month1; j < month2; j++){
		if (j == 2)
			days = days + 28;
		else if (j == 8)
			days = days + 30;
		else if (j <= 7){
			if (j % 2 == 0)
				days = days + 30;
			else
				days = days + 31;
		}
		else{
			if (j % 2 == 0)
				days = days + 31;
			else
				days = days + 30;
		}
	}
	int k3 = abs(day1 - day2);
	days = days + k3;
	return days;
}