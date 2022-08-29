# PolygonsProj-4
A program that stores and manipulates a list of at-most n polygons where n is given as a command-line argument when running the program.

				
Each polygon must be stored in a structure like this:
          
    typedef struct {
        int numberOfVertices;
        Direction shiftDirection;
        Vertex* vertexList;
     }Polygon;
           
           
Where Direction and Vertex are defined like this:
          
    typedef enum { 
        NONE = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 4,
        RIGHT = 8
    }Direction;
    
    typedef struct {
        int x, y; 
    }Vertex;


# I have implemented...
make	: makefile with different commands to run<br>
header	: header file to assist with cleanliness<br>
add 	: add polygon with list of vertices<br>
summary : returns the number of vertices and centroid for each polygon<br>
shift	: shifts the polygons location<br>
turn 	: sets the direction of the polygon<br>
quit 	: terminates the program<br>
