#include "polygons.h"

int main(int argc, char** argv)//./main 12
{
    int max_num_of_polygons;
    sscanf(argv[1], "%d", &max_num_of_polygons);

    Polygon* list = (Polygon*) malloc(max_num_of_polygons * sizeof(Polygon));/* cant figure out how many polygons im actually allowed to make; at 
                                                                                max_num_of_polygons set to 1 i'm able to make 2 */
    char command[1000];
    char tokentemp[20];
    char firsttoken[20];
    char rest[1000];
    char *token [3];
    int polygonindex = 0;
    Vertex tempVertexList[max_num_of_polygons];
    
    //first polygon is at list[0]
    //second one is at list[1]
    
    //strcpy(command, "turn 3 right-up\n");
    //strcpy(command, "shift 3 20\n");
    //strcpy(command, "add 3 4 1 2 3 4 5 6 7 8 9 1\n");
    //strcpy(command, "summary\n");
    //strcpy(command, "quit\n");
    
    while (1) {
        printf("Enter a command...\n");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s %[^\n]\n", firsttoken, rest);
        
        if(!strcmp(firsttoken, "quit")){
            printf("Quitting...\n");
            //printf("Quitting...✌️\n");
            break;
        }
        if(!strcmp(firsttoken, "summary")){
            summaryHandle(polygonindex, list);
        }
        if(!strcmp(firsttoken, "shift")) {
            shiftHandle(rest, list);
        }
        if(!strcmp(firsttoken, "turn")){
            turnHandle(rest, list);
        }
        if(!strcmp(firsttoken, "add")){
            int n = strlen(rest), x, y;
            rest[n] = '\n';
            rest[n+1] = '0';
            int rv = 0;
            int counter = 0;
            while((rv = sscanf(rest, "%d %d %[^\n]\n", &x, &y, rest)) >= 2){
                //printf("coordinate of the first point is (%d, %d), and the rest is %s, rv = %d\n", x, y, rest, rv);
                tempVertexList[counter].x = x;
                tempVertexList[counter++].y = y;
                if(rv == 2)
                    break;
            }
            list[polygonindex].numberOfVertices = counter;
            list[polygonindex].shiftDirection = NONE;
            list[polygonindex].vertexList = (Vertex*) malloc(counter * sizeof(Vertex));
            for(int i = 0; i < counter;i++)
                list[polygonindex].vertexList[i].x = tempVertexList[i].x,
                list[polygonindex].vertexList[i].y = tempVertexList[i].y;
                polygonindex++;
        }
        continue; //return 0;
    }
}

