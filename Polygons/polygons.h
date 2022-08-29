#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef enum {
    NONE =0,
    UP =1,
    DOWN =2,
    LEFT =4,
    RIGHT =8,
    LEFT_UP =16,
    LEFT_DOWN =32,
    RIGHT_UP =64,
    RIGHT_DOWN =128
}Direction;

typedef struct {
    int x,y;
}Vertex;

typedef struct {
    int numberOfVertices;
    Direction shiftDirection;
    Vertex* vertexList;
}Polygon;

void summaryHandle(int polygonindex, Polygon *list);
void shiftHandle(char *cmd, Polygon *list);
void turnHandle(char *cmd, Polygon *list);
