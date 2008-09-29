#ifndef _PLDYNAMICENVMAP_H
#define _PLDYNAMICENVMAP_H

#include "plRenderTarget.h"

DllClass plDynamicEnvMap : public plCubicRenderTarget {
protected:
    plKey fRootNode;
    hsVector3 fPos;
    float fHither, fYon, fFogStart;
    hsColorRGBA fColor;
    float fRefreshRate;
    double fLastRefresh;
    int fLastRender, fOutStanding;
    hsBitVector fVisSet;
    hsTArray<plKey> fVisRegions;
    hsTArray<plString> fVisRegionNames;
    int fIncCharacters;

public:
    plDynamicEnvMap();
    virtual ~plDynamicEnvMap();

    DECLARE_CREATABLE(plDynamicEnvMap)

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

DllClass plDynamicCamMap : public plRenderTarget {
public:
    enum {
        kReflectionCapable = 0x1,
        kReflectionEnabled = 0x2,
        kReflectionMask = kReflectionCapable | kReflectionEnabled
    };

protected:
    float fHither, fYon, fFogStart;
    hsColorRGBA fColor;
    float fRefreshRate;
    double fLastRefresh;
    int fOutStanding;
    hsBitVector fVisSet;
    hsTArray<plKey> fVisRegions, fTargetNodes, fMatLayers;
    hsTArray<plString> fVisRegionNames;
    unsigned char fIncCharacters;
    plKey fCamera, fRootNode, fDisableTexture;

public:
    plDynamicCamMap();
    virtual ~plDynamicCamMap();

    DECLARE_CREATABLE(plDynamicCamMap)

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

#endif
