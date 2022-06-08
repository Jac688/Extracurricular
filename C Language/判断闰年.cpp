//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/7/30 
//Task no: Summer4 
//Reqirement:≈–∂œ»ÚƒÍ
#include<stdio.h>
#include<stdbool.h> 

struct date {
	int year;
	int month;
	int day;
};

bool isleap(struct date d);
int numberOfDay(struct date d);

int main(int argc, char const *argv[]){
	struct date today, tomorrow;
	printf("Please enter today's date: ");
	scanf("%i %i %i", &today.day, &today.month, &today.year);
	if (today.day != numberOfDay(today)){
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if(today.month == 12){
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else{
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	return 0;
}
	
int numberOfDay(struct date d){
		int days;
		const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30,}; 
		if (d.month == 2 && isleap(d)){
			days = daysPerMonth[d.month - 1];
		}
		else
			days = daysPerMonth[d.month - 1];
		return days;
	}

	
bool isleap(struct date d){
	 bool leap = false;
	 if((d.year %4 == 0 && d.year %100 != 0) || d. year %400 == 0){
	 	leap = true;
	 }
	 return leap;
}

















