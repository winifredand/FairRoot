/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
/**
 * FairMQEx9Merger3Ch.h
 *
 * @since 2016-03-21
 * @author R. Karabowicz
 */

#ifndef FAIRMQEX9MERGER_H_
#define FAIRMQEX9MERGER_H_

#include "TClonesArray.h"
#include "TFile.h"
#include "TFolder.h"
#include "TTree.h"
#include "FairEventHeader.h"

#include "FairMQDevice.h"

#include "PixelEventHeader.h"

typedef std::multimap<std::pair<std::pair<int,int>,int>,TObject*> MultiMapDef;

class FairMQEx9Merger3Ch : public FairMQDevice
{
  public:
    FairMQEx9Merger3Ch();
    virtual ~FairMQEx9Merger3Ch();

    void SetNofParts(int iparts) { fNofParts = iparts; }

  protected:
    bool MergeData(FairMQParts&, int);
    virtual void Init();

 private:

    std::string fInputChannel1Name;
    std::string fInputChannel2Name;
    std::string fInputChannel3Name;
    std::string fOutputChannelName;

    std::map     <std::pair<int,int>,int>                     fNofPartsPerEventMap;  // number of parts for pair<event number,run id>
    MultiMapDef fObjectMap;            // TObjects for given pair<pair<event number, run,id>part>

    std::pair<int, int> fEvRIPair;
    std::pair<std::pair<int,int>,int> fEvRIPartTrio;
    std::pair<MultiMapDef::iterator, MultiMapDef::iterator> fRet;

    int fNofReceivedMessages;
    int fNofSentMessages;
    
    int fNofParts;
    PixelEventHeader* fEventHeader;

    FairMQEx9Merger3Ch(const FairMQEx9Merger3Ch&);
    FairMQEx9Merger3Ch& operator=(const FairMQEx9Merger3Ch&);
};

#endif /* FAIRMQEX9MERGER_H_ */