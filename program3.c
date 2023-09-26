#include <stdio.h>
#include <math.h>
int main()
{
    struct vector
    {
        int x;
        int y;
    };
    struct Max
    {
        int points[2];
        int distance;
    };

    struct Max max;
    max.distance = 0;
    struct vector position[5];
    for (int i = 0; i < 5; i++)
    {
        printf("x%d: ", i + 1);
        scanf("%d", &position[i].x);
        printf("y%d: ", i + 1);
        scanf("%d", &position[i].y);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d: (%d,%d)\n", i + 1, position[i].x, position[i].y);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            // int xDiff = (position[i].x - position[j].x) * (position[i].x - position[j].x);
            // int yDiff = (position[i].y - position[j].y) * (position[i].y - position[j].y);
            int distance = (position[i].x - position[j].x) * (position[i].x - position[j].x) +
                           (position[i].y - position[j].y) * (position[i].y - position[j].y);
            if (distance > max.distance)
            {
                max.distance = distance;
                max.points[0] = i;
                max.points[1] = j;
            }
        }
    }
    // printf("(%d, %d)\n", position[max.points[0]].x, position[max.points[0]].y);
    // printf("(%d, %d)\n", position[max.points[1]].x, position[max.points[1]].y);
    for (int i = 0; i < 2; i++)
    {
        printf("(%d, %d)\n", position[max.points[i]].x, position[max.points[i]].y);
    }
}