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

#ifndef _PLENABLEMSG_H
#define _PLENABLEMSG_H

#include "plMessage.h"
#include "Util/hsBitVector.h"

class PLASMA_DLL plEnableMsg : public plMessage {
    CREATABLE(plEnableMsg, kEnableMsg, plMessage)

public:
    enum { kDisable, kEnable, kDrawable, kPhysical, kAudible, kAll, kByType };

protected:
    hsBitVector fCmd, fTypes;

public:
    plEnableMsg();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    const hsBitVector& getCmd() const { return fCmd; }
    hsBitVector& getCmd() { return fCmd; }

    const hsBitVector& getTypes() const { return fTypes; }
    hsBitVector& getTypes() { return fTypes; }
};

#endif
