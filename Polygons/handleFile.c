#include "polygons.h"

void summaryHandle(int polygonindex, Polygon *list) {
    float centroX, centroY, sumX, sumY;
    //printf("There is %d polygon(s)\n", polygonindex);     
    //to calculate centroid
    for (int i = 0; i < polygonindex; ++i) {
        sumX = 0;
        sumY = 0;
        for (int j = 0; j < list[i].numberOfVertices; ++j) {
            sumX+=(list[i].vertexList[j].x);
            sumY+=(list[i].vertexList[j].y);
        }
        //printf("Σx: %d Σy: %d tempVert: %d 🥴🤣🦶👀\n", sumX, sumY, tempVert);
        centroX = sumX/list[i].numberOfVertices;
        centroY = sumY/list[i].numberOfVertices;
        printf("Polygon #%d has %d vertices. It's centroid is at (%0.1f,%0.1f)\n", 
            i + 1, list[i].numberOfVertices, centroX, centroY);
    }
}

void turnHandle(char *cmd, Polygon *list){
	char direct[20];
	int polyN;
	Direction givenDirection = 0;
	sscanf(cmd, "%d %[^\n]\n", &polyN, direct);

    if(!strcmp(direct, "right"))
        givenDirection |= RIGHT;
    if(!strcmp(direct, "left"))
        givenDirection |= LEFT;
    if(!strcmp(direct, "up"))
        givenDirection |= UP;
    if(!strcmp(direct, "down"))
        givenDirection |= DOWN;
    if(!strcmp(direct, "up-right")||!strcmp(direct, "right-up"))
        givenDirection |= RIGHT_UP;
    if(!strcmp(direct, "right-down")||!strcmp(direct, "down-right"))
        givenDirection |= RIGHT_DOWN;
    if(!strcmp(direct, "up-left")||!strcmp(direct, "left-up"))
        givenDirection |= LEFT_UP;
    if(!strcmp(direct, "left-down")||!strcmp(direct, "down-left"))
        givenDirection |= LEFT_DOWN;
    
    list[polyN-1].shiftDirection = givenDirection;
}

void shiftHandle(char *cmd, Polygon *list){
	int polyN, tShift;
	sscanf(cmd, "%d %d\n", &polyN, &tShift);

    if(list[polyN-1].shiftDirection & RIGHT)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) 
            list[polyN-1].vertexList[i].x+=tShift;
    if(list[polyN-1].shiftDirection & LEFT)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) 
            list[polyN-1].vertexList[i].x-=tShift;
    if(list[polyN-1].shiftDirection & UP)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) 
            list[polyN-1].vertexList[i].y+=tShift;
    if(list[polyN-1].shiftDirection & DOWN)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) 
            list[polyN-1].vertexList[i].y-=tShift;
    if(list[polyN-1].shiftDirection & RIGHT_UP)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) {
            list[polyN-1].vertexList[i].y+=tShift;
            list[polyN-1].vertexList[i].x+=tShift;
        }
    if(list[polyN-1].shiftDirection & RIGHT_DOWN)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) {
            list[polyN-1].vertexList[i].y-=tShift;
            list[polyN-1].vertexList[i].x+=tShift;
        }
    if(list[polyN-1].shiftDirection & LEFT_UP)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) {
            list[polyN-1].vertexList[i].y+=tShift;
            list[polyN-1].vertexList[i].x-=tShift;
        }
    if(list[polyN-1].shiftDirection & LEFT_DOWN)
        for (int i = 0; i < list[polyN-1].numberOfVertices; i++) {
            list[polyN-1].vertexList[i].y-=tShift;
            list[polyN-1].vertexList[i].x-=tShift;
        }

    //printf("Polygon #%d has shifted\n", polyN);
}