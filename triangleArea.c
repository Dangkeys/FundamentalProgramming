#include <stdio.h>
#include <math.h>

int x1,y1,x2,y2,x3,y3;
 
float area(){
    float side1,side2,side3,area,sum;
    side1 =  sqrt((pow((x1-x2),2))+pow((y1-y2),2) );
    side2 =  sqrt((pow((x1-x3),2))+pow((y1-y3),2) );
    side3 =  sqrt((pow((x2-x3),2))+pow((y2-y3),2) );
    sum = (side1+side2+side3)/2;
    area = sqrt(sum*(sum-side1)*(sum-side2)*(sum-side3));
    return area;
}

int main(){
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("%.2f",area(x1,y1,x2,y2,x3,y3));

}