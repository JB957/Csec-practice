#ifndef CIRCLE_H
#define CIRCLE_H

float area(float radius);
float perimeter(float radius);
#define PI 3.1454

float area(float radius){
return PI * radius*radius;
}

float perimeter(float radius){
return 2 * PI * radius;
}

#endif