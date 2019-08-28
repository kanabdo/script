#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NUMBER 4
#define MAX_STRING 50

char ** get_user_info();

int main (){
    char **info_array = get_user_info();
    if (!info_array){
        printf("ERROR: Unable to allocate info_array!\n");
        return 1;
    }
    else{
        printf("Operating system \t = %s\nComputer name \t\t = %s\nUser name \t\t = %s\nUser profile \t\t = %s\n", info_array[0], info_array[1],  info_array[2], info_array[3]);
    }
    return 0;
}


// This function return an array with the computer user information
// it needs improvement to return the computer name for Mac and Linux.
// I will finish it later
// Goal: get it to work cross platforms
// I should get these values for any system:
// info[0]=Operating system ; info[1]=computerName ; info[0]=userName ; info[0]=userProfile

char ** get_user_info(){
    int i=0;
    char **array = malloc(sizeof(char *) * NUMBER);
    if (!array){
        return NULL;
        }
    for (i=0; i<NUMBER; i++){
        array[i] = malloc(MAX_STRING +1 );
        if (!array[i]){
            free (array);
            return NULL;
            }
        }

    #ifdef _WIN32
        char buffer[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = MAX_COMPUTERNAME_LENGTH + 1 ;
        GetComputerName( buffer, &size ); // Works ONLY on Windows
        strncpy(array[0],"Windows 32-bit", MAX_STRING);
        strncpy(array[1],buffer, MAX_STRING);
        strncpy(array[2], getenv("username"), MAX_STRING);
        strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #elif _WIN64
        char buffer[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = MAX_COMPUTERNAME_LENGTH + 1 ;
        GetComputerName( buffer, &size ); // Works ONLY on Windows
        strncpy(array[0],"Windows 64-bit", MAX_STRING);
        strncpy(array[1],buffer, MAX_STRING);
        strncpy(array[2], getenv("username"), MAX_STRING);
        strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #elif __APPLE__ || __MACH__
        strncpy(array[0],"Mac OSX", MAX_STRING);
        strncpy(array[1],"N/A", MAX_STRING);
        strncpy(array[2], getenv("username"), MAX_STRING);
        strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #elif __linux__
            strncpy(array[0],"Linux", MAX_STRING);
            strncpy(array[1],"N/A", MAX_STRING);
            strncpy(array[2], getenv("username"), MAX_STRING);
            strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #elif __FreeBSD__
            strncpy(array[0],"FreeBSD", MAX_STRING);
            strncpy(array[1],"N/A", MAX_STRING);
            strncpy(array[2], getenv("username"), MAX_STRING);
            strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #elif __unix || __unix__
        strncpy(array[0],"Unix", MAX_STRING);
        strncpy(array[1],"N/A", MAX_STRING);
        strncpy(array[2], getenv("username"), MAX_STRING);
        strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;

    #else
        strncpy(array[0],"Other", MAX_STRING);
        strncpy(array[1],"N/A", MAX_STRING);
        strncpy(array[2], getenv("username"), MAX_STRING);
        strncpy(array[3], getenv("userprofile"), MAX_STRING);
        return array;
    #endif
}
