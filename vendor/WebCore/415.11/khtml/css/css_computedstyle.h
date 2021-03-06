/**
 * css_computedstyle.h
 *
 * Copyright (C)  2004  Zack Rusin <zack@kde.org>
 * Copyright (C) 2004 Apple Computer, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307  USA
 */

#ifndef CSS_COMPUTEDSTYLE_H
#define CSS_COMPUTEDSTYLE_H

#include "css/css_valueimpl.h"

namespace khtml {
    class RenderObject;
    class RenderStyle;
}

namespace DOM {

class CSSProperty;

enum EUpdateLayout { DoNotUpdateLayout = false, UpdateLayout = true };

class CSSComputedStyleDeclarationImpl : public CSSStyleDeclarationImpl
{
public:
    CSSComputedStyleDeclarationImpl(NodeImpl *node);
    virtual ~CSSComputedStyleDeclarationImpl();

    virtual DOMString cssText() const;

    virtual unsigned long length() const;
    virtual DOMString item(unsigned long index) const;

    virtual CSSValueImpl *getPropertyCSSValue(int propertyID) const;
    virtual DOMString getPropertyValue(int propertyID) const;
    virtual bool getPropertyPriority(int propertyID) const;

    virtual CSSMutableStyleDeclarationImpl *copy() const;
    virtual CSSMutableStyleDeclarationImpl *makeMutable();

    CSSValueImpl *getPropertyCSSValue(int propertyID, EUpdateLayout updateLayout) const;

    CSSMutableStyleDeclarationImpl *copyInheritableProperties() const;

private:
    virtual void setCssText(const DOMString &, int &exceptionCode);
    virtual DOMString removeProperty(int propertyID, int &exceptionCode);
    virtual void setProperty(int propertyId, const DOMString &value, bool important, int &exceptionCode);

    Node m_node;
};

}

#endif
