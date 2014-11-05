/*
 ** utils.h
 ** Author: Samuel Jarque Abizanda
 ** Date: 04/11/2014
 */
#ifndef _UTILS_H_
#define _UTILS_H_

#ifdef _WIN32
#include <Windows.h>
#endif

#include <cstdarg>
#include <cstdio>

#define INIT_ZERO(d, t) memset(&d, 0, sizeof(t))    // Memset to initialize values to Zeros
#define MAX_DBG_SIZE 4096                           // Buffer size for printing

void dbg(const char *fmt, ...) {
    // Function to print messages in the console

    va_list args;
    va_start(args, fmt);

    char buf[MAX_DBG_SIZE];
    int n = vsnprintf_s(buf, sizeof(buf), fmt, args);

    // Confirm the msg fits in the given buffer
    if (n < 0){
        buf[sizeof(buf)-1] = 0x00;
    }

    //Redirect to windows debug console
#ifdef _WIN32
    // In windows print the console output
    wchar_t* wString = new wchar_t[MAX_DBG_SIZE];
    MultiByteToWideChar(CP_ACP, 0, buf, -1, wString, MAX_DBG_SIZE);
    ::OutputDebugString(wString);
#else
    // If we are not in windows, we use printf
    printf(buf);
#endif
}

// Template function to define names to types
template<typename T> const char *GetTypeName();

// Macro to define the concrete template functions
#define DEFINE_TYPE_NAME(type, name, ptrName) \
template<>const char *GetTypeName<type>() {return name;} \
template<>const char *GetTypeName<type*>() {return ptrName;}

// Type name definition
DEFINE_TYPE_NAME(double ,"double " ,"*double" )
DEFINE_TYPE_NAME(long   ,"long   " ,"*long  " )
DEFINE_TYPE_NAME(float  ,"float  " ,"*float " )
DEFINE_TYPE_NAME(short  ,"short  " ,"*short " )
DEFINE_TYPE_NAME(int    ,"int    " ,"*int   " )
DEFINE_TYPE_NAME(bool   ,"bool   " ,"*bool  " )
DEFINE_TYPE_NAME(char   ,"char   " ,"*char  " )

#endif
