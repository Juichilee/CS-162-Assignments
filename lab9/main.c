#include <stdio.h>
#include <stdlib.h>

int main(void){
int i = 0, j = 0;
int length, width;

printf("Enter Length of Array\n");
scanf("%d", &length);
printf("Enter Width of Array\n");
scanf("%d", &width);

//Make Array
int **array = malloc(sizeof(int*) * length);
for(i = 0; i < length; i++){
	array[i] = malloc(sizeof(int) * width);
}	

//Fill Array
for(i = 0; i < length; i++){
	for(j = 0; j < width; j++){
		array[i][j] = rand()%50 + 1;
	}	
}	

//Print Array
for(i = 0; i < length; i++){
	for(j = 0; j < width; j++){
		printf("|%d", array[i][j]);
	}
	printf("\n");	
}	

//Add value
int add;
printf("Enter value to add\n");
scanf("%d", &add);
for(i = 0; i < length; i++){
	for(j = 0; j < width; j++){
		array[i][j] += add;
		printf("|%d", array[i][j]);
	}	
	printf("\n");
}	

//Delete array
for(i = 0; i < length; i++){
	free(array[i]);
}
free(array);

return 0;
}
