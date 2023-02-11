/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *  Last revised: Feb 11, 2023
 *      Author: c950c102
 */

#include <stdio.h>

int userChoice = 2;

int safety = 2;

int safetyCount;

int FG = 3;

int FGCount;

int TD0 = 6;

int TD0Count;

int TD1 = 7;

int TD1Count;

int TD2 = 8;

int TD2Count;

int findCombos(int score){

	safetyCount = 0;

	while (safetyCount*safety <= score){

		if (safetyCount * safety == score){

			printf("%d Safety, 0 FG, 0 TD, 0 TD + FG, 0 TD + 2pt\n", safetyCount);
		}

		FGCount = 0;

		while (((safetyCount * safety) + (FGCount * FG)) <= score){

			if (((safetyCount * safety) + (FGCount * FG) == score)&&(FGCount != 0)) {

				printf("%d Safety, %d FG, 0 TD, 0 TD + FG, 0 TD + 2pt\n", safetyCount, FGCount);

			}

			TD0Count = 0;

			while (((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0)) <= score){

				if ((((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0)) == score)&&(TD0Count != 0)){

					printf("%d Safety, %d FG, %d TD, 0 TD + FG, 0 TD + 2pt\n", safetyCount, FGCount, TD0Count);

				}

				TD1Count = 0;

				while (((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0)+(TD1Count * TD1)) <= score){

					if ((((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0)+(TD1Count * TD1)) == score)&&(TD1Count != 0)){

						printf("%d Safety, %d FG, %d TD, %d TD + FG, 0 TD + 2pt\n", safetyCount, FGCount, TD0Count, TD1Count);

					}

					TD2Count = 0;

					while (((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0) + (TD1Count * TD1) + (TD2Count * TD2)) <= score){

						if ((((safetyCount * safety) + (FGCount * FG) + (TD0Count * TD0) + (TD1Count * TD1) + (TD2Count * TD2)) == score)&&(TD2Count != 0)){

							printf("%d Safety, %d FG, %d TD, %d TD + FG, %d TD + 2pt\n", safetyCount, FGCount, TD0Count, TD1Count, TD2Count);

						}

						TD2Count++;
					}

					TD1Count++;
				}

				TD0Count++;
			}

			FGCount++;
		}

		safetyCount++;
	}
	return 0;
}

int main() {

	while (userChoice > 1){

		printf("%s","Enter an NFL Score(Input 1 or 0 to STOP):\n");

		scanf("%d", &userChoice);

		if (userChoice <= 1){
			break;
		}

		printf("%s","\nCombinations Found:\n");

		findCombos(userChoice);

		printf("%s","\n");
	}

	return 0;
}
