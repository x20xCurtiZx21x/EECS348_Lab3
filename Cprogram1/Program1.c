/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: c950c102
 */
#include <stdio.h>

#include <math.h>

char* monthName;

int sortedMonth[12];

float sales[12];

float temp[12];

int num;

int maxMonth;

int minMonth;

float max;

float min;

float sum;

float calcAverage(int numStart, int numEnd){

	for (int i=numStart; i <= numEnd; i++){

		sum = sum + sales[i];

	}

	sum = sum / 12;

	return sum;

}

char* declareMonth(int num){

	if (num == 0){
		return "January";
	} else if (num == 1){
		return "February";
	} else if (num == 2){
		return "March";
	} else if (num == 3){
		return "April";
	} else if (num == 4){
		return "May";
	} else if (num == 5){
		return "June";
	} else if (num == 6){
		return "July";
	} else if (num == 7){
		return "August";
	} else if (num == 8){
		return "September";
	} else if (num == 9){
		return "October";
	} else if (num == 10){
		return "November";
	} else{
		return "December";
	}
}

float maxValue(){

	num = 1;

	maxMonth = 0;

	max = sales[0];

	while (num<=11){

		if (max < sales[num]){

			max = sales[num];

			maxMonth = num;
		}

		num++;
	}

	return max;
}

float minValue(){

	num = 1;

	minMonth = num;

	min = sales[0];

	while (num<=11){

		if (min > sales[num]){

			min = sales[num];

			minMonth = num;
		}

		num++;
	}

	return min;
}

int sortMonths(){



	int num2;

	num = 0;

	while (num <= 11){

		num2 = 1;

		maxMonth = 0;

		max = temp[0];

		while (num2<=11){

			if (max < temp[num2]){

				max = temp[num2];

				maxMonth = num2;
			}

			num2++;

		}

		temp[maxMonth] = -1;

		sortedMonth[num] = maxMonth;

		num++;

	}

	return 0;
}

int main(){

printf("%s", "Enter your sales for each month (spaced out and in order):\n");

scanf("%f %f %f %f %f %f %f %f %f %f %f %f", &sales[0], &sales[1], &sales[2], &sales[3], &sales[4], &sales[5], &sales[6], &sales[7], &sales[8], &sales[9], &sales[10], &sales[11]);

for (int i = 0; i <= 11; i++){

	temp[i] = sales[i];

}
printf("%s", "\nMonthly Sales report for 2022\n\n");

printf("%s","Month   \tSales\n\n");

num = 0;

while (num<=11){

	monthName = declareMonth(num);

	printf("%s     \t$%f\n", monthName, sales[num]);

	num++;

}

printf("%f \n", calcAverage(0, 11));

printf("%f \n", maxValue());

printf("%f \n", minValue());

sortMonths();

for(int i = 0; i <= 11; i++){

	printf("%d \n", sortedMonth[i]);
}

return 0;

}
