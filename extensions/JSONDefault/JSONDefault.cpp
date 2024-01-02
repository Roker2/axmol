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

#include "JSONDefault.h"
#include "platform/FileUtils.h"

#define JSON_DEFAULT_FILENAME "JSONDefault.json"

NS_AX_EXT_BEGIN

/**
 * implements of JSONDefault
 */

JSONDefault* JSONDefault::_jsonDefault = nullptr;

JSONDefault::~JSONDefault() {}

JSONDefault::JSONDefault()
    : JSONBasic(FileUtils::getInstance()->getWritablePath() + JSON_DEFAULT_FILENAME)
{
}

JSONDefault* JSONDefault::getInstance()
{
    if (_jsonDefault)
        return _jsonDefault;

    return (_jsonDefault = new JSONDefault());
}

void JSONDefault::destroyInstance()
{
    AX_SAFE_DELETE(_jsonDefault);
}

void JSONDefault::setDelegate(JSONDefault* delegate)
{
    if (_jsonDefault)
        delete _jsonDefault;

    _jsonDefault = delegate;
}

NS_AX_EXT_END
