#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

const char* getOsName();

// THIS NEED IMPROVEMENT TO WORK CROSS PLATFORMS
// WILL FINISH LATER

int main(){
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1 ;
    GetComputerName( buffer, &size ); // Works ONLY on Windows

    printf("Operating system \t= %s\n", getOsName());
    printf( "Computer name \t\t= %s\n", buffer );
    printf("User name \t\t= %s\n",getenv("username"));
    printf("User profile \t\t= %s\n",getenv("userprofile"));

    return 0;
}

/*
    I should change this function to return an array info[4] such that:
    info[0]=osName ; info[1]=computerName ; info[0]=userName ; info[0]=userProfile
*/
const char* getOsName(){

    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif

}

