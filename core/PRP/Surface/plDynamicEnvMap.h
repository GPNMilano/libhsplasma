/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PLDYNAMICENVMAP_H
#define _PLDYNAMICENVMAP_H

#include "plRenderTarget.h"

class PLASMA_DLL plDynamicEnvMap : public virtual plCubicRenderTarget {
    CREATABLE(plDynamicEnvMap, kDynamicEnvMap, plCubicRenderTarget)

protected:
    plKey fRootNode;
    hsVector3 fPos;
    float fHither, fYon, fFogStart;
    hsColorRGBA fColor;
    float fRefreshRate;
    std::vector<plKey> fVisRegions;
    std::vector<plString> fVisRegionNames;
    int fIncCharacters;

public:
    plDynamicEnvMap()
        : fHither(0.0f), fYon(0.0f), fFogStart(0.0f), fRefreshRate(0.0f),
          fIncCharacters(false) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};


class PLASMA_DLL plDynamicCamMap : public virtual plRenderTarget {
    CREATABLE(plDynamicCamMap, kDynamicCamMap, plRenderTarget)

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
    std::vector<plKey> fVisRegions, fTargetNodes, fMatLayers;
    std::vector<plString> fVisRegionNames;
    unsigned char fIncCharacters;
    plKey fCamera, fRootNode, fDisableTexture;

public:
    plDynamicCamMap()
        : fHither(0.0f), fYon(0.0f), fFogStart(0.0f), fRefreshRate(0.0f),
          fIncCharacters(false) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

#endif
