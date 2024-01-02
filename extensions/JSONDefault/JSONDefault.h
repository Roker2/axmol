/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
Copyright (c) 2019-present Axmol Engine contributors (see AUTHORS.md).

https://axmolengine.github.io/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __SUPPORT_JSONDEFAULT_H__
#define __SUPPORT_JSONDEFAULT_H__

#include "extensions/JSONDefault/JSONBasic.h"

/**
 * @addtogroup extensions
 * @{
 */
NS_AX_EXT_BEGIN

/**
 * JSONDefault acts as a tiny database, which is placed in default path
 * and available everywhere. You can save and get base type values by
 * it. For example, setBoolForKey("played", true) will add a bool value true
 * into the database. Its key is "played". You can get the value of the key by
 * getBoolForKey("played").
 *
 * It supports the following base types:
 * bool, int, float, double, string
 *
 */
class JSONDefault : public JSONBasic
{
public:
    /** Returns the singleton.
     * @js NA
     * @lua NA
     */
    static JSONDefault* getInstance();
    /**
     * @js NA
     */
    static void destroyInstance();

    /**
     * You can inherit from platform dependent implementation of JSONDefault, such
     * as JSONDefaultAndroid, and use this function to set delegate, then
     * JSONDefault will invoke delegate's implementation. For example, your store
     * native data base or other format store.
     *
     * If you don't want to system default implementation after setting delegate,
     * you can just pass nullptr to this function.
     *
     * @warning It will delete previous delegate
     */
    static void setDelegate(JSONDefault* delegate);

protected:
    JSONDefault();
    virtual ~JSONDefault();

protected:
    static JSONDefault* _jsonDefault;
};

NS_AX_EXT_END
// end of extensions group
/** @} */

#endif  // __SUPPORT_JSONDEFAULT_H__
