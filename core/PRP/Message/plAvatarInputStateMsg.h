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

#ifndef _PLAVATARINPUTSTATEMSG_H
#define _PLAVATARINPUTSTATEMSG_H

#include "plMessage.h"

class PLASMA_DLL plAvatarInputStateMsg : public plMessage {
    CREATABLE(plAvatarInputStateMsg, kAvatarInputStateMsg, plMessage)

protected:
    uint16_t fState;

public:
    plAvatarInputStateMsg() : fState(0) { }

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    uint16_t getState() const { return fState; }
    void setState(uint16_t state) { fState = state; }
};

#endif
