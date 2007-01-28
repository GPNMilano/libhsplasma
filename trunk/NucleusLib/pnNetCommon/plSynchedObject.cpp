#include "plSynchedObject.h"

plSynchedObject::plSynchedObject(PlasmaVer pv) { }
plSynchedObject::~plSynchedObject() { }

short plSynchedObject::ClassIndex() { return 0x0028; }

void plSynchedObject::read(hsStream * S) {
    hsKeyedObject::read(S);
    SDLExcludeList.clear();
    SDLVolatileList.clear();
    flags = S->readInt();

    unsigned short count, len, i;
    if (flags & kExcludePersistentState) {
        count = S->readShort();
        for (i=0; i<count; i++) {
            len = S->readShort();
            SDLExcludeList.push_back(S->readStr(len));
        }
    }
    if (flags & kHasVolatileState) {
        count = S->readShort();
        for (i=0; i<count; i++) {
            len = S->readShort();
            SDLVolatileList.push_back(S->readStr(len));
        }
    }
}

void plSynchedObject::write(hsStream * S) {
    hsKeyedObject::write(S);
    S->writeInt(flags);

    unsigned short len, i;
    if (flags & kExcludePersistentState) {
        S->writeShort(SDLExcludeList.size());
        for (i=0; i<SDLExcludeList.size(); i++) {
            len = strlen(SDLExcludeList[i]);
            S->writeShort(len);
            S->writeStr(SDLExcludeList[i], len);
        }
    }
    if (flags & kHasVolatileState) {
        S->writeShort(SDLVolatileList.size());
        for (i=0; i<SDLVolatileList.size(); i++) {
            len = strlen(SDLVolatileList[i]);
            S->writeShort(len);
            S->writeStr(SDLVolatileList[i], len);
        }
    }
}
