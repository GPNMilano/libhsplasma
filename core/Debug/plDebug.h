#ifndef _PLDEBUG_H
#define _PLDEBUG_H

#include "Stream/hsStdioStream.h"

DllClass plDebug {
public:
    enum DebugLevel { kDLNone, kDLError, kDLWarning, kDLDebug, kDLAll };

private:
    static hsStream* fDebugStream;
    static int fDebugLevel;
    static bool fIOwnStream;
	static bool fIsExitRegistered;
    static plString fDebugFile;

public:
    static void Init(int level, hsStream* stream = NULL);
    static void InitFile(int level, const char* filename = "Plasma.log");

    static void Error(const char* fmt, ...);
    static void Warning(const char* fmt, ...);
    static void Debug(const char* fmt, ...);

private:
    static void WriteLn(const char* fmt, va_list args);
    static void DelayInit();
    static void DeInit();
};

#endif
