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

#ifndef _PLSCALECONTROLLER_H
#define _PLSCALECONTROLLER_H

#include "plKeyControllers.hpp"

class PLASMA_DLL plScaleController : public plController {
    CREATABLE(plScaleController, kScaleController, plController)

public:
    enum { kSimple = 1 };

public:
    virtual int getType() const = 0;
};


class PLASMA_DLL plSimpleScaleController : public plScaleController {
    CREATABLE(plSimpleScaleController, kSimpleScaleController, plScaleController)

protected:
    plScaleValueController* fValue;

public:
    plSimpleScaleController() : fValue(NULL) { }
    virtual ~plSimpleScaleController();

    virtual int getType() const { return kSimple; }
    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    plScaleValueController* getValue() const { return fValue; }
    void setValue(plScaleValueController* value);
};

#endif
