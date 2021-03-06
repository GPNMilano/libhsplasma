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

#ifndef _PLBLOWER_H
#define _PLBLOWER_H

#include "PRP/Modifier/plModifier.h"

class PLASMA_DLL plBlower : public virtual plSingleModifier {
    CREATABLE(plBlower, kBlower, plSingleModifier)

protected:
    float fMasterPower, fDirectRate, fImpulseRate, fSpringKonst;

public:
    plBlower() : fMasterPower(0.0f), fDirectRate(0.0f), fImpulseRate(0.0f),
                 fSpringKonst(0.0f) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    float getMasterPower() const { return fMasterPower; }
    float getDirectRate() const { return fDirectRate; }
    float getImpulseRate() const { return fImpulseRate; }
    float getSpringKonst() const { return fSpringKonst; }

    void setMasterPower(float power) { fMasterPower = power; }
    void setDirectRate(float rate) { fDirectRate = rate; }
    void setImpulseRate(float rate) { fImpulseRate = rate; }
    void setSpringKonst(float konst) { fSpringKonst = konst; }
};

#endif
