#ifndef _BBCP_SET_H_
#define _BBCP_SET_H_
/******************************************************************************/
/*                                                                            */
/*                            b b c p _ S e t . h                             */
/*                                                                            */
/*(c) 2010-14 by the Board of Trustees of the Leland Stanford, Jr., University*//*      All Rights Reserved. See bbcp_Version.C for complete License Terms    *//*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/*                                                                            */
/* bbcp is free software: you can redistribute it and/or modify it under      */
/* the terms of the GNU Lesser General Public License as published by the     */
/* Free Software Foundation, either version 3 of the License, or (at your     */
/* option) any later version.                                                 */
/*                                                                            */
/* bbcp is distributed in the hope that it will be useful, but WITHOUT        */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public       */
/* License for more details.                                                  */
/*                                                                            */
/* You should have received a copy of the GNU Lesser General Public License   */
/* along with bbcp in a file called COPYING.LESSER (LGPL license) and file    */
/* COPYING (GPL license).  If not, see <http://www.gnu.org/licenses/>.        */
/*                                                                            */
/* The copyright holder's institutional names and contributor's names may not */
/* be used to endorse or promote products derived from this software without  */
/* specific prior written permission of the institution or contributor.       */
/******************************************************************************/

#include <stdlib.h>
#include <string.h>

class bbcp_Set {
public:

    bool Add(const char* key);

    bbcp_Set(int slots = 509);

    ~bbcp_Set();

private:

    struct SetItem {
        SetItem* next;
        char* key;

        SetItem(const char* kval, SetItem* base)
            : next(base), key(strdup(kval))
        {
        }

        ~SetItem()
        {
            free(key);
        }
    };

    SetItem** SetTab;
    unsigned int Slots;
};

#endif
