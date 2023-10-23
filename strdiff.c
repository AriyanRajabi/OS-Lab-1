#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int get_char_size(const char* input){
    int size = 0;
    while(input[size] != '\0'){
        size++;
    }
    return size;
}
int main(int argc,char*argv[]){
   if(argc != 3){
    printf(1,"Invalid numver of arguments!\n");
    exit();
   }
   const char* first = argv[1];
   const char* second = argv[2];
   int first_size = get_char_size(first);
   int second_size = get_char_size(second);
   int result_size = second_size > first_size?second_size:first_size;
   char result[result_size+1];
   for(int i = 0;i<result_size;i++){
    if(i+1 > first_size){
        //out of first
            result[i] = '1';
    }else if(i+1 >second_size){
        //out of second
            result[i] = '0';
    }else{
    result[i] = first[i] >= second[i]?'0':'1';
    }
   }
   result[result_size] = '\0';
   printf(1,result);

    int file_id = open("strdiff_result.txt",O_CREATE | O_WRONLY);
    if(file_id == -1){
        printf(1,"error opening the file\n");
        exit();
    }
    int written = write(file_id,result,result_size * sizeof(result[0]));
    if(written == -1){
        printf(1,"error writing to the file\n");
    }
    close(file_id);
    exit();
}