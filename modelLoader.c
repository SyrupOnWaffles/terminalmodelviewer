#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadOBJ(char *filePath, float model[1000][9]){
  FILE *file;
  float mesh[1000][9];
  float verticies[1000][3];
  char line[500];
  int vCount = 0;
  int fCount = 0;
  file = fopen(filePath, "r");
  if(!file){
    printf("\n Unable to open file" );
  }
  while (fgets(line, sizeof(line), file)) {
    //put verticies in array
    if(line[0] == 'v' && line[1] == ' '){
      char *array[10];
      int i = 0;

      array[i] = strtok(line, " ");

      while(array[i] != NULL)
       array[++i] = strtok(NULL, " ");
      verticies[vCount][0] =  atof(array[1]);
      verticies[vCount][1] =  atof(array[2]);
      verticies[vCount][2] =  atof(array[3]);
      //printf("%f\n",verticies[vCount][1]);
      vCount += 1;
    }
    if(line[0] == 'f'){
      char *array[10];
      int i = 0;

      array[i] = strtok(line, " ");

      while(array[i] != NULL)
       array[++i] = strtok(NULL, " ");

      for(int j = 0; j < 3; j++){
      mesh[fCount][0+j] =  verticies[atoi(array[1])-1][j];
      mesh[fCount][3+j] =  verticies[atoi(array[2])-1][j+3];
      mesh[fCount][6+j] =  verticies[atoi(array[3])-1][j+6];
      printf("%f\n",mesh[fCount][0]);
    }
      fCount += 1;
    //put faces in array
//     if(line[0] == 'f'){
//       char *array[10];
//       int i = 0;
//
//       array[i] = strtok(line, " ");
//
//       while(array[i] != NULL) array[++i] = strtok(NULL, " ");
//
//         mesh[fCount][0] = verticies[atoi(array[1])][0];
//         mesh[fCount][1] = verticies[atoi(array[2])][1];
//         mesh[fCount][2] = verticies[atoi(array[3])][2];
//       //fancy vertex to face
//
//
// //       for(int j = 1; j < 4; j++){
// //         char *tri[10];
// //         int i = 0;
// //
// //         tri[i] = strtok(array[j], "/");
// //
// //        while(tri[i] != NULL)
// //          tri[++i] = strtok(NULL, "/");
// //
// //       //fancy vertex to face
// //
// //       }
//       fCount += 1;
//
//     }

  }
  model = mesh;
  fclose(file);
}}
int main(){
float mesh[1000][9];
loadOBJ("/home/syrup/Desktop/Programming/c/asciirenderer/models/cube.obj",mesh);
printf("%f", mesh[0][0]);
return 1;
}
