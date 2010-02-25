#ifndef _PLNETMSGGAMEMESSAGE_H
#define _PLNETMSGGAMEMESSAGE_H

#include "plNetMsgStream.h"
#include "Sys/plUnifiedTime.h"
#include "PRP/Message/plMessage.h"

DllClass plNetMsgGameMessage : public plNetMsgStream {
private:
    plUnifiedTime fDeliveryTime;
    plMessage* fMessage;

public:
    plNetMsgGameMessage();
    ~plNetMsgGameMessage();

    DECLARE_CREATABLE(plNetMsgGameMessage)

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

DllClass plNetMsgGameMessageDirected : public plNetMsgGameMessage {
private:
    hsTArray<unsigned int> fReceivers;

public:
    plNetMsgGameMessageDirected();
    ~plNetMsgGameMessageDirected();

    DECLARE_CREATABLE(plNetMsgGameMessageDirected)

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

#endif