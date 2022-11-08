#include <u.h>
#include <libc.h>
#include <stdio.h>

// perry page: 307-308

float gradeAve(float test1, float test2, float test3);

main()
{
	float grade1, grade2, grade3;
	float average;
	print("What was the grade on the first test? ");
	scanf(" %f", &grade1);
	print("What was the grade on the second test? ");
	scanf(" %f", &grade2);
	print("What was the grade on the third test? ");
	scanf(" %f", &grade3);
	
	average = gradeAve(grade1, grade2, grade3);
	print("\nWith those three test scores, the average is %.2f\n ", average);
	return 0;
}

float 
gradeAve(float test1, float test2, float test3)
{
	float localAverage;
	localAverage = (test1+test2+test3)/3;
	return (localAverage);
}
