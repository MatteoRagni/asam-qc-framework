// SPDX-License-Identifier: MPL-2.0
/**
 * Copyright 2023 CARIAD SE.
 * Copyright 2024 ASAM e.V.
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License, v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef cInertialLocation_h__
#define cInertialLocation_h__

#include "../xml/util_xerces.h"
#include "c_extended_information.h"

/*
 * Definition of additional interial location information. This can be used to debug special positions
 * in dbqa framework
 */
class cInertialLocation : public cExtendedInformation
{

  public:
    static const XMLCh *TAG_NAME;
    static const XMLCh *ATTR_X;
    static const XMLCh *ATTR_Y;
    static const XMLCh *ATTR_Z;

    /*
     * Creates a new instance of cInertialLocation
     * \param x: X of the position in inertial coordinate system
     * \param y: Y of the position in inertial coordinate system
     * \param z: Z of the position in inertial coordinate system
     * \param description: Additional description
     */
    cInertialLocation(double x, double y, double z) : cExtendedInformation("InertialLocation"), m_X(x), m_Y(y), m_Z(z)
    {
    }

    // Serialize this information
    virtual XERCES_CPP_NAMESPACE::DOMElement *WriteXML(XERCES_CPP_NAMESPACE::DOMDocument *p_resultDocument);

    // Unserialize this information
    static cInertialLocation *ParseFromXML(XERCES_CPP_NAMESPACE::DOMNode *pXMLNode,
                                           XERCES_CPP_NAMESPACE::DOMElement *pXMLElement);

    // Returns the X
    double GetX() const;

    // Returns the Y
    double GetY() const;

    // Returns the Z
    double GetZ() const;

  protected:
    double m_X, m_Y, m_Z;

  private:
    cInertialLocation();
    cInertialLocation(const cInertialLocation &);
};

#endif
